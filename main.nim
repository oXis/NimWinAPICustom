import winim/lean
import tools
import winapi

type MessageBox = (proc (hWnd: HWND, lpText: LPCSTR, lpCaption: LPCSTR, uType: UINT): int32 {.stdcall.})

when isMainModule:
    
    var pLoadLibraryA: LoadLibraryA = cast[LoadLibraryA](GetExportAddress(GetModuleBaseAddress(CalcHashSalt("KERNEL32.DLL")), CalcHashSalt("LoadLibraryA")))

    discard pLoadLibraryA("user32.dll")

    var moduleBase: HMODULE = GetModuleBaseAddress(CalcHashSalt("USER32.DLL"))

    if moduleBase == 0:
        echo "not found"
        quit()

    var pMessageBox: MessageBox

    pMessageBox = cast[MessageBox](GetExportAddress(moduleBase, CalcHashSalt("MessageBoxA")))
    discard pMessageBox(0, "By Name", "Box", 0)

    pMessageBox = cast[MessageBox](GetExportAddress(moduleBase, 0x7FB))
    discard pMessageBox(0, "By Ordinal", "Box", 0)

    discard GetExportAddress(GetModuleBaseAddress(CalcHashSalt("KERNEL32.DLL")), CalcHashSalt("EnterCriticalSection")) # Forwarded function
