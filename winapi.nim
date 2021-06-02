import strutils
import winim/lean
import PEB
import tools
import pointers

type LoadLibraryA* = (proc (lpFileName: LPCSTR): HMODULE {.stdcall.})

proc IsOrdinal*(pvTest: UINT_PTR): BOOL {.inline.} =
    var MASK: UINT_PTR = not UINT_PTR(0xFFFF)
    return if (pvTest and MASK) == 0: TRUE else: FALSE

proc GetDOSHeaders*(imageBase: HMODULE): PIMAGE_DOS_HEADER {.inline.} =
    return cast[PIMAGE_DOS_HEADER](imageBase)

proc GetNTHeaders*(imageBase: HMODULE): PIMAGE_NT_HEADERS {.inline.} =
    var dos_header: PIMAGE_DOS_HEADER = cast[PIMAGE_DOS_HEADER](imageBase)
    return cast[PIMAGE_NT_HEADERS](cast[ByteAddress](imageBase) + dos_header.e_lfanew)

proc GetOptionalHeader*(imageBase: HMODULE): PIMAGE_OPTIONAL_HEADER {.inline.} =
    return cast[PIMAGE_OPTIONAL_HEADER]((cast[ByteAddress](imageBase) + (cast[PIMAGE_DOS_HEADER](imageBase)).e_lfanew + sizeof(DWORD) + sizeof(IMAGE_FILE_HEADER)))

proc GetModuleBaseAddress*(moduleNameHash: int): HMODULE =
    var pPeb: PEB.PPEB = nil # Get PEB struct from PEB.nim instead of from winnim
    var head: PLIST_ENTRY = nil
    var entry: PLIST_ENTRY = nil

    pPeb = GetPEB()

    if pPeb == nil:
        return 0

    head = cast[PLIST_ENTRY](addr pPeb.Ldr.InLoadOrderModuleList)
    entry = cast[PLIST_ENTRY](head.Flink);

    while head != entry:

        var ldrData = cast[PEB.PLDR_DATA_TABLE_ENTRY](entry)

        var name = cast[ptr array[32, uint16]](ldrData.BaseDllName.Buffer)
        var charName: string

        var i = 0
        while name[i] != 0x0:
            charName.add cast[char](name[i])
            inc(i)

        var hash = CalcHashSalt(charName.toUpperAscii())

        if moduleNameHash == hash:
            return cast[HMODULE](ldrData.DllBase)

        entry = entry.Flink

    return 0

proc GetExportAddress*(hMod: HMODULE; lpProcNameHash: int): FARPROC =
    var pBaseAddress: ByteAddress = cast[ByteAddress](hMod)

    var pOptionalHeader: PIMAGE_OPTIONAL_HEADER = GetOptionalHeader(hMod)
    
    var pDataDirectory: PIMAGE_DATA_DIRECTORY = cast[PIMAGE_DATA_DIRECTORY](addr pOptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT])
    var pExportDirectory: PIMAGE_EXPORT_DIRECTORY = cast[PIMAGE_EXPORT_DIRECTORY](pBaseAddress + pDataDirectory.VirtualAddress)
    
    var pOrdinals: PWORD = cast[PWORD](pBaseAddress + pExportDirectory.AddressOfNameOrdinals)
    var pNames: PDWORD = cast[PDWORD](pBaseAddress + pExportDirectory.AddressOfNames)
    
    var pAddress: pointer = nil
    var pLoadLibraryA: LoadLibraryA = nil
    
    ## typeGetProcAddressA pGetProcAddress = NULL;
    var i: DWORD

    if IsOrdinal(lpProcNameHash) == 0:
        i = 0
        while i < pExportDirectory.NumberOfNames:
            var szName: cstring = nil
            ptrMath:
                szName = cast[cstring](pBaseAddress + cast[SIZE_T](pNames[i]))
                if lpProcNameHash == CalcHashSalt($szName):
                    pAddress = cast[FARPROC](pBaseAddress + cast[ptr ULONG](pBaseAddress + pExportDirectory.AddressOfFunctions)[cast[int](pOrdinals[i])])
                    break

            inc(i)
    else:
        ##  by ordinal
        var dwOrdinalBase: DWORD = pExportDirectory.Base
        var ordinal: DWORD = cast[DWORD](LOWORD(lpProcNameHash))

        if ordinal < dwOrdinalBase or ordinal >= dwOrdinalBase + pExportDirectory.NumberOfFunctions:
            return nil
        ptrMath:
            pAddress = cast[FARPROC](pBaseAddress + cast[ptr ULONG](pBaseAddress + pExportDirectory.AddressOfFunctions)[ordinal - dwOrdinalBase])
 
    ## Forward?
    if cast[ByteAddress](pAddress) >= cast[ByteAddress](pExportDirectory) and
        cast[ByteAddress](pAddress) <
        cast[ByteAddress](pExportDirectory) + pDataDirectory.Size:

        var hForward: HMODULE

        ##  pAddress is equal to DLL.FUNC or DLL.#ORDINAL
        var c = $(cast[cstring](pAddress))

        if c == "":
            return nil

        pAddress = nil
        
        var tmp = c.split('.')
        var dllName = tmp[0] & ".dll"
        var funcName = tmp[1]

        var num: int
        if funcName[0] == '#':
            num = parseInt(funcName[1..^1])
        else:
            num = CalcHashSalt(funcName)
        
        pLoadLibraryA = cast[LoadLibraryA](GetExportAddress(GetModuleBaseAddress(CalcHashSalt("KERNEL32.DLL")), CalcHashSalt("LoadLibraryA")))

        if pLoadLibraryA == nil:
            return nil

        hForward = pLoadLibraryA(dllName)

        if hForward == 0:
            return nil

        pAddress = GetExportAddress(hForward, num)

    return cast[FARPROC](pAddress)
