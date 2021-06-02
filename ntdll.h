
/****************************************************************************
*                                                                           *
* minwindef.h -- Basic Windows Type Definitions for minwin partition        *
*                                                                           *
* Copyright (c) Microsoft Corporation. All rights reserved.                 *
*                                                                           *
****************************************************************************/


#ifndef _MINWINDEF_
#define _MINWINDEF_
#pragma once

#ifndef NO_STRICT
#ifndef STRICT
#define STRICT 1
#endif
#endif /* NO_STRICT */

// Win32 defines _WIN32 automatically,
// but Macintosh doesn't, so if we are using
// Win32 Functions, we must do it here

#ifdef _MAC
#ifndef _WIN32
#define _WIN32
#endif
#endif //_MAC

#ifndef WIN32
#define WIN32
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * BASETYPES is defined in ntdef.h if these types are already defined
 */

#ifndef BASETYPES
#define BASETYPES
typedef unsigned long ULONG;
typedef ULONG *PULONG;
typedef unsigned short USHORT;
typedef USHORT *PUSHORT;
typedef unsigned char UCHAR;
typedef UCHAR *PUCHAR;
typedef unsigned int UINT;
typedef UINT* UINT_PTR;
typedef long* LONG_PTR;
typedef void *HANDLE;
#endif  /* !BASETYPES */

#define MAX_PATH          260

#ifndef NULL
#ifdef __cplusplus
#define NULL    0
#else
#define NULL    ((void *)0)
#endif
#endif

#ifndef FALSE
#define FALSE               0
#endif

#ifndef TRUE
#define TRUE                1
#endif

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef OPTIONAL
#define OPTIONAL
#endif

#undef far
#undef near
#undef pascal

#define far
#define near

#if (!defined(_MAC)) && ((_MSC_VER >= 800) || defined(_STDCALL_SUPPORTED))
#define pascal __stdcall
#else
#define pascal
#endif

#if defined(DOSWIN32) || defined(_MAC)
#define cdecl _cdecl
#ifndef CDECL
#define CDECL _cdecl
#endif
#else
#define cdecl
#ifndef CDECL
#define CDECL
#endif
#endif

#ifdef _MAC
#define CALLBACK    PASCAL
#define WINAPI      CDECL
#define WINAPIV     CDECL
#define APIENTRY    WINAPI
#define APIPRIVATE  CDECL
#ifdef _68K_
#define PASCAL      __pascal
#else
#define PASCAL
#endif
#elif (_MSC_VER >= 800) || defined(_STDCALL_SUPPORTED)
#define CALLBACK    __stdcall
#define WINAPI      __stdcall
#define WINAPIV     __cdecl
#define APIENTRY    WINAPI
#define APIPRIVATE  __stdcall
#define PASCAL      __stdcall
#else
#define CALLBACK
#define WINAPI
#define WINAPIV
#define APIENTRY    WINAPI
#define APIPRIVATE
#define PASCAL      pascal
#endif

#ifndef _M_CEE_PURE
#ifndef WINAPI_INLINE
#define WINAPI_INLINE  WINAPI
#endif
#endif

#undef FAR
#undef  NEAR
#define FAR                 far
#define NEAR                near
#ifndef CONST
#define CONST               const
#endif

typedef unsigned long       DWORD;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef float               FLOAT;
typedef FLOAT               *PFLOAT;
typedef BOOL near           *PBOOL;
typedef BOOL far            *LPBOOL;
typedef BYTE near           *PBYTE;
typedef BYTE far            *LPBYTE;
typedef int near            *PINT;
typedef int far             *LPINT;
typedef WORD near           *PWORD;
typedef WORD far            *LPWORD;
typedef long far            *LPLONG;
typedef DWORD near          *PDWORD;
typedef DWORD far           *LPDWORD;
typedef void far            *LPVOID;
typedef CONST void far      *LPCVOID;

typedef int                 INT;
typedef unsigned int        UINT;
typedef unsigned int        *PUINT;


#ifndef NT_INCLUDED
#endif /* NT_INCLUDED */

/* Types use for passing & returning polymorphic values */
typedef UINT_PTR            WPARAM;
typedef LONG_PTR            LPARAM;
typedef LONG_PTR            LRESULT;

#ifndef NOMINMAX

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

#endif  /* NOMINMAX */

#define MAKEWORD(a, b)      ((WORD)(((BYTE)(((DWORD_PTR)(a)) & 0xff)) | ((WORD)((BYTE)(((DWORD_PTR)(b)) & 0xff))) << 8))
#define MAKELONG(a, b)      ((LONG)(((WORD)(((DWORD_PTR)(a)) & 0xffff)) | ((DWORD)((WORD)(((DWORD_PTR)(b)) & 0xffff))) << 16))
#define LOWORD(l)           ((WORD)(((DWORD_PTR)(l)) & 0xffff))
#define HIWORD(l)           ((WORD)((((DWORD_PTR)(l)) >> 16) & 0xffff))
#define LOBYTE(w)           ((BYTE)(((DWORD_PTR)(w)) & 0xff))
#define HIBYTE(w)           ((BYTE)((((DWORD_PTR)(w)) >> 8) & 0xff))

typedef HANDLE NEAR         *SPHANDLE;
typedef HANDLE FAR          *LPHANDLE;
typedef HANDLE              HGLOBAL;
typedef HANDLE              HLOCAL;
typedef HANDLE              GLOBALHANDLE;
typedef HANDLE              LOCALHANDLE;

#ifndef _MANAGED
#if _MSC_VER >= 1200
#pragma warning(push)
#pragma warning(disable:4255) // () treated as (void)
#endif
#ifndef _MAC
#ifdef _WIN64

#else
typedef int (FAR WINAPI *FARPROC)();
typedef int (NEAR WINAPI *NEARPROC)();
typedef int (WINAPI *PROC)();
#endif  // _WIN64
#else
typedef int (CALLBACK *FARPROC)();
typedef int (CALLBACK *NEARPROC)();
typedef int (CALLBACK *PROC)();
#endif
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif
#else
typedef INT_PTR (WINAPI *FARPROC)(void);
typedef INT_PTR (WINAPI *NEARPROC)(void);
typedef INT_PTR (WINAPI *PROC)(void);
#endif

typedef WORD                ATOM;   //BUGBUG - might want to remove this from minwin

DECLARE_HANDLE(HKEY);
typedef HKEY *PHKEY;
DECLARE_HANDLE(HMETAFILE);
DECLARE_HANDLE(HINSTANCE);
typedef HINSTANCE HMODULE;      /* HMODULEs can be used in place of HINSTANCEs */
DECLARE_HANDLE(HRGN);
DECLARE_HANDLE(HRSRC);
DECLARE_HANDLE(HSPRITE);
DECLARE_HANDLE(HLSURF);
DECLARE_HANDLE(HSTR);
DECLARE_HANDLE(HTASK);
DECLARE_HANDLE(HWINSTA);
DECLARE_HANDLE(HKL);

#ifndef _MAC
typedef int HFILE;
#else
typedef short HFILE;
#endif

//
//  File System time stamps are represented with the following structure:
//

typedef struct _FILETIME {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
} FILETIME, *PFILETIME, *LPFILETIME;
#define _FILETIME_

#ifdef __cplusplus
}
#endif

#endif // _MINWINDEF_

#ifndef _NTDLL_
#define _NTDLL_

#define NT_INCLUDED
#define _NTDEF_
#define _CTYPE_DISABLE_MACROS

#pragma warning(disable : 4200)

#define STATUS_SUCCESS                   ((NTSTATUS)0x00000000L)

#if (_MSC_VER >= 800) || defined(_STDCALL_SUPPORTED)
#define NTAPI __stdcall
#else
#define _cdecl
#define NTAPI
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define MAXIMUM_FILENAME_LENGTH			256
#define PORT_MAXIMUM_MESSAGE_LENGTH		256
#define INITIAL_PRIVILEGE_COUNT			3

#define FSCTL_GET_VOLUME_INFORMATION	0x90064

// constants for RtlDetermineDosPathNameType_U
#define DOS_PATHTYPE_UNC				0x00000001	// \\COMPUTER1
#define DOS_PATHTYPE_ROOTDRIVE			0x00000002	// C:\ 
#define DOS_PATHTYPE_STREAM				0x00000003	// X:X or C:
#define DOS_PATHTYPE_NT					0x00000004	// \\??\\C:
#define DOS_PATHTYPE_NAME				0x00000005	// C
#define DOS_PATHTYPE_DEVICE				0x00000006	// \\.\C:
#define DOS_PATHTYPE_LOCALUNCROOT		0x00000007	// \\.

// Define the various device characteristics flags
#define FILE_REMOVABLE_MEDIA            0x00000001
#define FILE_READ_ONLY_DEVICE           0x00000002
#define FILE_FLOPPY_DISKETTE            0x00000004
#define FILE_WRITE_ONCE_MEDIA           0x00000008
#define FILE_REMOTE_DEVICE              0x00000010
#define FILE_DEVICE_IS_MOUNTED          0x00000020
#define FILE_VIRTUAL_VOLUME             0x00000040
#define FILE_AUTOGENERATED_DEVICE_NAME  0x00000080
#define FILE_DEVICE_SECURE_OPEN			0x00000100

#define FILE_SUPERSEDE							0x00000000
#define FILE_OPEN								0x00000001
#define FILE_CREATE								0x00000002
#define FILE_OPEN_IF							0x00000003
#define FILE_OVERWRITE							0x00000004
#define FILE_OVERWRITE_IF						0x00000005
#define FILE_MAXIMUM_DISPOSITION				0x00000005

#define FILE_DIRECTORY_FILE                     0x00000001
#define FILE_WRITE_THROUGH                      0x00000002
#define FILE_SEQUENTIAL_ONLY                    0x00000004
#define FILE_NO_INTERMEDIATE_BUFFERING          0x00000008

#define FILE_SYNCHRONOUS_IO_ALERT               0x00000010
#define FILE_SYNCHRONOUS_IO_NONALERT            0x00000020
#define FILE_NON_DIRECTORY_FILE                 0x00000040
#define FILE_CREATE_TREE_CONNECTION             0x00000080

#define FILE_COMPLETE_IF_OPLOCKED               0x00000100
#define FILE_NO_EA_KNOWLEDGE                    0x00000200
#define FILE_OPEN_FOR_RECOVERY                  0x00000400
#define FILE_RANDOM_ACCESS                      0x00000800

#define FILE_DELETE_ON_CLOSE                    0x00001000
#define FILE_OPEN_BY_FILE_ID                    0x00002000
#define FILE_OPEN_FOR_BACKUP_INTENT             0x00004000
#define FILE_NO_COMPRESSION                     0x00008000

#define FILE_RESERVE_OPFILTER                   0x00100000
#define FILE_OPEN_REPARSE_POINT                 0x00200000
#define FILE_OPEN_NO_RECALL                     0x00400000
#define FILE_OPEN_FOR_FREE_SPACE_QUERY          0x00800000

#define FILE_COPY_STRUCTURED_STORAGE            0x00000041
#define FILE_STRUCTURED_STORAGE                 0x00000441

#define FILE_VALID_OPTION_FLAGS                 0x00ffffff
#define FILE_VALID_PIPE_OPTION_FLAGS            0x00000032
#define FILE_VALID_MAILSLOT_OPTION_FLAGS        0x00000032
#define FILE_VALID_SET_FLAGS                    0x00000036

// THREAD STATES
#define THREAD_STATE_INITIALIZED		0
#define THREAD_STATE_READY				1
#define THREAD_STATE_RUNNING			2
#define THREAD_STATE_STANDBY			3
#define THREAD_STATE_TERMINATED			4
#define THREAD_STATE_WAIT				5
#define THREAD_STATE_TRANSITION			6
#define THREAD_STATE_UNKNOWN			7

// OBJECT TYPE CODES
#define OB_TYPE_TYPE					1
#define OB_TYPE_DIRECTORY				2
#define OB_TYPE_SYMBOLIC_LINK			3
#define OB_TYPE_TOKEN					4
#define OB_TYPE_PROCESS					5
#define OB_TYPE_THREAD					6
#define OB_TYPE_EVENT					7
#define OB_TYPE_EVENT_PAIR				8
#define OB_TYPE_MUTANT					9
#define OB_TYPE_SEMAPHORE				10
#define OB_TYPE_TIMER					11
#define OB_TYPE_PROFILE					12
#define OB_TYPE_WINDOW_STATION			13
#define OB_TYPE_DESKTOP					14
#define OB_TYPE_SECTION					15
#define OB_TYPE_KEY						16
#define OB_TYPE_PORT					17
#define OB_TYPE_ADAPTER					18
#define OB_TYPE_CONTROLLER				19
#define OB_TYPE_DEVICE					20
#define OB_TYPE_DRIVER					21
#define OB_TYPE_IO_COMPLETION			22
#define OB_TYPE_FILE					23

#define OBJ_INHERIT						0x00000002
#define OBJ_PERMANENT					0x00000010
#define OBJ_EXCLUSIVE					0x00000020
#define OBJ_CASE_INSENSITIVE			0x00000040
#define OBJ_OPENIF						0x00000080
#define OBJ_OPENLINK					0x00000100
#define OBJ_VALID_ATTRIBUTES			0x000001F2


// Object Manager Directory Specific Access Rights.
#define DIRECTORY_QUERY					0x0001
#define DIRECTORY_TRAVERSE				0x0002
#define DIRECTORY_CREATE_OBJECT			0x0004
#define DIRECTORY_CREATE_SUBDIRECTORY	0x0008
#define DIRECTORY_ALL_ACCESS			(STANDARD_RIGHTS_REQUIRED | 0xF)

// Object Manager Symbolic Link Specific Access Rights.
#define SYMBOLIC_LINK_QUERY				0x0001
#define SYMBOLIC_LINK_ALL_ACCESS		(STANDARD_RIGHTS_REQUIRED | 0x1)

#define NT_SUCCESS(Status)				((LONG)(Status) >= 0)
#define NT_ERROR(Status)				((ULONG)(Status) >> 30 == 3)

#define DEVICE_TYPE						DWORD

// values for RtlAdjustPrivilege
#define SE_MIN_WELL_KNOWN_PRIVILEGE       (2L)
#define SE_CREATE_TOKEN_PRIVILEGE         (2L)
#define SE_ASSIGNPRIMARYTOKEN_PRIVILEGE   (3L)
#define SE_LOCK_MEMORY_PRIVILEGE          (4L)
#define SE_INCREASE_QUOTA_PRIVILEGE       (5L)
#define SE_UNSOLICITED_INPUT_PRIVILEGE    (6L) // obsolete and unused
#define SE_MACHINE_ACCOUNT_PRIVILEGE      (6L)
#define SE_TCB_PRIVILEGE                  (7L)
#define SE_SECURITY_PRIVILEGE             (8L)
#define SE_TAKE_OWNERSHIP_PRIVILEGE       (9L)
#define SE_LOAD_DRIVER_PRIVILEGE          (10L)
#define SE_SYSTEM_PROFILE_PRIVILEGE       (11L)
#define SE_SYSTEMTIME_PRIVILEGE           (12L)
#define SE_PROF_SINGLE_PROCESS_PRIVILEGE  (13L)
#define SE_INC_BASE_PRIORITY_PRIVILEGE    (14L)
#define SE_CREATE_PAGEFILE_PRIVILEGE      (15L)
#define SE_CREATE_PERMANENT_PRIVILEGE     (16L)
#define SE_BACKUP_PRIVILEGE               (17L)
#define SE_RESTORE_PRIVILEGE              (18L)
#define SE_SHUTDOWN_PRIVILEGE             (19L)
#define SE_DEBUG_PRIVILEGE                (20L)
#define SE_AUDIT_PRIVILEGE                (21L)
#define SE_SYSTEM_ENVIRONMENT_PRIVILEGE   (22L)
#define SE_CHANGE_NOTIFY_PRIVILEGE        (23L)
#define SE_REMOTE_SHUTDOWN_PRIVILEGE      (24L)
#define SE_MAX_WELL_KNOWN_PRIVILEGE       (SE_REMOTE_SHUTDOWN_PRIVILEGE)

typedef LONG		NTSTATUS;
/*lint -e624 */  // Don't complain about different typedefs.
				 // winnt
typedef NTSTATUS	*PNTSTATUS;
/*lint +e624 */  // Resume checking for different typedefs.

typedef NTSTATUS	(NTAPI *NTSYSCALL)();
typedef NTSYSCALL	*PNTSYSCALL;


typedef ULONG_PTR	KAFFINITY;
typedef KAFFINITY	*PKAFFINITY;
typedef LONG		KPRIORITY;

typedef BYTE		KPROCESSOR_MODE;

typedef VOID		*POBJECT;

typedef VOID		(*PKNORMAL_ROUTINE) (
						IN PVOID NormalContext,
						IN PVOID SystemArgument1,
						IN PVOID SystemArgument2
					);

typedef struct _STRING {
    USHORT Length;
    USHORT MaximumLength;
#ifdef MIDL_PASS
    [size_is(MaximumLength), length_is(Length) ]
#endif // MIDL_PASS
    PCHAR Buffer;
} STRING, *PSTRING;


typedef STRING ANSI_STRING;
typedef PSTRING PANSI_STRING;

typedef STRING OEM_STRING;
typedef PSTRING POEM_STRING;


typedef struct _UNICODE_STRING 
{
	USHORT  Length;
	USHORT  MaximumLength;
	PWSTR  Buffer;
} UNICODE_STRING, *PUNICODE_STRING;

typedef struct _HARDWARE_PTE
{
    ULONG Valid             : 1;
    ULONG Write             : 1;
    ULONG Owner             : 1;
    ULONG WriteThrough      : 1;
    ULONG CacheDisable      : 1;
    ULONG Accessed          : 1;
    ULONG Dirty             : 1;
    ULONG LargePage         : 1;
    ULONG Global            : 1;
    ULONG CopyOnWrite       : 1;
    ULONG Prototype         : 1;
    ULONG reserved          : 1;
    ULONG PageFrameNumber   : 20;
} HARDWARE_PTE, *PHARDWARE_PTE;

typedef struct _OBJECT_ATTRIBUTES
{
	ULONG			uLength;
	HANDLE			hRootDirectory;
	PUNICODE_STRING	pObjectName;
	ULONG			uAttributes;
	PVOID			pSecurityDescriptor;
	PVOID			pSecurityQualityOfService;
} OBJECT_ATTRIBUTES, *POBJECT_ATTRIBUTES;

typedef struct _CLIENT_ID
{
	HANDLE	UniqueProcess;
	HANDLE	UniqueThread;
} CLIENT_ID, *PCLIENT_ID;

typedef struct _PEB_FREE_BLOCK
{
   struct _PEB_FREE_BLOCK	*Next;
   ULONG					Size;
} PEB_FREE_BLOCK, *PPEB_FREE_BLOCK;

typedef struct _CURDIR
{
   UNICODE_STRING	DosPath;
   HANDLE			Handle;
} CURDIR, *PCURDIR;

typedef struct _RTL_DRIVE_LETTER_CURDIR
{
	WORD	Flags;
	WORD	Length;
	DWORD	TimeStamp;
	STRING	DosPath;
} RTL_DRIVE_LETTER_CURDIR, *PRTL_DRIVE_LETTER_CURDIR;

#define	PROCESS_PARAMETERS_NORMALIZED	1	// pointers in are absolute (not self-relative)

typedef struct _PROCESS_PARAMETERS
{
    ULONG					MaximumLength;
    ULONG					Length;
    ULONG					Flags;				// PROCESS_PARAMETERS_NORMALIZED
    ULONG					DebugFlags;
    HANDLE					ConsoleHandle;
    ULONG					ConsoleFlags;
    HANDLE					StandardInput;
    HANDLE					StandardOutput;
    HANDLE					StandardError;
    CURDIR					CurrentDirectory;
    UNICODE_STRING			DllPath;
    UNICODE_STRING			ImagePathName;
    UNICODE_STRING			CommandLine;
    PWSTR					Environment;
    ULONG					StartingX;
    ULONG					StartingY;
    ULONG					CountX;
    ULONG					CountY;
    ULONG					CountCharsX;
    ULONG					CountCharsY;
    ULONG					FillAttribute;
    ULONG					WindowFlags;
    ULONG					ShowWindowFlags;
    UNICODE_STRING			WindowTitle;
    UNICODE_STRING			Desktop;
    UNICODE_STRING			ShellInfo;
    UNICODE_STRING			RuntimeInfo;
	RTL_DRIVE_LETTER_CURDIR	CurrentDirectores[32];
} PROCESS_PARAMETERS, *PPROCESS_PARAMETERS;

typedef struct _RTL_BITMAP
{
	DWORD	SizeOfBitMap;
	PDWORD	Buffer;
} RTL_BITMAP, *PRTL_BITMAP, **PPRTL_BITMAP;

#define LDR_STATIC_LINK				0x0000002
#define LDR_IMAGE_DLL				0x0000004
#define LDR_LOAD_IN_PROGRESS		0x0001000
#define LDR_UNLOAD_IN_PROGRESS		0x0002000
#define LDR_ENTRY_PROCESSED			0x0004000
#define LDR_ENTRY_INSERTED			0x0008000
#define LDR_CURRENT_LOAD			0x0010000
#define LDR_FAILED_BUILTIN_LOAD		0x0020000
#define LDR_DONT_CALL_FOR_THREADS	0x0040000
#define LDR_PROCESS_ATTACH_CALLED	0x0080000
#define LDR_DEBUG_SYMBOLS_LOADED	0x0100000
#define LDR_IMAGE_NOT_AT_BASE		0x0200000
#define LDR_WX86_IGNORE_MACHINETYPE	0x0400000

typedef struct _LDR_DATA_TABLE_ENTRY
{
    LIST_ENTRY		InLoadOrderModuleList;
    LIST_ENTRY		InMemoryOrderModuleList;
    LIST_ENTRY		InInitializationOrderModuleList;
    PVOID			DllBase;
    PVOID			EntryPoint;
    ULONG			SizeOfImage;	// in bytes
    UNICODE_STRING	FullDllName;
    UNICODE_STRING	BaseDllName;
    ULONG			Flags;			// LDR_*
    USHORT			LoadCount;
    USHORT			TlsIndex;
    LIST_ENTRY		HashLinks;
    PVOID			SectionPointer;
    ULONG			CheckSum;
    ULONG			TimeDateStamp;
//    PVOID			LoadedImports;					// seems they are exist only on XP !!!
//    PVOID			EntryPointActivationContext;	// -same-
} LDR_DATA_TABLE_ENTRY, *PLDR_DATA_TABLE_ENTRY;

typedef struct _PEB_LDR_DATA {
	ULONG Length;
	BOOLEAN Initialized;
	PVOID SsHandle;
	LIST_ENTRY ModuleListLoadOrder;
	LIST_ENTRY ModuleListMemoryOrder;
	LIST_ENTRY ModuleListInitOrder;
} PEB_LDR_DATA, *PPEB_LDR_DATA;

typedef VOID NTSYSAPI (*PPEBLOCKROUTINE)(PVOID);

typedef struct _SYSTEM_STRINGS
{
	UNICODE_STRING	SystemRoot;       // C:\WINNT
	UNICODE_STRING	System32Root;     // C:\WINNT\System32
	UNICODE_STRING	BaseNamedObjects; // \BaseNamedObjects
}SYSTEM_STRINGS,*PSYSTEM_STRINGS;

typedef struct _TEXT_INFO
{
	PVOID			Reserved;
	PSYSTEM_STRINGS	SystemStrings;
}TEXT_INFO, *PTEXT_INFO;

typedef struct _PEB
{
	UCHAR				InheritedAddressSpace;				// 0
	UCHAR				ReadImageFileExecOptions;			// 1
	UCHAR				BeingDebugged;						// 2
	BYTE				b003;								// 3
	PVOID				Mutant;								// 4
	PVOID				ImageBaseAddress;					// 8
	PPEB_LDR_DATA		Ldr;								// C
	PPROCESS_PARAMETERS	ProcessParameters;					// 10
	PVOID				SubSystemData;						// 14  
	PVOID				ProcessHeap;						// 18
	KSPIN_LOCK			FastPebLock;						// 1C
	PPEBLOCKROUTINE		FastPebLockRoutine;					// 20
	PPEBLOCKROUTINE		FastPebUnlockRoutine;				// 24
	ULONG				EnvironmentUpdateCount;				// 28
	PVOID				*KernelCallbackTable;				// 2C
	PVOID				EventLogSection;					// 30
	PVOID				EventLog;							// 34
	PPEB_FREE_BLOCK		FreeList;							// 38
	ULONG				TlsExpansionCounter;				// 3C
	PRTL_BITMAP			TlsBitmap;							// 40
	ULONG				TlsBitmapData[0x2];					// 44
	PVOID				ReadOnlySharedMemoryBase;			// 4C
	PVOID				ReadOnlySharedMemoryHeap;			// 50
	PTEXT_INFO			ReadOnlyStaticServerData;			// 54
	PVOID				InitAnsiCodePageData;				// 58
	PVOID				InitOemCodePageData;				// 5C
	PVOID				InitUnicodeCaseTableData;			// 60
	ULONG				KeNumberProcessors;					// 64
	ULONG				NtGlobalFlag;						// 68
	DWORD				d6C;								// 6C
	LARGE_INTEGER		MmCriticalSectionTimeout;			// 70
	ULONG				MmHeapSegmentReserve;				// 78
	ULONG				MmHeapSegmentCommit;				// 7C
	ULONG				MmHeapDeCommitTotalFreeThreshold;	// 80
	ULONG				MmHeapDeCommitFreeBlockThreshold;	// 84
	ULONG				NumberOfHeaps;						// 88
	ULONG				AvailableHeaps;						// 8C
	PHANDLE				ProcessHeapsListBuffer;				// 90
	PVOID				GdiSharedHandleTable;				// 94
	PVOID				ProcessStarterHelper;				// 98
	PVOID				GdiDCAttributeList;					// 9C
	KSPIN_LOCK			LoaderLock;							// A0
	ULONG				NtMajorVersion;						// A4
	ULONG				NtMinorVersion;						// A8
	USHORT				NtBuildNumber;						// AC
	USHORT				NtCSDVersion;						// AE
	ULONG				PlatformId;							// B0
	ULONG				Subsystem;							// B4
	ULONG				MajorSubsystemVersion;				// B8
	ULONG				MinorSubsystemVersion;				// BC
	KAFFINITY			AffinityMask;						// C0
	ULONG				GdiHandleBuffer[0x22];				// C4
	ULONG				PostProcessInitRoutine;				// 14C
	ULONG				TlsExpansionBitmap;					// 150
	UCHAR				TlsExpansionBitmapBits[0x80];		// 154
	ULONG				SessionId;							// 1D4
	ULARGE_INTEGER		AppCompatFlags;						// 1D8
	PWORD				CSDVersion;							// 1E0
/*	PVOID				AppCompatInfo;						// 1E4
	UNICODE_STRING		usCSDVersion;
	PVOID				ActivationContextData;
    PVOID				ProcessAssemblyStorageMap;
    PVOID				SystemDefaultActivationContextData;
    PVOID				SystemAssemblyStorageMap;
    ULONG				MinimumStackCommit; */
} PEB, *PPEB;

typedef struct _TEB
{
	NT_TIB			Tib;                         
	PVOID			EnvironmentPointer;           
	CLIENT_ID		Cid;                      
	PVOID			ActiveRpcInfo;                
	PVOID			ThreadLocalStoragePointer;    
	PPEB			Peb;                           
	ULONG			LastErrorValue;               
	ULONG			CountOfOwnedCriticalSections; 
	PVOID			CsrClientThread;              
	PVOID			Win32ThreadInfo;              
	ULONG			Win32ClientInfo[0x1F];        
	PVOID			WOW32Reserved;                
	ULONG			CurrentLocale;                
	ULONG			FpSoftwareStatusRegister;     
	PVOID			SystemReserved1[0x36];        
	PVOID			Spare1;                       
	LONG			ExceptionCode;                 
	ULONG			SpareBytes1[0x28];            
	PVOID			SystemReserved2[0xA];         
	ULONG			gdiRgn;                       
	ULONG			gdiPen;                       
	ULONG			gdiBrush;                     
	CLIENT_ID		RealClientId;             
	PVOID			GdiCachedProcessHandle;       
	ULONG			GdiClientPID;                 
	ULONG			GdiClientTID;                 
	PVOID			GdiThreadLocaleInfo;          
	PVOID			UserReserved[5];              
	PVOID			glDispatchTable[0x118];       
	ULONG			glReserved1[0x1A];            
	PVOID			glReserved2;                  
	PVOID			glSectionInfo;                
	PVOID			glSection;                    
	PVOID			glTable;                      
	PVOID			glCurrentRC;                  
	PVOID			glContext;                    
	NTSTATUS		LastStatusValue;           
	UNICODE_STRING	StaticUnicodeString; 
	WCHAR			StaticUnicodeBuffer[0x105];   
	PVOID			DeallocationStack;            
	PVOID			TlsSlots[0x40];               
	LIST_ENTRY		TlsLinks;                
	PVOID			Vdm;                          
	PVOID			ReservedForNtRpc;             
	PVOID			DbgSsReserved[0x2];           
	ULONG			HardErrorDisabled;            
	PVOID			Instrumentation[0x10];        
	PVOID			WinSockData;                  
	ULONG			GdiBatchCount;                
	ULONG			Spare2;                       
	ULONG			Spare3;                       
	ULONG			Spare4;                       
	PVOID			ReservedForOle;               
	ULONG			WaitingOnLoaderLock;          
	PVOID			StackCommit;                  
	PVOID			StackCommitMax;               
	PVOID			StackReserve;                 
} TEB, *PTEB;

typedef enum _POOL_TYPE
{
	NonPagedPool,
	PagedPool,
	NonPagedPoolMustSucceed,
	DontUseThisType,
	NonPagedPoolCacheAligned,
	PagedPoolCacheAligned,
	NonPagedPoolCacheAlignedMustS,
	MaxPoolType
} POOL_TYPE, *PPOOL_TYPE;

typedef enum _KWAIT_REASON
{
	Executive,
	FreePage,
	PageIn,
	PoolAllocation,
	DelayExecution,
	Suspended,
	UserRequest,
	WrExecutive,
	WrFreePage,
	WrPageIn,
	WrPoolAllocation,
	WrDelayExecution,
	WrSuspended,
	WrUserRequest,
	WrEventPair,
	WrQueue,
	WrLpcReceive,
	WrLpcReply,
	WrVirtualMemory,
	WrPageOut,
	WrRendezvous,
	Spare2,
	Spare3,
	Spare4,
	Spare5,
	Spare6,
	WrKernel,
	MaximumWaitReason
} KWAIT_REASON, *PKWAIT_REASON;

typedef struct _DISPATCHER_HEADER
{
	BYTE		uType;			//DO_TYPE_*
	BYTE		uAbsolute;
	BYTE		uSize;			// number of DWORDs
	BYTE		uInserted;
	LONG		lSignalState;
	LIST_ENTRY	WaitListHead;
} DISPATCHER_HEADER, *PDISPATCHER_HEADER;

typedef struct _KPROCESS
{
	DISPATCHER_HEADER	Header;           // DO_TYPE_PROCESS (0x1A)
	LIST_ENTRY			le10;
	DWORD				d18;
	DWORD				d1C;
	DWORD				d20;
	DWORD				d24;
	DWORD				d28;
	DWORD				d2C;
	DWORD				d30;
	DWORD				d34;
	DWORD				dKernelTime;      // ticks
	DWORD				dUserTime;        // ticks
	LIST_ENTRY			le40;
	LIST_ENTRY			OutSwapList;
	LIST_ENTRY			ThreadListHead;   // KTHREAD.ThreadList
	DWORD				d58;
	KAFFINITY			AffinityMask;
	WORD				w60;
	BYTE				bBasePriority;
	BYTE				b63;
	WORD				w64;
	BYTE				b66;
	BOOLEAN				fPriorityBoost;
} KPROCESS, *PKPROCESS;

typedef struct _PORT_MESSAGE
{
	USHORT		DataSize;
	USHORT		MessageSize;
	USHORT		MessageType;
	USHORT		VirtualRangesOffset;
	CLIENT_ID	ClientId;
	ULONG		MessageId;
	ULONG		SectionSize;
//	UCHAR		Data[];
} PORT_MESSAGE, *PPORT_MESSAGE;

typedef struct _SERVICE_DESCRIPTOR_TABLE
{
	PNTSYSCALL	ServiceTable;    // array of entrypoints
	PULONG		puCounterTable;    // array of counters
	ULONG		uTableSize;       // number of table entries
	PBYTE		pbArgumentTable;   // array of byte counts
} SERVICE_DESCRIPTOR_TABLE, *PSERVICE_DESCRIPTOR_TABLE;

typedef struct _KSEMAPHORE
{
	DISPATCHER_HEADER	Header;
	LONG				lLimit;
} KSEMAPHORE, *PKSEMAPHORE;

typedef struct _KTHREAD
{
	DISPATCHER_HEADER			Header;       // DO_TYPE_THREAD (0x6C)
	LIST_ENTRY					le010;
	DWORD						d018;
	DWORD						d01C;
	PTEB						pTeb;
	DWORD						d024;
	DWORD						d028;
	BYTE						b02C;
	BYTE						bThreadState; // THREAD_STATE_*
	WORD						w02E;
	WORD						w030;
	BYTE						b032;
	BYTE						bPriority;
	LIST_ENTRY					le034;
	LIST_ENTRY					le03C;
	PKPROCESS					pProcess;
	DWORD						d048;
	DWORD						dContextSwitches;
	DWORD						d050;
	WORD						w054;
	BYTE						b056;
	BYTE						bWaitReason;
	DWORD						d058;
	PLIST_ENTRY					ple05C;
	PLIST_ENTRY					ple060;
	DWORD						d064;
	BYTE						bBasePriority;
	BYTE						b069;
	WORD						w06A;
	DWORD						d06C;
	DWORD						d070;
	DWORD						d074;
	DWORD						d078;
	DWORD						d07C;
	DWORD						d080;
	DWORD						d084;
	DWORD						d088;
	DWORD						d08C;
	DWORD						d090;
	DWORD						d094;
	DWORD						d098;
	DWORD						d09C;
	DWORD						d0A0;
	DWORD						d0A4;
	DWORD						d0A8;
	DWORD						d0AC;
	DWORD						d0B0;
	DWORD						d0B4;
	DWORD						d0B8;
	DWORD						d0BC;
	DWORD						d0C0;
	DWORD						d0C4;
	DWORD						d0C8;
	DWORD						d0CC;
	DWORD						d0D0;
	DWORD						d0D4;
	DWORD						d0D8;
	PSERVICE_DESCRIPTOR_TABLE	pServiceDescriptorTable;
	DWORD						d0E0;
	DWORD						d0E4;
	DWORD						d0E8;
	DWORD						d0EC;
	LIST_ENTRY					le0F0;
	DWORD						d0F8;
	DWORD						d0FC;
	DWORD						d100;
	DWORD						d104;
	DWORD						d108;
	DWORD						d10C;
	DWORD						d110;
	DWORD						d114;
	DWORD						d118;
	BYTE						b11C;
	BYTE						b11D;
	WORD						w11E;
	DWORD						d120;
	DWORD						d124;
	DWORD						d128;
	DWORD						d12C;
	DWORD						d130;
	WORD						w134;
	BYTE						b136;
	KPROCESSOR_MODE				ProcessorMode;
	DWORD						dKernelTime;  // ticks
	DWORD						dUserTime;    // ticks
	DWORD						d140;
	DWORD						d144;
	DWORD						d148;
	DWORD						d14C;
	DWORD						d150;
	DWORD						d154;
	DWORD						d158;
	DWORD						d15C;
	DWORD						d160;
	DWORD						d164;
	DWORD						d168;
	DWORD						d16C;
	DWORD						d170;
	PROC						SuspendNop;
	DWORD						d178;
	DWORD						d17C;
	DWORD						d180;
	DWORD						d184;
	DWORD						d188;
	DWORD						d18C;
	KSEMAPHORE					SuspendSemaphore;
	LIST_ENTRY					ThreadList; // KPROCESS.ThreadListHead
	DWORD						d1AC;
} KTHREAD, *PKTHREAD;

typedef struct _ETHREAD
{
	KTHREAD			Tcb;
	LARGE_INTEGER	liCreateTime;
	LARGE_INTEGER	liExitTime;
	NTSTATUS		ExitStatus;
	LIST_ENTRY		PostBlockList;
	LIST_ENTRY		TerminationPortList;
	ULONG			uActiveTimerListLock;
	LIST_ENTRY		ActiveTimerListHead;
	CLIENT_ID		Cid;
	KSEMAPHORE		LpcReplySemaphore;
	ULONG			uLpcReplyMessage;
	LARGE_INTEGER	liLpcReplyMessageId;
	ULONG			uImpersonationInfo;
	LIST_ENTRY		IrpList;
	LIST_ENTRY		TopLevelIrp;
	ULONG			uReadClusterSize;
	BOOLEAN			fForwardClusterOnly;
	BOOLEAN			fDisablePageFaultClustering;
	BOOLEAN			fDeadThread;
	BOOLEAN			fHasTerminated;
	ULONG			uEventPair;
	ULONG			uGrantedAccess;
	ULONG			uThreadsProcess;
	PVOID			pStartAddress;
	PVOID			Win32StartAddress;
	BOOLEAN			fLpcExitThreadCalled;
	BOOLEAN			fHardErrorsAreDisabled;
	WORD			wUknown1;
	DWORD			dwUknown2;
} ETHREAD, *PETHREAD;

typedef PETHREAD	ERESOURCE_THREAD,
					*PERESOURCE_THREAD;

typedef struct _KEVENT
{
	DISPATCHER_HEADER	Header;
} KEVENT, *PKEVENT;

typedef struct _ERESOURCE_OLD
{
	LIST_ENTRY			SystemResourcesList;
	PERESOURCE_THREAD	OwnerThreads;
	PBYTE				pbOwnerCounts;
	WORD				wTableSize;
	WORD				wActiveCount;
	WORD				wFlag;
	WORD				wTableRover;
	BYTE				bInitialOwnerCounts[4];
	ERESOURCE_THREAD	InitialOwnerThreads[4];
	DWORD				dwUknown1;
	ULONG				uContentionCount;
	WORD				wNumberOfExclusiveWaiters;
	WORD				wNumberOfSharedWaiters;
	KSEMAPHORE			SharedWaiters;
	KEVENT				ExclusiveWaiters;
	KSPIN_LOCK			SpinLock;
	ULONG				uCreatorBackTraceIndex;
	WORD				wDepth;
	WORD				wUknown2;
	PVOID				pOwnerBackTrace[4];
} ERESOURCE_OLD, *PERESOURCE_OLD;

typedef struct _OWNER_ENTRY
{
	ERESOURCE_THREAD	OwnerThread;
	SHORT				sOwnerCount;
	WORD				wTableSize;
} OWNER_ENTRY, *POWNER_ENTRY;

typedef struct _ERESOURCE_LITE
{
	LIST_ENTRY		SystemResourcesList;
	POWNER_ENTRY	OwnerTable;
	SHORT			sActiveCount;
	WORD			wFlag;
	PKSEMAPHORE		SharedWaiters;
	PKEVENT			ExclusiveWaiters;
	OWNER_ENTRY		OwnerThreads[2];
	ULONG			uContentionCount;
	WORD			wNumberOfSharedWaiters;
	WORD			wNumberOfExclusiveWaiters;
	union
	{

		PVOID		pAddress;
		ULONG		uCreatorBackTraceIndex;
	};
	KSPIN_LOCK		SpinLock;
} ERESOURCE_LITE, *PERESOURCE_LITE;

typedef ERESOURCE_LITE	ERESOURCE,
						*PERESOURCE;

typedef struct _IO_STATUS_BLOCK
{
	NTSTATUS	Status;
	ULONG		uInformation;
} IO_STATUS_BLOCK, *PIO_STATUS_BLOCK;

/* Defined in Winnt.h
typedef struct _QUOTA_LIMITS {
    SIZE_T PagedPoolLimit;
    SIZE_T NonPagedPoolLimit;
    SIZE_T MinimumWorkingSetSize;
    SIZE_T MaximumWorkingSetSize;
    SIZE_T PagefileLimit;
    LARGE_INTEGER TimeLimit;
} QUOTA_LIMITS, *PQUOTA_LIMITS;
*/

typedef struct _IOCOUNTERS
{
	ULONG			uReadOperationCount;
	ULONG			uWriteOperationCount;
	ULONG			uOtherOperationCount;
	LARGE_INTEGER	liReadTransferCount;
	LARGE_INTEGER	liWriteTransferCount;
	LARGE_INTEGER	liOtherTransferCount;
} IOCOUNTERS, *PIOCOUNTERS;

typedef struct _VM_COUNTERS
{
	ULONG	uPeakVirtualSize;
	ULONG	uVirtualSize;
	ULONG	uPageFaultCount;
	ULONG	uPeakWorkingSetSize;
	ULONG	uWorkingSetSize;
	ULONG	uQuotaPeakPagedPoolUsage;
	ULONG	uQuotaPagedPoolUsage;
	ULONG	uQuotaPeakNonPagedPoolUsage;
	ULONG	uQuotaNonPagedPoolUsage;
	ULONG	uPagefileUsage;
	ULONG	uPeakPagefileUsage;
} VM_COUNTERS, *PVM_COUNTERS;

typedef struct _KERNEL_USER_TIMES
{
	LARGE_INTEGER liCreateTime;
	LARGE_INTEGER liExitTime;
	LARGE_INTEGER liKernelTime;
	LARGE_INTEGER liUserTime;
} KERNEL_USER_TIMES, *PKERNEL_USER_TIMES;

typedef struct _BASE_PRIORITY_INFORMATION
{
	KPRIORITY	BasePriority;
} BASE_PRIORITY_INFORMATION, *PBASE_PRIORITY_INFORMATION;

typedef struct _AFFINITY_MASK
{
	KAFFINITY	AffinityMask;
} AFFINITY_MASK, *PAFFINITY_MASK;

typedef struct _TIME_FIELDS
{
	WORD	wYear;
	WORD	wMonth;
	WORD	wDay;
	WORD	wHour;
	WORD	wMinute;
	WORD	wSecond;
	WORD	wMilliseconds;
	WORD	wWeekday;
} TIME_FIELDS, *PTIME_FIELDS;

typedef void (*PIO_APC_ROUTINE)	(PVOID				ApcContext,
                                 PIO_STATUS_BLOCK	IoStatusBlock,
                                 ULONG				Reserved);

#if(_WIN32_WINNT < 0x0400)

typedef struct _NTFS_VOLUME_DATA_BUFFER
{
	LARGE_INTEGER	liSerialNumber;
	LARGE_INTEGER	liNumberOfSectors;
	LARGE_INTEGER	liTotalClusters;
	LARGE_INTEGER	liFreeClusters;
	LARGE_INTEGER	liReserved;
	ULONG			uBytesPerSector;
	ULONG			uBytesPerCluster;
	ULONG			uBytesPerMFTRecord;
	ULONG			uClustersPerMFTRecord;
	LARGE_INTEGER	liMFTLength;
	LARGE_INTEGER	liMFTStart;
	LARGE_INTEGER	liMFTMirrorStart;
	LARGE_INTEGER	liMFTZoneStart;
	LARGE_INTEGER	liMFTZoneEnd;
} NTFS_VOLUME_DATA_BUFFER, *PNTFS_VOLUME_DATA_BUFFER;

#endif

typedef struct _OBJDIR_INFORMATION
{
	UNICODE_STRING	ObjectName;
	UNICODE_STRING	ObjectTypeName; // e.g. Directory, Device ...
	UCHAR			Data[1];        // variable length
} OBJDIR_INFORMATION, *POBJDIR_INFORMATION;

// Define the file system information class values
typedef enum _FSINFOCLASS {
    FileFsVolumeInformation       = 1,
    FileFsLabelInformation,      // 2
    FileFsSizeInformation,       // 3
    FileFsDeviceInformation,     // 4
    FileFsAttributeInformation,  // 5
    FileFsControlInformation,    // 6
    FileFsFullSizeInformation,   // 7
    FileFsObjectIdInformation,   // 8
    FileFsMaximumInformation
} FS_INFORMATION_CLASS, *PFS_INFORMATION_CLASS;

typedef struct _FILE_FS_VOLUME_INFORMATION {
    LARGE_INTEGER VolumeCreationTime;
    ULONG VolumeSerialNumber;
    ULONG VolumeLabelLength;
    BOOLEAN SupportsObjects;
    WCHAR VolumeLabel[1];
} FILE_FS_VOLUME_INFORMATION, *PFILE_FS_VOLUME_INFORMATION;

typedef struct _FILE_FS_LABEL_INFORMATION {
    ULONG VolumeLabelLength;
    WCHAR VolumeLabel[1];
} FILE_FS_LABEL_INFORMATION, *PFILE_FS_LABEL_INFORMATION;

typedef struct _FILE_FS_SIZE_INFORMATION {
    LARGE_INTEGER TotalAllocationUnits;
    LARGE_INTEGER AvailableAllocationUnits;
    ULONG SectorsPerAllocationUnit;
    ULONG BytesPerSector;
} FILE_FS_SIZE_INFORMATION, *PFILE_FS_SIZE_INFORMATION;

typedef struct _FILE_FS_DEVICE_INFORMATION {
    DEVICE_TYPE DeviceType;
    ULONG Characteristics;
} FILE_FS_DEVICE_INFORMATION, *PFILE_FS_DEVICE_INFORMATION;

typedef struct _FILE_FS_ATTRIBUTE_INFORMATION {
    ULONG FileSystemAttributes;
    LONG MaximumComponentNameLength;
    ULONG FileSystemNameLength;
    WCHAR FileSystemName[1];
} FILE_FS_ATTRIBUTE_INFORMATION, *PFILE_FS_ATTRIBUTE_INFORMATION;

typedef struct _FILE_FS_CONTROL_INFORMATION {
    LARGE_INTEGER FreeSpaceStartFiltering;
    LARGE_INTEGER FreeSpaceThreshold;
    LARGE_INTEGER FreeSpaceStopFiltering;
    LARGE_INTEGER DefaultQuotaThreshold;
    LARGE_INTEGER DefaultQuotaLimit;
    ULONG FileSystemControlFlags;
} FILE_FS_CONTROL_INFORMATION, *PFILE_FS_CONTROL_INFORMATION;

typedef struct _FILE_FS_FULL_SIZE_INFORMATION {
    LARGE_INTEGER TotalQuotaAllocationUnits;
    LARGE_INTEGER AvailableQuotaAllocationUnits;
    LARGE_INTEGER AvailableAllocationUnits;
    ULONG SectorsPerAllocationUnit;
    ULONG BytesPerSector;
} FILE_FS_FULL_SIZE_INFORMATION, *PFILE_FS_FULL_SIZE_INFORMATION;

typedef struct _FILE_FS_OBJECT_ID_INFORMATION {
    GUID VolumeObjectId;
    ULONG VolumeObjectIdExtendedInfo[12];
} FILE_FS_OBJECT_ID_INFORMATION, *PFILE_FS_OBJECT_ID_INFORMATION;

typedef enum _SYSTEMINFOCLASS
{
	SystemBasicInformation,             // 0x002C
	SystemProcessorInformation,         // 0x000C
	SystemPerformanceInformation,       // 0x0138
	SystemTimeInformation,              // 0x0020
	SystemPathInformation,              // not implemented
	SystemProcessInformation,           // 0x00C8+ per process
	SystemCallInformation,              // 0x0018 + (n * 0x0004)
	SystemConfigurationInformation,     // 0x0018
	SystemProcessorCounters,            // 0x0030 per cpu
	SystemGlobalFlag,                   // 0x0004 (fails if size != 4)
	SystemCallTimeInformation,          // not implemented
	SystemModuleInformation,            // 0x0004 + (n * 0x011C)
	SystemLockInformation,              // 0x0004 + (n * 0x0024)
	SystemStackTraceInformation,        // not implemented
	SystemPagedPoolInformation,         // checked build only
	SystemNonPagedPoolInformation,      // checked build only
	SystemHandleInformation,            // 0x0004  + (n * 0x0010)
	SystemObjectTypeInformation,        // 0x0038+ + (n * 0x0030+)
	SystemPageFileInformation,          // 0x0018+ per page file
	SystemVdmInstemulInformation,       // 0x0088
	SystemVdmBopInformation,            // invalid info class
	SystemCacheInformation,             // 0x0024
	SystemPoolTagInformation,           // 0x0004 + (n * 0x001C)
	SystemInterruptInformation,         // 0x0000, or 0x0018 per cpu
	SystemDpcInformation,               // 0x0014
	SystemFullMemoryInformation,        // checked build only
	SystemLoadDriver,                   // 0x0018, set mode only
	SystemUnloadDriver,                 // 0x0004, set mode only
	SystemTimeAdjustmentInformation,    // 0x000C, 0x0008 writeable
	SystemSummaryMemoryInformation,     // checked build only
	SystemNextEventIdInformation,       // checked build only
	SystemEventIdsInformation,          // checked build only
	SystemCrashDumpInformation,         // 0x0004
	SystemExceptionInformation,         // 0x0010
	SystemCrashDumpStateInformation,    // 0x0004
	SystemDebuggerInformation,          // 0x0002
	SystemContextSwitchInformation,     // 0x0030
	SystemRegistryQuotaInformation,     // 0x000C
	SystemAddDriver,                    // 0x0008, set mode only
	SystemPrioritySeparationInformation,// 0x0004, set mode only
	SystemPlugPlayBusInformation,       // not implemented
	SystemDockInformation,              // not implemented
	SystemPowerInfo,             // 0x0060 (XP only!)
	SystemProcessorSpeedInformation,    // 0x000C (XP only!)
	SystemTimeZoneInformation,          // 0x00AC
	SystemLookasideInformation,         // n * 0x0020
	SystemSetTimeSlipEvent,
    SystemCreateSession,				// set mode only
    SystemDeleteSession,				// set mode only
    SystemInvalidInfoClass1,			// invalid info class
    SystemRangeStartInformation,		// 0x0004 (fails if size != 4)
    SystemVerifierInformation,
    SystemAddVerifier,
    SystemSessionProcessesInformation,	// checked build only
	MaxSystemInfoClass
} SYSTEMINFOCLASS, *PSYSTEMINFOCLASS;

typedef struct _SYSTEM_BASIC_INFORMATION
{
    DWORD		dwUnknown1;               // 0
    ULONG		uKeMaximumIncrement;      // x86: 0x0002625A or 0x00018730
    ULONG		uPageSize;                // bytes
    ULONG		uMmNumberOfPhysicalPages;
    ULONG		uMmLowestPhysicalPage;
    ULONG		uMmHighestPhysicalPage;
    ULONG		uAllocationGranularity;   // bytes
    PVOID		pLowestUserAddress;
    PVOID		pMmHighestUserAddress;
    KAFFINITY	uKeActiveProcessors;
    BYTE		bKeNumberProcessors;
    BYTE		bUnknown2;
    WORD		wUnknown3;
} SYSTEM_BASIC_INFORMATION, *PSYSTEM_BASIC_INFORMATION;

typedef struct _SYSTEM_PROCESSOR_INFORMATION
{
	WORD	wKeProcessorArchitecture; // PROCESSOR_ARCHITECTURE_* (PROCESSOR_ARCHITECTURE_INTEL)
	WORD	wKeProcessorLevel;        // PROCESSOR_* (PROCESSOR_INTEL_PENTIUM)
	WORD	wKeProcessorRevision;     // Pentium: H=model, L=stepping
	WORD	wUnknown1;                // 0
	ULONG	uKeFeatureBits;
} SYSTEM_PROCESSOR_INFORMATION, *PSYSTEM_PROCESSOR_INFORMATION;

typedef struct _MM_INFO_COUNTERS
{
	ULONG	uPageFaults;
	ULONG	uWriteCopyFaults;
	ULONG	uTransistionFaults;
	ULONG	uCacheTransitionCount;
	ULONG	uDemandZeroFaults;
	ULONG	uPagesRead;
	ULONG	uPageReadIos;
	ULONG	uCacheReadCount;
	ULONG	uCacheIoCount;
	ULONG	uPagefilePagesWritten;
	ULONG	uPagefilePageWriteIos;
	ULONG	uMappedFilePagesWritten;
	ULONG	uMappedFilePageWriteIos;
} MM_INFO_COUNTERS, *PMM_INFO_COUNTERS;

typedef struct _SYSTEM_PERFORMANCE_INFORMATION
{
	LARGE_INTEGER		liIdleTime;             // 100 nsec units
	LARGE_INTEGER		liIoReadTransferCount;
	LARGE_INTEGER		liIoWriteTransferCount;
	LARGE_INTEGER		liIoOtherTransferCount;
	ULONG				uIoReadOperationCount;
	ULONG				uIoWriteOperationCount;
	ULONG				uIoOtherOperationCount;
	ULONG				uMmAvailablePages;
	ULONG				uMmTotalCommittedPages;
	ULONG				uMmTotalCommitLimit;   // pages
	ULONG				uMmPeakCommitLimit;    // pages
	MM_INFO_COUNTERS	MmInfoCounters;
	ULONG				uPoolPaged;            // pages
	ULONG				uPoolNonPaged;         // pages
	ULONG				uPagedPoolAllocs;
	ULONG				uPagedPoolFrees;
	ULONG				uNonPagedPoolAllocs;
	ULONG				uNonPagedPoolFrees;
	ULONG				uMmTotalFreeSystemPages;
	ULONG				uMmSystemCodePage;
	ULONG				uMmTotalSystemDriverPages;
	ULONG				uMmTotalSystemCodePages;
	ULONG				uSmallNonPagedLookasideListAllocateHits;
	ULONG				uSmallPagedLookasideListAllocateHits;
	DWORD				dwUnknown1;
	ULONG				uMmSystemCachePage;
	ULONG				uMmPagedPoolPage;
	ULONG				uMmSystemDriverPage;
	ULONG				uCcFastReadNoWait;
	ULONG				uCcFastReadWait;
	ULONG				uCcFastReadResourceMiss;
	ULONG				uCcFastReadNotPossible;
	ULONG				uCcFastMdlReadNoWait;
	ULONG				uCcFastMdlReadWait;
	ULONG				uCcFastMdlReadResourceMiss;
	ULONG				uCcFastMdlReadNotPossible;
	ULONG				uCcMapDataNoWait;
	ULONG				uCcMapDataWait;
	ULONG				uCcMapDataNoWaitMiss;
	ULONG				uCcMapDataWaitMiss;
	ULONG				uCcPinMappedDataCount;
	ULONG				uCcPinReadNoWait;
	ULONG				uCcPinReadWait;
	ULONG				uCcPinReadNoWaitMiss;
	ULONG				uCcPinReadWaitMiss;
	ULONG				uCcCopyReadNoWait;
	ULONG				uCcCopyReadWait;
	ULONG				uCcCopyReadNoWaitMiss;
	ULONG				uCcCopyReadWaitMiss;
	ULONG				uCcMdlReadNoWait;
	ULONG				uCcMdlReadWait;
	ULONG				uCcMdlReadNoWaitMiss;
	ULONG				uCcMdlReadWaitMiss;
	ULONG				uCcReadAheadIos;
	ULONG				uCcLazyWriteIos;
	ULONG				uCcLazyWritePages;
	ULONG				uCcDataFlushes;
	ULONG				uCcDataPages;
	ULONG				uTotalContextSwitches; // total across cpus
	ULONG				uFirstLevelTbFills;
	ULONG				uSecondLevelTbFills;
	ULONG				uSystemCalls;
} SYSTEM_PERFORMANCE_INFORMATION, *PSYSTEM_PERFORMANCE_INFORMATION;

typedef struct _SYSTEM_TIME_INFORMATION
{
	LARGE_INTEGER	liKeBootTime;			// relative to 01-01-1601
	LARGE_INTEGER	liKeSystemTime;			// relative to 01-01-1601
	LARGE_INTEGER	liExpTimeZoneBias;		// utc time = local time + bias
	ULONG			uExpCurrentTimeZoneId;	// TIME_ZONE_ID_* (TIME_ZONE_ID_UNKNOWN, etc.)
	DWORD			dwUnknown1;
} SYSTEM_TIME_INFORMATION, *PSYSTEM_TIME_INFORMATION;

typedef enum
{
    StateInitialized,
    StateReady,
    StateRunning,
    StateStandby,
    StateTerminated,
    StateWait,
    StateTransition,
    StateUnknown
} THREAD_STATE;

typedef struct _SYSTEM_THREAD
{
	LARGE_INTEGER	liKernelTime;       // 100 nsec units
	LARGE_INTEGER	liUserTime;         // 100 nsec units
	LARGE_INTEGER	liCreateTime;       // relative to 01-01-1601
	ULONG			WaitTime;			// ticks
	PVOID			pStartAddress;		// EIP
	CLIENT_ID		Cid;				// process/thread ids
	KPRIORITY		Priority;
	KPRIORITY		BasePriority;
	ULONG			ContextSwitches;
	THREAD_STATE	ThreadState;
	KWAIT_REASON	WaitReason;
//	DWORD			dwUnknown2;			// maybe it not exists !!!
} SYSTEM_THREAD, *PSYSTEM_THREAD;

typedef struct _SYSTEM_PROCESS_INFORMATION
{
	ULONG			uNext;           // relative offset
	ULONG			uThreadCount;
	LARGE_INTEGER	liUnknown1;
	LARGE_INTEGER	liUnknown2;
	LARGE_INTEGER	liUnknown3;
	LARGE_INTEGER	liCreateTime;     // relative to 01-01-1601
	LARGE_INTEGER	liUserTime;       // 100 nsec units
	LARGE_INTEGER	liKernelTime;     // 100 nsec units
	UNICODE_STRING	usName;
	KPRIORITY		BasePriority;
	ULONG			uUniqueProcessId;
	ULONG			uInheritedFromUniqueProcessId;
	ULONG			uHandleCount;
	ULONG			uSessionId;      // W2K Only!
	DWORD			dwUnknown5;
	VM_COUNTERS		VmCounters;
	ULONG			uCommitCharge;   // bytes
	SYSTEM_THREAD	aST[];
} SYSTEM_PROCESS_INFORMATION, *PSYSTEM_PROCESS_INFORMATION;

typedef struct _IO_COUNTERSEX
{
    LARGE_INTEGER	ReadOperationCount;
    LARGE_INTEGER	WriteOperationCount;
    LARGE_INTEGER	OtherOperationCount;
    LARGE_INTEGER	ReadTransferCount;
    LARGE_INTEGER	WriteTransferCount;
    LARGE_INTEGER	OtherTransferCount;
} IO_COUNTERSEX, *PIO_COUNTERSEX;

typedef struct _SYSTEM_PROCESS_INFORMATION_2000
{
	ULONG			uNext;           // relative offset
	ULONG			uThreadCount;
	LARGE_INTEGER	liUnknown1;
	LARGE_INTEGER	liUnknown2;
	LARGE_INTEGER	liUnknown3;
	LARGE_INTEGER	liCreateTime;     // relative to 01-01-1601
	LARGE_INTEGER	liUserTime;       // 100 nsec units
	LARGE_INTEGER	liKernelTime;     // 100 nsec units
	UNICODE_STRING	usName;
	KPRIORITY		BasePriority;
	ULONG			uUniqueProcessId;
	ULONG			uInheritedFromUniqueProcessId;
	ULONG			uHandleCount;
	ULONG			uSessionId;      // W2K Only!
	DWORD			dwUnknown5;
	VM_COUNTERS		VmCounters;
	ULONG			uCommitCharge;   // bytes
	IO_COUNTERSEX	IoCounters;
	SYSTEM_THREAD	aST[];
} SYSTEM_PROCESS_INFORMATION_2000, *PSYSTEM_PROCESS_INFORMATION_2000;

typedef struct _SYSTEM_CALL_INFORMATION
{
	ULONG	Length;
	ULONG	NumberOfTables;
//	ULONG	NumberOfEntries[NumberOfTables]
//	ULONG	CallCounts[NumberOfTables][NumberOfEntries];
} SYSTEM_CALL_INFORMATION, *PSYSTEM_CALL_INFORMATION;

typedef struct _SYSTEM_CONFIGURATION_INFORMATION
{
	ULONG	uDiskCount;
	ULONG	uFloppyCount;
	ULONG	uCDRomCount;
	ULONG	uTapeCount;
	ULONG	uSerialCount;         // com port with mouse not included
	ULONG	uParallelCount;
} SYSTEM_CONFIGURATION_INFORMATION, *PSYSTEM_CONFIGURATION_INFORMATION;

typedef struct _SYSTEM_PROCESSOR_COUNTERS
{
	LARGE_INTEGER	liProcessorTime;       // 100 nsec units
	LARGE_INTEGER	liKernelTime;          // 100 nsec units
	LARGE_INTEGER	liUserTime;            // 100 nsec units
	LARGE_INTEGER	liDpcTime;             // 100 nsec units
	LARGE_INTEGER	liInterruptTime;       // 100 nsec units
	ULONG			uInterruptCount;
	DWORD			dwUnknown1;
} SYSTEM_PROCESSOR_COUNTERS, *PSYSTEM_PROCESSOR_COUNTERS;

typedef struct _SYSTEM_GLOBAL_FLAG
{
	ULONG	NtGlobalFlag;        // see Q147314, Q102985, Q105677
} SYSTEM_GLOBAL_FLAG, *PSYSTEM_GLOBAL_FLAG;

typedef struct _SYSTEM_CALL_TIME_INFORMATION
{
	ULONG			Length;
	ULONG			TotalCalls;
	LARGE_INTEGER	TimeOfCalls[1];
} SYSTEM_CALL_TIME_INFORMATION, *PSYSTEM_CALL_TIME_INFORMATION;

typedef struct _SYSTEM_MODULE
{
    ULONG	Reserved[2];
    ULONG	Base;
    ULONG	Size;
    ULONG	Flags;
    USHORT	Index;
    USHORT	Unknown;
    USHORT	LoadCount;
    USHORT	ModuleNameOffset;
    CHAR	ImageName[256];
} SYSTEM_MODULE, *PSYSTEM_MODULE;

typedef struct _SYSTEM_MODULE_INFORMATION
{
	ULONG			uCount;
	SYSTEM_MODULE	aSM[];
} SYSTEM_MODULE_INFORMATION, *PSYSTEM_MODULE_INFORMATION;

typedef struct _SYSTEM_LOCK
{
	union
	{
		PERESOURCE_OLD	pEResourceOld;  // old ERESOURCE format
		PERESOURCE_LITE	pEResourceLite; // new "lite" format
		PERESOURCE		pEResource;     // current format
	};
	WORD	wUnknown1;                  // 1
	WORD	wUnknown2;                  // 0
	ULONG	ExclusiveOwnerThreadId;
	ULONG	uActiveCount;
	ULONG	uContentionCount;
	DWORD	dwUnknown3;
	DWORD	dwUnknown4;
	ULONG	uNumberOfSharedWaiters;
	ULONG	uNumberOfExclusiveWaiters;
} SYSTEM_LOCK, *PSYSTEM_LOCK;

typedef struct _SYSTEM_LOCK_INFORMATION
{
	ULONG		uCount;
	SYSTEM_LOCK	aSL[];
} SYSTEM_LOCK_INFORMATION, *PSYSTEM_LOCK_INFORMATION;

typedef struct _SYSTEM_HANDLE
{
	ULONG		uIdProcess;
	UCHAR		ObjectType;    // OB_TYPE_* (OB_TYPE_TYPE, etc.)
	UCHAR		Flags;         // HANDLE_FLAG_* (HANDLE_FLAG_INHERIT, etc.)
	USHORT		Handle;
	POBJECT		pObject;
	ACCESS_MASK	GrantedAccess;
} SYSTEM_HANDLE, *PSYSTEM_HANDLE;

typedef struct _SYSTEM_HANDLE_INFORMATION
{
	ULONG			uCount;
	SYSTEM_HANDLE	aSH[];
} SYSTEM_HANDLE_INFORMATION, *PSYSTEM_HANDLE_INFORMATION;

typedef struct _SYSTEM_OBJECTTYPE_INFORMATION
{
	ULONG			NextEntryOffset;	// absolute offset
	ULONG			ObjectCount;
	ULONG			HandleCount;
	ULONG			TypeIndex;			// OB_TYPE_* (OB_TYPE_TYPE, etc.)
	ULONG			InvalidAttributes;	// OBJ_* (OBJ_INHERIT, etc.)
	GENERIC_MAPPING	GenericMapping;
	ACCESS_MASK		ValidAccessMask;
	POOL_TYPE		PoolType;
	BOOLEAN			SecurityRequired;
	BOOLEAN			WaitableObject;
	UNICODE_STRING	TypeName;
} SYSTEM_OBJECTTYPE_INFORMATION, *PSYSTEM_OBJECTTYPE_INFORMATION;

// follows after SYSTEM_OBJECTTYPE_INFORMATION.TypeName
typedef struct _SYSTEM_OBJECT_INFORMATION
{
	ULONG					NextEntryOffset;		// absolute offset
	POBJECT					Object;
	ULONG					CreatorProcessId;
	USHORT					CreatorBackTraceIndex;
	USHORT					Flags;					// see "Native API Reference" page 24
	LONG					PointerCount;
	LONG					HandleCount;
	ULONG					PagedPoolCharge;
	ULONG					NonPagedPoolCharge;
	ULONG					ExclusiveProcessId;
	PSECURITY_DESCRIPTOR	SecurityDescriptor;
	UNICODE_STRING			ObjectName;
} SYSTEM_OBJECT_INFORMATION, *PSYSTEM_OBJECT_INFORMATION;

typedef struct _SYSTEM_PAGE_FILE_INFORMATION
{
	ULONG			NextEntryOffset;	// relative offset
	ULONG			CurrentSize;		// pages
	ULONG			TotalUsed;			// pages
	ULONG			PeakUsed;			// pages
	UNICODE_STRING	FileName;
} SYSTEM_PAGE_FILE_INFORMATION, *PSYSTEM_PAGE_FILE_INFORMATION;

typedef struct _SYSTEM_VDM_INSTEMUL_INFO
{
	BOOL	fExVdmSegmentNotPresent;
	ULONG	uOpcode0FV86;
	ULONG	uOpcodeESPrefixV86;
	ULONG	uOpcodeCSPrefixV86;
	ULONG	uOpcodeSSPrefixV86;
	ULONG	uOpcodeDSPrefixV86;
	ULONG	uOpcodeFSPrefixV86;
	ULONG	uOpcodeGSPrefixV86;
	ULONG	uOpcodeOPER32PrefixV86;
	ULONG	uOpcodeADDR32PrefixV86;
	ULONG	uOpcodeINSBV86;
	ULONG	uOpcodeINSWV86;
	ULONG	uOpcodeOUTSBV86;
	ULONG	uOpcodeOUTSWV86;
	ULONG	uOpcodePUSHFV86;
	ULONG	uOpcodePOPFV86;
	ULONG	uOpcodeINTnnV86;
	ULONG	uOpcodeINTOV86;
	ULONG	uOpcodeIRETV86;
	ULONG	uOpcodeINBimmV86;
	ULONG	uOpcodeINWimmV86;
	ULONG	uOpcodeOUTBimmV86;
	ULONG	uOpcodeOUTWimmV86;
	ULONG	uOpcodeINBV86;
	ULONG	uOpcodeINWV86;
	ULONG	uOpcodeOUTBV86;
	ULONG	uOpcodeOUTWV86;
	ULONG	uOpcodeLOCKPrefixV86;
	ULONG	uOpcodeREPNEPrefixV86;
	ULONG	uOpcodeREPPrefixV86;
	ULONG	uOpcodeHLTV86;
	ULONG	uOpcodeCLIV86;
	ULONG	uOpcodeSTIV86;
	ULONG	uVdmBopCount;
} SYSTEM_VDM_INSTEMUL_INFO, *PSYSTEM_VDM_INSTEMUL_INFO;

typedef struct _SYSTEM_CACHE_INFORMATION
{
    ULONG uFileCache;           // bytes
	ULONG uFileCachePeak;       // bytes
    ULONG PageFaultCount;
    ULONG MinimumWorkingSet;
    ULONG MaximumWorkingSet;
    ULONG TransitionSharedPages;
    ULONG TransitionSharedPagesPeak;
    ULONG Reserved[2];
} SYSTEM_CACHE_INFORMATION, *PSYSTEM_CACHE_INFORMATION;

typedef struct _SYSTEM_POOL_ENTRY
{
	BOOLEAN	Allocated;
	BOOLEAN	Spare0;
	USHORT	AllocatorBackTraceIndex;
	ULONG	Size;
	union
	{
		UCHAR	Tag[4];
		ULONG	TagUlong;
		PVOID	ProcessChargedQuota;
	};
} SYSTEM_POOL_ENTRY, *PSYSTEM_POOL_ENTRY;

typedef struct _SYSTEM_POOL_INFORMATION
{
	ULONG				TotalSize;
	PVOID				FirstEntry;
	USHORT				EntryOverhead;
	BOOLEAN				PoolTagPresent;
	BOOLEAN				Spare0;
	ULONG				NumberOfEntries;
	SYSTEM_POOL_ENTRY	Entries[1];
} SYSTEM_POOL_INFORMATION, *PSYSTEM_POOL_INFORMATION;

typedef struct _SYSTEM_POOL_TAG
{
	union
	{
		UCHAR	Tag[4];
		ULONG	TagUlong;
    };
	ULONG	PagedPoolAllocs;
	ULONG	PagedPoolFrees;
	ULONG	PagedPoolUsage;
	ULONG	NonPagedPoolAllocs;
	ULONG	NonPagedPoolFrees;
	ULONG	NonPagedPoolUsage;
} SYSTEM_POOL_TAG, *PSYSTEM_POOL_TAG;

typedef struct _SYSTEM_POOL_TAG_INFORMATION
{
	ULONG			uCount;
	SYSTEM_POOL_TAG	aSPT[];
} SYSTEM_POOL_TAG_INFORMATION, *PSYSTEM_POOL_TAG_INFORMATION;

typedef struct _SYSTEM_INTERRUPT_INFORMATION
{
	ULONG	ContextSwitches;
	ULONG	DpcCount;
	ULONG	DpcRate;
	ULONG	TimeIncrement;
	ULONG	DpcBypassCount;
	ULONG	ApcBypassCount;
} SYSTEM_INTERRUPT_INFORMATION, *PSYSTEM_INTERRUPT_INFORMATION;

typedef struct _SYSTEM_DPC_INFORMATION
{
	DWORD	dwUnknown1;
	ULONG	MaximumDpcQueueDepth;
	ULONG	MinimumDpcRate;
	ULONG	AdjustDpcThreshold;
	ULONG	IdealDpcRate;
} SYSTEM_DPC_INFORMATION, *PSYSTEM_DPC_INFORMATION;

typedef struct _SYSTEM_MEMORY_INFO
{
	PUCHAR	StringOffset;
	USHORT	ValidCount;
	USHORT	TransitionCount;
	USHORT	ModifiedCount;
	USHORT	PageTableCount;
} SYSTEM_MEMORY_INFO, *PSYSTEM_MEMORY_INFO;

typedef struct _SYSTEM_MEMORY_INFORMATION
{
	ULONG				InfoSize;
	ULONG				StringStart;
	SYSTEM_MEMORY_INFO	Memory[1];
} SYSTEM_MEMORY_INFORMATION, *PSYSTEM_MEMORY_INFORMATION;

typedef struct _SYSTEM_LOAD_DRIVER
{
	UNICODE_STRING			DriverName;			// input
	PVOID					BaseAddress;		// output
	PVOID					SectionPointer;		// output
	PVOID					EntryPoint;			// output
	PIMAGE_EXPORT_DIRECTORY	ExportDirectory;	// output
} SYSTEM_LOAD_DRIVER, *PSYSTEM_LOAD_DRIVER;

typedef struct _SYSTEM_UNLOAD_DRIVER
{
	PVOID	SectionPointer;
} SYSTEM_UNLOAD_DRIVER, *PSYSTEM_UNLOAD_DRIVER;

typedef struct _SYSTEM_QUERY_TIME_ADJUSTMENT
{
	ULONG	TimeAdjustment;
	ULONG	MaximumIncrement;
	BOOLEAN	TimeSynchronization;
} SYSTEM_QUERY_TIME_ADJUSTMENT, *PSYSTEM_QUERY_TIME_ADJUSTMENT;

typedef struct _SYSTEM_SET_TIME_ADJUSTMENT
{
	ULONG	TimeAdjustment;
	BOOLEAN	TimeSynchronization;
} SYSTEM_SET_TIME_ADJUSTMENT, *PSYSTEM_SET_TIME_ADJUSTMENT;

typedef struct _SYSTEM_CRASH_DUMP_INFORMATION
{
	HANDLE	CrashDumpSectionHandle;
} SYSTEM_CRASH_DUMP_INFORMATION, *PSYSTEM_CRASH_DUMP_INFORMATION;

typedef struct _SYSTEM_CRASH_DUMP_INFORMATION_2000
{
	HANDLE	CrashDumpSectionHandle;
	HANDLE	Unknown;				// Windows 2000 only
} SYSTEM_CRASH_DUMP_INFORMATION_2000, *PSYSTEM_CRASH_DUMP_INFORMATION_2000;

typedef struct _SYSTEM_EXCEPTION_INFORMATION
{
	ULONG	AlignmentFixupCount;
	ULONG	ExceptionDispatchCount;
	ULONG	FloatingEmulationCount;
	ULONG	ByteWordEmulationCount;
} SYSTEM_EXCEPTION_INFORMATION, *PSYSTEM_EXCEPTION_INFORMATION;

typedef struct _SYSTEM_CRASH_DUMP_STATE_INFORMATION
{
	ULONG	ValidCrashDump;
} SYSTEM_CRASH_DUMP_STATE_INFORMATION, *PSYSTEM_CRASH_DUMP_STATE_INFORMATION;

typedef struct _SYSTEM_CRASH_DUMP_STATE_INFORMATION_2000
{
	ULONG	ValidCrashDump;
	ULONG	Unknown;		// Windows 2000 only
} SYSTEM_CRASH_DUMP_STATE_INFORMATION_2000, *PSYSTEM_CRASH_DUMP_STATE_INFORMATION_2000;

typedef struct _SYSTEM_DEBUGGER_INFORMATION
{
	BOOLEAN	KernelDebuggerEnabled;
	BOOLEAN	KernelDebuggerNotPresent;
} SYSTEM_DEBUGGER_INFORMATION, *PSYSTEM_DEBUGGER_INFORMATION;

typedef struct _SYSTEM_CONTEXT_SWITCH_INFORMATION
{
	ULONG	ContextSwitches;
	ULONG	FindAny;
	ULONG	FindLast;
	ULONG	FindIdeal;
	ULONG	IdleAny;
	ULONG	IdleCurrent;
	ULONG	IdleLast;
	ULONG	IdleIdeal;
	ULONG	PreemptAny;
	ULONG	PreemptCurrent;
	ULONG	PreemptLast;
	ULONG	SwitchToIdle;
} SYSTEM_CONTEXT_SWITCH_INFORMATION, *PSYSTEM_CONTEXT_SWITCH_INFORMATION;

typedef struct _SYSTEM_REGISTRY_QUOTA_INFORMATION
{
	ULONG	RegistryQuotaAllowed;	// bytes
	ULONG	RegistryQuotaUsed;		// bytes
	ULONG	PagedPoolSize;			// bytes
} SYSTEM_REGISTRY_QUOTA_INFORMATION, *PSYSTEM_REGISTRY_QUOTA_INFORMATION;

typedef struct _SYSTEM_ADD_DRIVER
{
	UNICODE_STRING	ModuleName;
} SYSTEM_ADD_DRIVER, *PSYSTEM_ADD_DRIVER;

typedef struct _SYSTEM_PRIORITY_SEPARATION_INFORMATION
{
	ULONG	PrioritySeparation;		// 0..2
} SYSTEM_PRIORITY_SEPARATION_INFORMATION, *PSYSTEM_PRIORITY_SEPARATION_INFORMATION;

#define MAX_BUS_NAME	24

typedef enum _PLUGPLAY_BUS_CLASS
{
	SystemBus,
	PlugPlayVirtualBus,
	MaxPlugPlayBusClass
} PLUGPLAY_BUS_CLASS, *PPLUGPLAY_BUS_CLASS;

typedef enum _PLUGPLAY_VIRTUAL_BUS_TYPE
{
	Root,
	MaxPlugPlayVirtualBusType
} PLUGPLAY_VIRTUAL_BUS_TYPE, *PPLUGPLAY_VIRTUAL_BUS_TYPE;

typedef enum _INTERFACE_TYPE
{
	InterfaceTypeUndefined = -1,
	Internal,
	Isa,
	Eisa,
	MicroChannel,
	TurboChannel,
	PCIBus,
	VMEBus,
	NuBus,
	PCMCIABus,
	CBus,
	MPIBus,
	MPSABus,
	ProcessorInternal,
	InternalPowerBus,
	PNPISABus,
	PNPBus,
	MaximumInterfaceType
}INTERFACE_TYPE, *PINTERFACE_TYPE;

typedef struct _PLUGPLAY_BUS_TYPE
{
	PLUGPLAY_BUS_CLASS	BusClass;
	union
	{
		INTERFACE_TYPE				SystemBusType;
		PLUGPLAY_VIRTUAL_BUS_TYPE	PlugPlayVirtualBusType;
    };
} PLUGPLAY_BUS_TYPE, *PPLUGPLAY_BUS_TYPE;

typedef struct _PLUGPLAY_BUS_INSTANCE
{
	PLUGPLAY_BUS_TYPE	BusType;
	ULONG				BusNumber;
	WCHAR				BusName[MAX_BUS_NAME];
} PLUGPLAY_BUS_INSTANCE, *PPLUGPLAY_BUS_INSTANCE;

typedef struct _SYSTEM_PLUGPLAY_BUS_INFORMATION
{
	ULONG					BusCount;
	PLUGPLAY_BUS_INSTANCE	BusInstance[1];
} SYSTEM_PLUGPLAY_BUS_INFORMATION, *PSYSTEM_PLUGPLAY_BUS_INFORMATION;

typedef enum _SYSTEM_DOCK_STATE
{
	SystemDockStateUnknown,
	SystemUndocked,
	SystemDocked
} SYSTEM_DOCK_STATE, *PSYSTEM_DOCK_STATE;

typedef struct _SYSTEM_DOCK_INFORMATION
{
	SYSTEM_DOCK_STATE	DockState;
	INTERFACE_TYPE		DeviceBusType;
	ULONG				DeviceBusNumber;
	ULONG				SlotNumber;
} SYSTEM_DOCK_INFORMATION, *PSYSTEM_DOCK_INFORMATION;

typedef struct _SYSTEM_POWER_INFORMATION	// not for SystemPowerInfo !
{
	BOOLEAN			SystemSuspendSupported;
	BOOLEAN			SystemHibernateSupported;
	BOOLEAN			ResumeTimerSupportsSuspend;
	BOOLEAN			ResumeTimerSupportsHibernate;
	BOOLEAN			LidSupported;
	BOOLEAN			TurboSettingSupported;
	BOOLEAN			TurboMode;
	BOOLEAN			SystemAcOrDc;
	BOOLEAN			PowerDownDisabled;
	LARGE_INTEGER	SpindownDrives;
} SYSTEM_POWER_INFORMATION, *PSYSTEM_POWER_INFORMATION;

typedef struct _SYSTEM_PROCESSOR_SPEED_INFORMATION	// not for SystemProcessorSpeedInformation !
{
	ULONG	MaximumProcessorSpeed;
	ULONG	CurrentAvailableSpeed;
	ULONG	ConfiguredSpeedLimit;
	BOOLEAN	PowerLimit;
	BOOLEAN	ThermalLimit;
	BOOLEAN	TurboLimit;
} SYSTEM_PROCESSOR_SPEED_INFORMATION, *PSYSTEM_PROCESSOR_SPEED_INFORMATION;

typedef struct _SYSTEM_TIME_ZONE_INFORMATION
{
	LONG		Bias;
	WCHAR		StandardName[32];
	TIME_FIELDS	StandardDate;
	LONG		StandardBias;
	WCHAR		DaylightName[32];
	TIME_FIELDS	DaylightDate;
	LONG		DaylightBias;
} SYSTEM_TIME_ZONE_INFORMATION, *PSYSTEM_TIME_ZONE_INFORMATION;

typedef struct _SYSTEM_LOOKASIDE
{
	USHORT		Depth;
	USHORT		MaximumDepth;
	ULONG		TotalAllocates;
	ULONG		AllocateMisses;
	ULONG		TotalFrees;
	ULONG		FreeMisses;
	POOL_TYPE	Type;
	ULONG		Tag;
	ULONG		Size;
} SYSTEM_LOOKASIDE, *PSYSTEM_LOOKASIDE;

// typedef struct _SYSTEM_LOOKASIDE_INFORMATION
// {
// 	SYSTEM_LOOKASIDE	asl[];
// } SYSTEM_LOOKASIDE_INFORMATION, *PSYSTEM_LOOKASIDE_INFORMATION;

typedef struct _SYSTEM_SET_TIME_SLIP_EVENT
{
	HANDLE	TimeSlipEvent;
} SYSTEM_SET_TIME_SLIP_EVENT, *PSYSTEM_SET_TIME_SLIP_EVENT;

typedef struct _SYSTEM_CREATE_SESSION
{
	ULONG	Session;
} SYSTEM_CREATE_SESSION, *PSYSTEM_CREATE_SESSION;

typedef struct _SYSTEM_DELETE_SESSION
{
	ULONG	Session;
} SYSTEM_DELETE_SESSION, *PSYSTEM_DELETE_SESSION;

typedef struct _SYSTEM_RANGE_START_INFORMATION
{
	PVOID	SystemRangeStart;
} SYSTEM_RANGE_START_INFORMATION, *PSYSTEM_RANGE_START_INFORMATION;

NTSYSAPI
NTSTATUS
NTAPI
NtQuerySystemInformation(
	IN SYSTEMINFOCLASS	SystemInformationClass,
	OUT PVOID			pSystemInformation,
	IN ULONG			uSystemInformationLength,
    OUT PULONG			puReturnLength OPTIONAL
	);

NTSYSAPI
NTSTATUS
NTAPI
NtSetSystemInformation(
	IN SYSTEMINFOCLASS	SystemInformationClass,
	IN PVOID			pSystemInformation,
	IN ULONG			uSystemInformationLength
	);

// Time functions
NTSYSAPI
NTSTATUS
NTAPI
NtQuerySystemTime(
	OUT PLARGE_INTEGER	SystemTime
);

NTSYSAPI
NTSTATUS
NTAPI
NtSetSystemTime(
	IN PLARGE_INTEGER	NewTime,
	OUT PLARGE_INTEGER	OldTime OPTIONAL
);

NTSYSAPI
VOID
NTAPI
RtlTimeToTimeFields(
	IN PLARGE_INTEGER	pliTime,
	OUT PTIME_FIELDS	pTimeFields
);

NTSYSAPI
BOOLEAN
NTAPI
RtlTimeFieldsToTime(
	IN	PTIME_FIELDS	pTimeFields,
	OUT PLARGE_INTEGER	pliTime
);

NTSYSAPI
VOID
NTAPI
RtlSecondsSince1970ToTime(
    IN ULONG			SecondsSince1970,
    OUT PLARGE_INTEGER	Time
);

NTSYSAPI
VOID
NTAPI
RtlTimeToSecondsSince1970(
	IN PLARGE_INTEGER	Time,
	OUT PULONG			SecondsSince1970
);

// Event functions
NTSYSAPI
NTSTATUS
NTAPI
NtOpenEvent(
	PHANDLE				phEvent,
	ACCESS_MASK			AccessMask,
	POBJECT_ATTRIBUTES	pObjectAttributes
);

NTSYSAPI
NTSTATUS
NTAPI
NtClearEvent(
	IN HANDLE	hEvent
);

NTSYSAPI
NTSTATUS
NTAPI
NtSetEvent(
	IN HANDLE	hEvent,
	OUT PLONG	plSignaled OPTIONAL
);

NTSYSAPI
NTSTATUS
NTAPI
NtCreateSemaphore(
    OUT PHANDLE SemaphoreHandle,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes,
    IN LONG InitialCount,
    IN LONG MaximumCount
);

NTSYSAPI
NTSTATUS
NTAPI
NtOpenSemaphore(
    OUT PHANDLE SemaphoreHandle,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes
);

NTSYSAPI
NTSTATUS
NTAPI
NtReleaseSemaphore(
    IN HANDLE SemaphoreHandle,
    IN LONG ReleaseCount,
    OUT PLONG PreviousCount OPTIONAL
);

typedef enum _SEMAPHORE_INFORMATION_CLASS
{
	SemaphoreBasicInformation
} SEMAPHORE_INFORMATION_CLASS;

NTSYSAPI
NTSTATUS
NTAPI
NtQuerySemaphore(
    IN HANDLE SemaphoreHandle,
    IN SEMAPHORE_INFORMATION_CLASS SemaphoreInformationClass,
    OUT PVOID SemaphoreInformation,
    IN ULONG SemaphoreInformationLength,
    OUT PULONG ResultLength OPTIONAL
);

typedef struct _SEMAPHORE_BASIC_INFORMATION
{
	LONG CurrentCount;
	LONG MaximumCount;
} SEMAPHORE_BASIC_INFORMATION, *PSEMAPHORE_BASIC_INFORMATION;

// Directory and Symbolic Link functions
NTSYSAPI
NTSTATUS
NTAPI
NtCreateDirectoryObject(
	OUT PHANDLE				phDirectory,
	IN ACCESS_MASK			AccessMask,
	IN POBJECT_ATTRIBUTES	pObjectAttributes
);

NTSYSAPI
NTSTATUS
NTAPI
NtOpenDirectoryObject(
	OUT PHANDLE				DirectoryHandle,
	IN ACCESS_MASK			DesiredAccess,
	IN POBJECT_ATTRIBUTES	ObjectAttributes
);

typedef struct _DIRECTORY_CONTENTS
{
    struct
	{
        UNICODE_STRING Name;
        UNICODE_STRING Type;
    } Entry[ANYSIZE_ARRAY];
} DIRECTORY_CONTENTS, *PDIRECTORY_CONTENTS;

NTSYSAPI
NTSTATUS
NTAPI 
NtQueryDirectoryObject(
	IN HANDLE				DirectoryHandle,
	OUT PDIRECTORY_CONTENTS	Buffer,
	IN ULONG				Length,
	IN BOOLEAN				ReturnSingleEntry,
	IN BOOLEAN				RestartScan,
	IN OUT PULONG			Index,
	OUT PULONG				ResultLength OPTIONAL
);

NTSYSAPI
NTSTATUS
NTAPI
NtOpenSymbolicLinkObject(
	OUT PHANDLE				SymbolicLinkHandle,
	IN ACCESS_MASK			DesiredAccess,
	IN POBJECT_ATTRIBUTES	ObjectAttributes
);

NTSYSAPI
NTSTATUS
NTAPI
NtQuerySymbolicLinkObject(
	IN HANDLE			SymbolicLinkHandle,
	OUT PUNICODE_STRING	NameString,
	OUT PULONG			ResultLength OPTIONAL
);

// File functions
NTSYSAPI
NTSTATUS
NTAPI
NtCreateFile(
	PHANDLE				phFile,
	ACCESS_MASK			AccessMask,
	POBJECT_ATTRIBUTES	pObjectAttributes,
	PIO_STATUS_BLOCK	pIoStatusBlock,
	PLARGE_INTEGER		pliAllocationSize,
	ULONG				uFileAttributes,
	ULONG				uShareAccess,
	ULONG				uCreateDisposition,
	ULONG				uCreateOptions,
	PVOID				pEaBuffer,
	ULONG				uEaLength
);

NTSYSAPI
NTSTATUS
NTAPI
NtOpenFile(
	PHANDLE				phFile,
	ACCESS_MASK			AccessMask,

	POBJECT_ATTRIBUTES	pObjectAttributes,
	PIO_STATUS_BLOCK	pIoStatusBlock,
	ULONG				uShareAccess,
	ULONG				uOpenOptions
);

NTSYSAPI
NTSTATUS
NTAPI
NtDeleteFile(
	IN POBJECT_ATTRIBUTES	pObjectAttributes
);

typedef enum _FILE_INFORMATION_CLASS
{
    FileDirectoryInformation       = 1,
    FileFullDirectoryInformation   = 2,
    FileBothDirectoryInformation   = 3,
    FileBasicInformation,         // 4
    FileStandardInformation,      // 5
    FileInternalInformation,      // 6
    FileEaInformation,            // 7
    FileAccessInformation,        // 8
    FileNameInformation,          // 9
    FileRenameInformation,        // 10
    FileLinkInformation,          // 11
    FileNamesInformation		   = 12,
    FileDispositionInformation,   // 13
    FilePositionInformation,      // 14
    FileFullEaInformation,        // 15
    FileModeInformation,          // 16
    FileAlignmentInformation,     // 17
    FileAllInformation,           // 18
    FileAllocationInformation,    // 19
    FileEndOfFileInformation,     // 20
    FileAlternateNameInformation, // 21
    FileStreamInformation,        // 22
    FilePipeInformation,          // 23
    FilePipeLocalInformation,     // 24
    FilePipeRemoteInformation,    // 25
    FileMailslotQueryInformation, // 26
    FileMailslotSetInformation,   // 27
    FileCompressionInformation,   // 28
    FileObjectIdInformation,      // 29
    FileCompletionInformation,    // 30
    FileMoveClusterInformation,   // 31
    FileInformationReserved32,    // 32
    FileInformationReserved33,    // 33
    FileNetworkOpenInformation,   // 34
	FileIdBothDirectoryInformation = 37,
	FileIdFullDirectoryInformation, // 38
    FileMaximumInformation
} FILE_INFORMATION_CLASS, *PFILE_INFORMATION_CLASS;

NTSYSAPI
NTSTATUS
NTAPI
NtQueryDirectoryFile(
    IN HANDLE FileHandle,
    IN HANDLE Event OPTIONAL,
    IN PIO_APC_ROUTINE ApcRoutine OPTIONAL,
    IN PVOID ApcContext OPTIONAL,
    OUT PIO_STATUS_BLOCK IoStatusBlock,
    OUT PVOID FileInformation,
    IN ULONG FileInformationLength,
    IN FILE_INFORMATION_CLASS FileInformationClass,
    IN BOOLEAN ReturnSingleEntry,
    IN PUNICODE_STRING FileName OPTIONAL,
	IN BOOLEAN RestartScan
);

typedef struct _FILE_DIRECTORY_INFORMATION
{
    ULONG			NextEntryOffset;
    ULONG			FileIndex;
    LARGE_INTEGER	CreationTime;
    LARGE_INTEGER	LastAccessTime;
    LARGE_INTEGER	LastWriteTime;
    LARGE_INTEGER	ChangeTime;
    LARGE_INTEGER	EndOfFile;
    LARGE_INTEGER	AllocationSize;
    ULONG			FileAttributes;
    ULONG			FileNameLength;
    WCHAR			FileName[1];
} FILE_DIRECTORY_INFORMATION, *PFILE_DIRECTORY_INFORMATION;

typedef struct _FILE_FULL_DIR_INFORMATION
{
    ULONG			NextEntryOffset;
    ULONG			FileIndex;
    LARGE_INTEGER	CreationTime;
    LARGE_INTEGER	LastAccessTime;
    LARGE_INTEGER	LastWriteTime;
    LARGE_INTEGER	ChangeTime;
    LARGE_INTEGER	EndOfFile;
    LARGE_INTEGER	AllocationSize;
    ULONG			FileAttributes;
    ULONG			FileNameLength;
    ULONG			EaSize;
    WCHAR			FileName[1];
} FILE_FULL_DIR_INFORMATION, *PFILE_FULL_DIR_INFORMATION;

typedef struct _FILE_BOTH_DIR_INFORMATION
{
    ULONG			NextEntryOffset;
    ULONG			FileIndex;
    LARGE_INTEGER	CreationTime;
    LARGE_INTEGER	LastAccessTime;
    LARGE_INTEGER	LastWriteTime;
    LARGE_INTEGER	ChangeTime;
    LARGE_INTEGER	EndOfFile;
    LARGE_INTEGER	AllocationSize;
    ULONG			FileAttributes;
    ULONG			FileNameLength;
    ULONG			EaSize;
    CCHAR			ShortNameLength;
    WCHAR			ShortName[12];
    WCHAR			FileName[1];
} FILE_BOTH_DIR_INFORMATION, *PFILE_BOTH_DIR_INFORMATION;

 typedef struct _FILE_ID_BOTH_DIR_INFORMATION 
 {
    ULONG NextEntryOffset;
    ULONG Unknown;
    LARGE_INTEGER CreationTime;
    LARGE_INTEGER LastAccessTime;
    LARGE_INTEGER LastWriteTime;
    LARGE_INTEGER ChangeTime;
    LARGE_INTEGER EndOfFile;
    LARGE_INTEGER AllocationSize;
    ULONG FileAttributes;
    ULONG FileNameLength;
    ULONG EaInformationLength;
    USHORT AlternateNameLength;
	WCHAR AlternateName[12];
    LARGE_INTEGER FileId;
    WCHAR FileName[1];
} FILE_ID_BOTH_DIR_INFORMATION, *PFILE_ID_BOTH_DIR_INFORMATION;

typedef struct _FILE_BASIC_INFORMATION
{                    
    LARGE_INTEGER	CreationTime;                             
    LARGE_INTEGER	LastAccessTime;                           
    LARGE_INTEGER	LastWriteTime;                            
    LARGE_INTEGER	ChangeTime;                               
    ULONG			FileAttributes;                                   
} FILE_BASIC_INFORMATION, *PFILE_BASIC_INFORMATION;         

typedef struct _FILE_STANDARD_INFORMATION
{                 
    LARGE_INTEGER	AllocationSize;                           
    LARGE_INTEGER	EndOfFile;                                
    ULONG			NumberOfLinks;                                    
    BOOLEAN			DeletePending;                                  
    BOOLEAN			Directory;                                      
} FILE_STANDARD_INFORMATION, *PFILE_STANDARD_INFORMATION;   
                                                            
typedef struct _FILE_INTERNAL_INFORMATION
{
    LARGE_INTEGER	IndexNumber;
} FILE_INTERNAL_INFORMATION, *PFILE_INTERNAL_INFORMATION;

typedef struct _FILE_EA_INFORMATION
{
    ULONG	EaSize;
} FILE_EA_INFORMATION, *PFILE_EA_INFORMATION;

typedef struct _FILE_ACCESS_INFORMATION
{
    ACCESS_MASK	AccessFlags;
} FILE_ACCESS_INFORMATION, *PFILE_ACCESS_INFORMATION;

typedef struct _FILE_NAME_INFORMATION
{
//	ULONG   NextEntryOffset;
//    ULONG   Unknown;
    ULONG	FileNameLength;
    WCHAR	FileName[1];
} FILE_NAME_INFORMATION, *PFILE_NAME_INFORMATION;

typedef struct _FILE_RENAME_INFORMATION
{
    BOOLEAN	ReplaceIfExists;
    HANDLE	RootDirectory;
    ULONG	FileNameLength;
    WCHAR	FileName[1];
} FILE_RENAME_INFORMATION, *PFILE_RENAME_INFORMATION;

typedef struct _FILE_LINK_INFORMATION
{
    BOOLEAN	ReplaceIfExists;
    HANDLE	RootDirectory;
    ULONG	FileNameLength;
    WCHAR	FileName[1];
} FILE_LINK_INFORMATION, *PFILE_LINK_INFORMATION;

typedef struct _FILE_NAMES_INFORMATION
{
    ULONG	NextEntryOffset;
    ULONG	FileIndex;
    ULONG	FileNameLength;
    WCHAR	FileName[1];
} FILE_NAMES_INFORMATION, *PFILE_NAMES_INFORMATION;

typedef struct _FILE_ALLOCATION_INFORMATION
{
    LARGE_INTEGER	AllocationSize;
} FILE_ALLOCATION_INFORMATION, *PFILE_ALLOCATION_INFORMATION;

typedef struct _FILE_COMPRESSION_INFORMATION
{
    LARGE_INTEGER   CompressedFileSize;
    USHORT          CompressionFormat;
    UCHAR           CompressionUnitShift;
    UCHAR           ChunkShift;
    UCHAR           ClusterShift;
    UCHAR           Reserved[3];
} FILE_COMPRESSION_INFORMATION, *PFILE_COMPRESSION_INFORMATION;

typedef struct _FILE_COMPLETION_INFORMATION
{
    HANDLE  Port;
    ULONG   Key;
} FILE_COMPLETION_INFORMATION, *PFILE_COMPLETION_INFORMATION;

NTSYSAPI
NTSTATUS
NTAPI
NtQueryInformationFile(
    IN HANDLE					FileHandle,
    OUT PIO_STATUS_BLOCK		IoStatusBlock,
    OUT PVOID					FileInformation,
    IN ULONG					Length,
    IN FILE_INFORMATION_CLASS	FileInformationClass
);

NTSYSAPI
NTSTATUS

NTAPI
NtDeviceIoControlFile(
    IN HANDLE				FileHandle,
    IN HANDLE				Event OPTIONAL,
    IN PIO_APC_ROUTINE		ApcRoutine OPTIONAL,
    IN PVOID				ApcContext OPTIONAL,
    OUT PIO_STATUS_BLOCK	IoStatusBlock,
    IN ULONG				IoControlCode,
    IN PVOID				InputBuffer OPTIONAL,
    IN ULONG				InputBufferLength,
    OUT PVOID				OutputBuffer OPTIONAL,
    IN ULONG				OutputBufferLength
);

NTSYSAPI
NTSTATUS
NTAPI
NtFsControlFile(
    IN HANDLE				FileHandle,
    IN HANDLE				Event OPTIONAL,
    IN PIO_APC_ROUTINE		ApcRoutine OPTIONAL,
    IN PVOID				ApcContext OPTIONAL,
    OUT PIO_STATUS_BLOCK	IoStatusBlock,
    IN ULONG				FsControlCode,
    IN PVOID				InputBuffer OPTIONAL,
    IN ULONG				InputBufferLength,
    OUT PVOID				OutputBuffer OPTIONAL,
    IN ULONG				OutputBufferLength
);

NTSYSAPI
NTSTATUS
NTAPI
NtQueryVolumeInformationFile(
    IN HANDLE				FileHandle,
    OUT PIO_STATUS_BLOCK	IoStatusBlock,
    OUT PVOID				FsInformation,
    IN ULONG				Length,
    IN FS_INFORMATION_CLASS	FsInformationClass
);

NTSYSAPI
NTSTATUS
NTAPI
NtFlushBuffersFile(
    IN HANDLE				FileHandle,
    OUT PIO_STATUS_BLOCK	IoStatusBlock
);

// Process functions
#define NtCurrentProcess()				((HANDLE) -1)

NTSYSAPI
NTSTATUS
NTAPI
NtOpenProcess(
	OUT PHANDLE				phProcess,
	IN ACCESS_MASK			AccessMask,
	IN POBJECT_ATTRIBUTES	pObjectAttributes,
	IN PCLIENT_ID			pClientId
);

NTSYSAPI
NTSTATUS
NTAPI
NtCreateProcess(
    OUT PHANDLE ProcessHandle,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes,
    IN HANDLE InheritFromProcessHandle,
    IN BOOLEAN InheritHandles,
    IN HANDLE SectionHandle OPTIONAL,
    IN HANDLE DebugPort OPTIONAL,
    IN HANDLE ExceptionPort OPTIONAL
);

/*typedef enum _PROCESSINFOCLASS
{
	ProcessBasicInformation,
	ProcessQuotaLimits,			// QUOTA_LIMITS
	ProcessIoCounters,			// IOCOUNTERS
	ProcessVmCounters,			// VM_COUNTERS
	ProcessTimes,				// KERNEL_USER_TIMES
	ProcessBasePriority,		// BASE_PRIORITY_INFORMATION
	ProcessRaisePriority,
	ProcessDebugPort,
	ProcessExceptionPort,
	ProcessAccessToken,
	ProcessLdtInformation,
	ProcessLdtSize,
	ProcessDefaultHardErrorMode,
	ProcessIoPortHandlers,          // Note: this is kernel mode only
	ProcessPooledUsageAndLimits,
	ProcessWorkingSetWatch,
	ProcessUserModeIOPL,
	ProcessEnableAlignmentFaultFixup,
	ProcessPriorityClass,
	ProcessWx86Information,
	ProcessHandleCount,
	ProcessAffinityMask,		// AFFINITY_MASK
	ProcessPriorityBoost,
	ProcessDeviceMap,
    ProcessSessionInformation,
    ProcessForegroundInformation,
    ProcessWow64Information,
    ProcessImageFileName
} PROCESSINFOCLASS;*/

typedef enum _PROCESSINFOCLASS
{
	ProcessBasicInformation = 0, // 0, q: PROCESS_BASIC_INFORMATION, PROCESS_EXTENDED_BASIC_INFORMATION
	ProcessQuotaLimits, // qs: QUOTA_LIMITS, QUOTA_LIMITS_EX
	ProcessIoCounters, // q: IO_COUNTERS
	ProcessVmCounters, // q: VM_COUNTERS, VM_COUNTERS_EX
	ProcessTimes, // q: KERNEL_USER_TIMES
	ProcessBasePriority, // s: KPRIORITY
	ProcessRaisePriority, // s: ULONG
	ProcessDebugPort, // q: HANDLE
	ProcessExceptionPort, // s: HANDLE
	ProcessAccessToken, // s: PROCESS_ACCESS_TOKEN
	ProcessLdtInformation, // 10
	ProcessLdtSize,
	ProcessDefaultHardErrorMode, // qs: ULONG
	ProcessIoPortHandlers, // (kernel-mode only)
	ProcessPooledUsageAndLimits, // q: POOLED_USAGE_AND_LIMITS
	ProcessWorkingSetWatch, // q: PROCESS_WS_WATCH_INFORMATION[]; s: void
	ProcessUserModeIOPL,
	ProcessEnableAlignmentFaultFixup, // s: BOOLEAN
	ProcessPriorityClass, // qs: PROCESS_PRIORITY_CLASS
	ProcessWx86Information,
	ProcessHandleCount, // 20, q: ULONG, PROCESS_HANDLE_INFORMATION
	ProcessAffinityMask, // s: KAFFINITY
	ProcessPriorityBoost, // qs: ULONG
	ProcessDeviceMap, // qs: PROCESS_DEVICEMAP_INFORMATION, PROCESS_DEVICEMAP_INFORMATION_EX
	ProcessSessionInformation, // q: PROCESS_SESSION_INFORMATION
	ProcessForegroundInformation, // s: PROCESS_FOREGROUND_BACKGROUND
	ProcessWow64Information, // q: ULONG_PTR
	ProcessImageFileName, // q: UNICODE_STRING
	ProcessLUIDDeviceMapsEnabled, // q: ULONG
	ProcessBreakOnTermination, // qs: ULONG
	ProcessDebugObjectHandle, // 30, q: HANDLE
	ProcessDebugFlags, // qs: ULONG
	ProcessHandleTracing, // q: PROCESS_HANDLE_TRACING_QUERY; s: size 0 disables, otherwise enables
	ProcessIoPriority, // qs: ULONG
	ProcessExecuteFlags, // qs: ULONG
	ProcessResourceManagement,
	ProcessCookie, // q: ULONG
	ProcessImageInformation, // q: SECTION_IMAGE_INFORMATION
	ProcessCycleTime, // q: PROCESS_CYCLE_TIME_INFORMATION
	ProcessPagePriority, // q: ULONG
	ProcessInstrumentationCallback, // 40
	ProcessThreadStackAllocation, // s: PROCESS_STACK_ALLOCATION_INFORMATION, PROCESS_STACK_ALLOCATION_INFORMATION_EX
	ProcessWorkingSetWatchEx, // q: PROCESS_WS_WATCH_INFORMATION_EX[]
	ProcessImageFileNameWin32, // q: UNICODE_STRING
	ProcessImageFileMapping, // q: HANDLE (input)
	ProcessAffinityUpdateMode, // qs: PROCESS_AFFINITY_UPDATE_MODE
	ProcessMemoryAllocationMode, // qs: PROCESS_MEMORY_ALLOCATION_MODE
	ProcessGroupInformation, // q: USHORT[]
	ProcessTokenVirtualizationEnabled, // s: ULONG
	ProcessConsoleHostProcess, // q: ULONG_PTR
	ProcessWindowInformation, // 50, q: PROCESS_WINDOW_INFORMATION
	ProcessHandleInformation, // q: PROCESS_HANDLE_SNAPSHOT_INFORMATION // since WIN8
	ProcessMitigationPolicy, // s: PROCESS_MITIGATION_POLICY_INFORMATION
	ProcessDynamicFunctionTableInformation,
	ProcessHandleCheckingMode,
	ProcessKeepAliveCount, // q: PROCESS_KEEPALIVE_COUNT_INFORMATION
	ProcessRevokeFileHandles, // s: PROCESS_REVOKE_FILE_HANDLES_INFORMATION
	MaxProcessInfoClass
} PROCESSINFOCLASS;

typedef struct _PROCESS_BASIC_INFORMATION
{
	NTSTATUS	ExitStatus;
	PPEB		PebBaseAddress;
	KAFFINITY	AffinityMask;
	KPRIORITY	BasePriority;
	ULONG		uUniqueProcessId;
	ULONG		uInheritedFromUniqueProcessId;
} PROCESS_BASIC_INFORMATION, *PPROCESS_BASIC_INFORMATION;

typedef struct _PROCESS_RAISE_PRIORITY
{
	KPRIORITY	RaisePriority;
} PROCESS_RAISE_PRIORITY, *PPROCESS_RAISE_PRIORITY;

typedef struct _PROCESS_DEBUG_PORT_INFORMATION
{
	HANDLE	DebugPort;
} PROCESS_DEBUG_PORT_INFORMATION, *PPROCESS_DEBUG_PORT_INFORMATION;

typedef struct _PROCESS_EXCEPTION_PORT
{
	HANDLE	ExceptionPort;
} PROCESS_EXCEPTION_PORT, *PPROCESS_EXCEPTION_PORT;

typedef struct _PROCESS_ACCESS_TOKEN
{
	HANDLE	Token;
	HANDLE	Thread;
} PROCESS_ACCESS_TOKEN, *PPROCESS_ACCESS_TOKEN;

#ifndef _LDT_ENTRY_DEFINED
#define _LDT_ENTRY_DEFINED

typedef struct _LDT_ENTRY
{
    USHORT	LimitLow;
    USHORT	BaseLow;
    union
	{
        struct
		{
            UCHAR	BaseMid;
            UCHAR	Flags1;     // Declare as bytes to avoid alignment
            UCHAR	Flags2;     // Problems.
            UCHAR	BaseHi;
        } Bytes;

        struct
		{
            ULONG	BaseMid : 8;
            ULONG	Type : 5;
            ULONG	Dpl : 2;
            ULONG	Pres : 1;
            ULONG	LimitHi : 4;
            ULONG	Sys : 1;
            ULONG	Reserved_0 : 1;
            ULONG	Default_Big : 1;
            ULONG	Granularity : 1;
            ULONG	BaseHi : 8;
        } Bits;
    } HighWord;
} LDT_ENTRY, *PLDT_ENTRY;

#endif

#define LDT_TABLE_SIZE  (8 * 1024 * sizeof(LDT_ENTRY))

typedef struct _LDT_INFORMATION
{
    ULONG		Start;
    ULONG		Length;
    LDT_ENTRY	LdtEntries[1];
} PROCESS_LDT_INFORMATION, *PPROCESS_LDT_INFORMATION;

typedef struct _LDT_SIZE
{
	ULONG	Length;
} PROCESS_LDT_SIZE, *PPROCESS_LDT_SIZE;

typedef struct _PROCESS_DEFAULT_HARDERROR_MODE_INFORMATION
{
	ULONG	HardErrorMode;	// SEM_* (SEM_FAILCRITICALERRORS, etc.)
} PROCESS_DEFAULT_HARDERROR_MODE_INFORMATION, *PPROCESS_DEFAULT_HARDERROR_MODE_INFORMATION;

typedef struct _PROCESS_POOLED_USAGE_AND_LIMITS_INFORMATION
{
	ULONG	PeakPagedPoolUsage;
	ULONG	PagedPoolUsage;
	ULONG	PagedPoolLimit;
	ULONG	PeakNonPagedPoolUsage;
	ULONG	NonPagedPoolUsage;
	ULONG	NonPagedPoolLimit;
	ULONG	PeakPagefileUsage;
	ULONG	PagefileUsage;
	ULONG	PagefileLimit;
} PROCESS_POOLED_USAGE_AND_LIMITS_INFORMATION, *PPROCESS_POOLED_USAGE_AND_LIMITS_INFORMATION;

typedef struct _PROCESS_WS_WATCH_INFORMATION
{
	PVOID	FaultingPc;
	PVOID	FaultingVa;
} PROCESS_WS_WATCH_INFORMATION, *PPROCESS_WS_WATCH_INFORMATION;

typedef struct _PROCESS_IOPL
{
	ULONG	Iopl;
} PROCESS_IOPL, *PPROCESS_IOPL;

typedef struct _PROCESS_ALLIGNMENT_FAULT_FIXUP
{
	BOOLEAN	EnableAllignmentFaultFixup;
} PROCESS_ALLIGNMENT_FAULT_FIXUP, *PPROCESS_ALLIGNMENT_FAULT_FIXUP;

#define KRNL_NORMAL_PRIORITY_CLASS       0x02
#define KRNL_IDLE_PRIORITY_CLASS         0x01
#define KRNL_HIGH_PRIORITY_CLASS         0x03
#define KRNL_REALTIME_PRIORITY_CLASS     0x04

typedef struct _PROCESS_PRIORITY_CLASS_INFORMATION
{
	UCHAR	Unknown;
	UCHAR	PriorityClass;
} PROCESS_PRIORITY_CLASS_INFORMATION, *PPROCESS_PRIORITY_CLASS_INFORMATION;

typedef struct _PROCESS_X86_INFORMATION
{
	ULONG	x86Info;
} PROCESS_X86_INFORMATION, *PPROCESS_X86_INFORMATION;

typedef struct _PROCESS_HANDLE_COUNT_INFORMATION
{
	ULONG	HandleCount;
} PROCESS_HANDLE_COUNT_INFORMATION, *PPROCESS_HANDLE_COUNT_INFORMATION;

typedef struct _PROCESS_PRIORITY_BOOST_INFORMATION
{
	ULONG	PriorityBoostEnabled;
} PROCESS_PRIORITY_BOOST_INFORMATION, *PPROCESS_PRIORITY_BOOST_INFORMATION;

typedef struct _PROCESS_DEVICE_MAP_INFORMATION
{
    union
	{
        struct
		{
            HANDLE	DirectoryHandle;
        } Set;

        struct
		{
            ULONG	DriveMap;
            UCHAR	DriveType[32];
        } Query;
    };

} PROCESS_DEVICE_MAP_INFORMATION, *PPROCESS_DEVICE_MAP_INFORMATION;

typedef struct _PROCESS_SESSION_INFORMATION
{
    ULONG	SessionId;
} PROCESS_SESSION_INFORMATION, *PPROCESS_SESSION_INFORMATION;

NTSYSAPI
NTSTATUS
NTAPI
NtQueryInformationProcess(
    IN HANDLE			hProcess,
    IN PROCESSINFOCLASS	ProcessInformationClass,
    OUT PVOID			pProcessInformation,
    IN ULONG			uProcessInformationLength,
    OUT PULONG			puReturnLength OPTIONAL
);

NTSYSAPI
NTSTATUS
NTAPI
NtSetInformationProcess(
    IN HANDLE			hProcess,
    IN PROCESSINFOCLASS	ProcessInformationClass,
    OUT PVOID			pProcessInformation,
    IN ULONG			uProcessInformationLength
);

NTSTATUS
NTAPI
RtlCreateProcessParameters(
    OUT PPROCESS_PARAMETERS *ProcessParameters,
    IN PUNICODE_STRING ImageFile,
    IN PUNICODE_STRING DllPath OPTIONAL,
    IN PUNICODE_STRING CurrentDirectory OPTIONAL,
    IN PUNICODE_STRING CommandLine OPTIONAL,
    IN ULONG CreationFlags,
    IN PUNICODE_STRING WindowTitle OPTIONAL,
    IN PUNICODE_STRING Desktop OPTIONAL,
    IN PUNICODE_STRING Reserved OPTIONAL,
    IN PUNICODE_STRING Reserved2 OPTIONAL
);

NTSTATUS
NTAPI
RtlDestroyProcessParameters(
    IN PPROCESS_PARAMETERS ProcessParameters
);

// Thread functions
#define NtCurrentThread()				((HANDLE) -2)

typedef struct _USER_STACK
{
	PVOID	FixedStackBase;
	PVOID	FixedStackLimit;
	PVOID	ExpandableStackBase;
	PVOID	ExpandableStackLimit;
	PVOID	ExpandableStackBottom;
} USER_STACK, *PUSER_STACK;

NTSYSAPI
NTSTATUS
NTAPI
NtCreateThread(
    OUT PHANDLE				ThreadHandle,
    IN ACCESS_MASK			DesiredAccess,
    IN POBJECT_ATTRIBUTES	ObjectAttributes,
    IN HANDLE				ProcessHandle,
    OUT PCLIENT_ID			ClientId,
    IN PCONTEXT				ThreadContext,
    IN PUSER_STACK			UserStack,
    IN BOOLEAN				CreateSuspended
);

NTSYSAPI
NTSTATUS
NTAPI
NtOpenThread(
	OUT PHANDLE				phThread,
	IN ACCESS_MASK			AccessMask,
	IN POBJECT_ATTRIBUTES	pObjectAttributes,
	IN PCLIENT_ID			pClientId
);

NTSYSAPI
NTSTATUS
NTAPI
NtTerminateThread(
    IN HANDLE	ThreadHandle OPTIONAL,
    IN NTSTATUS	ExitStatus
);

NTSYSAPI
NTSTATUS
NTAPI
NtSuspendThread(
    IN HANDLE	ThreadHandle,
    OUT PULONG	PreviousSuspendCount OPTIONAL
);

NTSYSAPI
NTSTATUS
NTAPI
NtResumeThread(
    IN HANDLE	ThreadHandle,
    OUT PULONG	PreviousSuspendCount OPTIONAL
);

typedef enum _THREADINFOCLASS
{
	ThreadBasicInformation,
	ThreadTimes,				// KERNEL_USER_TIMES
	ThreadPriority,
	ThreadBasePriority,			// BASE_PRIORITY_INFORMATION
	ThreadAffinityMask,			// AFFINITY_MASK
	ThreadImpersonationToken,
	ThreadDescriptorTableEntry,
	ThreadEnableAlignmentFaultFixup,
	ThreadEventPair,
	ThreadQuerySetWin32StartAddress,
	ThreadZeroTlsCell,
	ThreadPerformanceCount,
	ThreadAmILastThread,
	ThreadIdealProcessor,
	ThreadPriorityBoost,
	ThreadSetTlsArrayAddress,
	ThreadIsIoPending,			// W2K
	ThreadHideFromDebugger,		// W2K
	MaxThreadInfoClass
} THREADINFOCLASS;

typedef struct _THREAD_BASIC_INFORMATION
{
    NTSTATUS	ExitStatus;
    PTEB		TebBaseAddress;
    CLIENT_ID	ClientId;
    KAFFINITY	AffinityMask;
    KPRIORITY	Priority;
    KPRIORITY	BasePriority;
} THREAD_BASIC_INFORMATION, *PTHREAD_BASIC_INFORMATION;

typedef struct _THREAD_PRIORITY
{
	KPRIORITY	Priority;
} THREAD_PRIORITY, *PTHREAD_PRIORITY;

typedef struct _THREAD_DESCRIPTOR_TABLE_ENTRY_INFORMATION
{
    ULONG		Selector;
    LDT_ENTRY	Descriptor;
} THREAD_DESCRIPTOR_TABLE_ENTRY_INFORMATION, *PTHREAD_DESCRIPTOR_TABLE_ENTRY_INFORMATION;

typedef struct _THREAD_EVENTPAIR
{
	HANDLE	EventPair;
} THREAD_EVENTPAIR, *PTHREAD_EVENTPAIR;

typedef struct _THREAD_WIN32_START_ADDRESS_INFORMATION
{
	PVOID	Win32StartAddress;
} THREAD_WIN32_START_ADDRESS_INFORMATION, *PTHREAD_WIN32_START_ADDRESS_INFORMATION;

typedef struct _THREAD_ZERO_TLSCELL
{
	ULONG	TlsIndex;
} THREAD_ZERO_TLSCELL, *PTHREAD_ZERO_TLSCELL;

typedef struct _THREAD_PERFORMANCE_COUNTER_INFORMATION
{
	ULONG	Count1;
	ULONG	Count2;
} THREAD_PERFORMANCE_COUNTER_INFORMATION, *PTHREAD_PERFORMANCE_COUNTER_INFORMATION;

typedef struct _THREAD_AMI_LAST_THREAD
{
	ULONG	AmILastThread;
} THREAD_AMI_LAST_THREAD, *PTHREAD_AMI_LAST_THREAD;

typedef struct _THREAD_IDEAL_PROCESSOR
{
	ULONG	IdealProcessor;
} THREAD_IDEAL_PROCESSOR, *PTHREAD_IDEAL_PROCESSOR;

typedef struct _THREAD_TLS_ARRAY
{
	PULONG	TlsArray;
} THREAD_TLS_ARRAY, *PTHREAD_TLS_ARRAY;

typedef struct _THREAD_IS_IO_PENDING_INFORMATION
{
	ULONG	IsIOPending;
} THREAD_IS_IO_PENDING_INFORMATION, *PTHREAD_IS_IO_PENDING_INFORMATION;

typedef struct _THREAD_HIDE_FROM_DEBUGGER
{
	ULONG	HideFromDebugger;
} THREAD_HIDE_FROM_DEBUGGER, *PTHREAD_HIDE_FROM_DEBUGGER;

typedef enum _SECTION_INHERIT {
    ViewShare=1,
    ViewUnmap=2
} SECTION_INHERIT, *PSECTION_INHERIT;


NTSYSAPI
NTSTATUS
NTAPI
NtQueryInformationThread(
    IN HANDLE			hThread,
    IN THREADINFOCLASS	ThreadInformationClass,
    OUT PVOID			pThreadInformation,
    IN ULONG			uThreadInformationLength,
    OUT PULONG			puReturnLength OPTIONAL
);

NTSYSAPI
NTSTATUS
NTAPI
NtSetInformationThread(
	IN HANDLE			hThread,
	IN THREADINFOCLASS	ThreadInformationClass,
	OUT PVOID			pThreadInformation,
	IN ULONG			uthreadInformationLength
);

NTSYSAPI
NTSTATUS
NTAPI
NtOpenThreadToken(
	IN HANDLE	hThread,
	IN ACCESS_MASK	DesiredAccess,
	IN BOOLEAN		bOpenAsSelf,
	OUT PHANDLE		phToken
);

NTSYSAPI
NTSTATUS
NTAPI
NtImpersonateThread(
    IN HANDLE						ThreadHandle,
    IN HANDLE						TargetThreadHandle,
    IN PSECURITY_QUALITY_OF_SERVICE	SecurityQos
);

NTSYSAPI
NTSTATUS
NTAPI
NtGetContextThread(
    IN HANDLE		ThreadHandle,
    OUT PCONTEXT	Context
);

NTSYSAPI
NTSTATUS
NTAPI
NtSetContextThread(
    IN HANDLE	ThreadHandle,
    IN PCONTEXT	Context
);

NTSYSAPI
NTSTATUS
NTAPI
NtQueueApcThread(
    IN HANDLE			ThreadHandle,
    IN PKNORMAL_ROUTINE	ApcRoutine,
    IN PVOID ApcContext	OPTIONAL,
    IN PVOID Argument1	OPTIONAL,
    IN PVOID Argument2	OPTIONAL
);

NTSYSAPI
NTSTATUS
NTAPI
NtImpersonateAnonymousToken(
	IN HANDLE	hThread
);

NTSYSAPI
NTSTATUS
NTAPI
NtCreateSection(
    OUT PHANDLE SectionHandle,
    IN ACCESS_MASK DesiredAccess,
    IN POBJECT_ATTRIBUTES ObjectAttributes,
    IN PLARGE_INTEGER SectionSize OPTIONAL,
    IN ULONG Protect,
    IN ULONG Attributes,
    IN HANDLE FileHandle
);

NTSYSAPI
NTSTATUS
NTAPI
NtOpenSection(
	OUT PHANDLE				SectionHandle,
	IN ACCESS_MASK			DesiredAccess,
	IN POBJECT_ATTRIBUTES	ObjectAttributes
);

NTSYSAPI
NTSTATUS
NTAPI
NtMapViewOfSection (
    IN HANDLE SectionHandle,
    IN HANDLE ProcessHandle,
    IN OUT PVOID *BaseAddress,
    IN ULONG ZeroBits,
    IN ULONG CommitSize,
    IN OUT PLARGE_INTEGER SectionOffset OPTIONAL,
    IN OUT PULONG_PTR ViewSize,
    IN SECTION_INHERIT InheritDisposition,
    IN ULONG AllocationType,
    IN ULONG Protect
);

typedef enum _SECTION_INFORMATION_CLASS
{
	SectionBasicInformation,
	SectionImageInformation
} SECTION_INFORMATION_CLASS;

NTSYSAPI
NTSTATUS
NTAPI
NtQuerySection(
    IN HANDLE SectionHandle,
    IN SECTION_INFORMATION_CLASS SectionInformationClass,
    OUT PVOID SectionInformation,
    IN ULONG SectionInformationLength,
    OUT PULONG ResultLength OPTIONAL
);

typedef struct _SECTION_BASIC_INFORMATION
{
	PVOID			BaseAddress;
	ULONG			Attributes;
	LARGE_INTEGER	Size;
} SECTION_BASIC_INFORMATION, *PSECTION_BASIC_INFORMATION;

typedef struct _SECTION_IMAGE_INFORMATION
{
	PVOID	EntryPoint;
	ULONG	Unknown1;
	ULONG	StackReserve;
	ULONG	StackCommit;
	ULONG	Subsystem;
	USHORT	MinorSubsystemVersion;
	USHORT	MajorSubsystemVersion;
	ULONG	Unknown2;
	ULONG	Characteristics;
	USHORT	ImageNumber;
	BOOLEAN	Executable;
	UCHAR	Unknown3;
	ULONG	Unknown4[3];
} SECTION_IMAGE_INFORMATION, *PSECTION_IMAGE_INFORMATION;

NTSYSAPI
NTSTATUS
NTAPI
NtExtendSection(
	IN HANDLE SectionHandle,
	IN PLARGE_INTEGER SectionSize
);

NTSYSAPI
NTSTATUS
NTAPI
NtUnmapViewOfSection(
	IN HANDLE	hProcess,
	IN PVOID	pBaseAddress
);

NTSYSAPI
NTSTATUS
NTAPI
NtWaitForSingleObject(
	IN HANDLE			hObject,
	IN BOOL				fAlertable,
	IN PLARGE_INTEGER	pliTimeout   // NULL = infinite
);

// Object functions
typedef enum _OBJECT_INFORMATION_CLASS
{
	ObjectBasicInformation,             // 0    Y       N
	ObjectNameInformation,              // 1    Y       N
	ObjectTypeInformation,              // 2    Y       N
	ObjectAllTypesInformation,          // 3    Y       N
	ObjectHandleInformation             // 4    Y       Y
} OBJECT_INFORMATION_CLASS;

typedef struct _OBJECT_BASIC_INFORMATION
{
	ULONG			Attributes;
	ACCESS_MASK		GrantedAccess;
	ULONG			HandleCount;
	ULONG			PointerCount;
	ULONG			PagedPoolUsage;
	ULONG			NonPagedPoolUsage;
	ULONG			Reserved[3];
	ULONG			NameInformationLength;
	ULONG			TypeInformationLength;
	ULONG			SecurityDescriptorLength;
	LARGE_INTEGER	CreateTime;
} OBJECT_BASIC_INFORMATION, *POBJECT_BASIC_INFORMATION;

typedef struct _OBJECT_NAME_INFORMATION
{               
	UNICODE_STRING	Name;                                
} OBJECT_NAME_INFORMATION, *POBJECT_NAME_INFORMATION;   

typedef struct _OBJECT_TYPE_INFORMATION
{
	UNICODE_STRING	Name;
	ULONG			ObjectCount;
	ULONG			HandleCount;
	ULONG			Reserved1[4];
	ULONG			PeakObjectCount;
	ULONG			PeakHandleCount;
	ULONG			Reserved2[4];
	ULONG			InvalidAttributes;
	GENERIC_MAPPING	GenericMapping;
	ULONG			ValidAccess;
	UCHAR			Unknown;
	BOOLEAN			MaintainHandleDatabase;
	UCHAR			Reserved3[2];
	POOL_TYPE		PoolType;
	ULONG			PagedPoolUsage;
	ULONG			NonPagedPoolUsage;
} OBJECT_TYPE_INFORMATION, *POBJECT_TYPE_INFORMATION;

typedef struct _OBJECT_ALL_TYPES_INFORMATION
{
	ULONG					NumberOfTypes;
	OBJECT_TYPE_INFORMATION	TypeInformation;
} OBJECT_ALL_TYPES_INFORMATION, *POBJECT_ALL_TYPES_INFORMATION;

typedef struct _OBJECT_HANDLE_ATTRIBUTE_INFORMATION
{
	BOOLEAN	Inherit;
	BOOLEAN	ProtectFromClose;
} OBJECT_HANDLE_ATTRIBUTE_INFORMATION, *POBJECT_HANDLE_ATTRIBUTE_INFORMATION;

NTSYSAPI
NTSTATUS
NTAPI
NtQueryObject(
	IN HANDLE ObjectHandle,
	IN OBJECT_INFORMATION_CLASS ObjectInformationClass,
	OUT PVOID ObjectInformation,
	IN ULONG ObjectInformationLength,
	OUT PULONG ReturnLength OPTIONAL
);

NTSYSAPI
NTSTATUS
NTAPI
NtSetInformationObject(
	IN HANDLE ObjectHandle,
	IN OBJECT_INFORMATION_CLASS ObjectInformationClass,
	IN PVOID ObjectInformation,
	IN ULONG ObjectInformationLength
);

NTSYSAPI
NTSTATUS
NTAPI
NtDuplicateObject(
	IN HANDLE SourceProcessHandle,
	IN HANDLE SourceHandle,
	IN HANDLE TargetProcessHandle OPTIONAL,
	OUT PHANDLE TargetHandle OPTIONAL,
	IN ACCESS_MASK DesiredAccess,
	IN ULONG HandleAttributes,
	IN ULONG Options
);

NTSYSAPI
NTSTATUS
NTAPI
NtQuerySecurityObject(
	IN HANDLE FileHandle,
	IN SECURITY_INFORMATION SecurityInformation,
	OUT PSECURITY_DESCRIPTOR SecurityDescriptor,
	IN ULONG Length,
	OUT PULONG ResultLength
);

NTSYSAPI
NTSTATUS
NTAPI
NtSetSecurityObject(
	IN HANDLE FileHandle,
	IN SECURITY_INFORMATION SecurityInformation,
	IN PSECURITY_DESCRIPTOR SecurityDescriptor
);

// Memory management functions
NTSYSAPI
NTSTATUS
NTAPI
NtAllocateVirtualMemory(
	IN HANDLE ProcessHandle,
	IN OUT PVOID *BaseAddress,
	IN ULONG ZeroBits,
	IN OUT PULONG AllocationSize,
	IN ULONG AllocationType,
	IN ULONG Protect
);

typedef enum _MEMORY_INFORMATION_CLASS
{
	MemoryBasicInformation,
	MemoryWorkingSetList,
	MemorySectionName,
	MemoryBasicVlmInformation
} MEMORY_INFORMATION_CLASS;

NTSYSAPI
NTSTATUS
NTAPI
NtQueryVirtualMemory(
	IN HANDLE ProcessHandle,
	IN PVOID BaseAddress,
	IN MEMORY_INFORMATION_CLASS MemoryInformationClass,
	OUT PVOID MemoryInformation,
	IN ULONG MemoryInformationLength,
	OUT PULONG ReturnLength OPTIONAL
);

/* Defined in Winnt.h
typedef struct _MEMORY_BASIC_INFORMATION
{
	PVOID	BaseAddress;
	PVOID	AllocationBase;
	ULONG	AllocationProtect;
	ULONG	RegionSize;
	ULONG	State;
	ULONG	Protect;
	ULONG	Type;
} MEMORY_BASIC_INFORMATION, *PMEMORY_BASIC_INFORMATION;
*/

typedef struct _MEMORY_WORKING_SET_LIST
{
	ULONG	NumberOfPages;
	ULONG	WorkingSetList[1];
} MEMORY_WORKING_SET_LIST, *PMEMORY_WORKING_SET_LIST;

typedef struct _MEMORY_SECTION_NAME
{
	UNICODE_STRING	SectionFileName;
} MEMORY_SECTION_NAME, *PMEMORY_SECTION_NAME;

NTSYSAPI
NTSTATUS
NTAPI
NtReadVirtualMemory(
	IN HANDLE ProcessHandle,
	IN PVOID BaseAddress,
	OUT PVOID Buffer,
	IN ULONG BufferLength,
	OUT PULONG ReturnLength OPTIONAL
);

NTSYSAPI
NTSTATUS
NTAPI
NtWriteVirtualMemory(
	IN HANDLE ProcessHandle,
	IN PVOID BaseAddress,
	IN PVOID Buffer,
	IN ULONG BufferLength,
	OUT PULONG ReturnLength OPTIONAL
);

NTSYSAPI
NTSTATUS
NTAPI
NtProtectVirtualMemory(
    IN HANDLE ProcessHandle,
    IN OUT PVOID *BaseAddress,
    IN OUT PULONG ProtectSize,
    IN ULONG NewProtect,
    OUT PULONG OldProtect
);

NTSYSAPI
NTSTATUS
NTAPI
NtFlushVirtualMemory(
    IN HANDLE ProcessHandle,
    IN OUT PVOID *BaseAddress,
    IN OUT PULONG FlushSize,
    OUT PIO_STATUS_BLOCK IoStatusBlock
);

// Ldr Functions
NTSYSAPI
NTSTATUS
NTAPI
LdrDisableThreadCalloutsForDll(
	IN HANDLE hModule
);

// Rtl String Functions
NTSYSAPI
VOID
NTAPI
RtlInitUnicodeString (
    OUT PUNICODE_STRING DestinationString,
    IN PCWSTR SourceString
    );

NTSYSAPI
VOID
NTAPI
RtlCreateUnicodeString(
    OUT PUNICODE_STRING AllocatedString,
    IN PCWSTR SourceString
    );

NTSYSAPI
VOID
NTAPI
RtlFreeUnicodeString(
    IN PUNICODE_STRING UnicodeString
    );

NTSYSAPI
ULONG
NTAPI
RtlAnsiStringToUnicodeSize(
    IN PANSI_STRING AnsiString
    );

NTSYSAPI
NTSTATUS
NTAPI
RtlAnsiStringToUnicodeString(
    OUT PUNICODE_STRING DestinationString,
    IN PANSI_STRING SourceString,
    IN BOOLEAN AllocateDestinationString
    );

NTSYSAPI
NTSTATUS
NTAPI
RtlAppendUnicodeStringToString(
    OUT PUNICODE_STRING Destination,
    IN PUNICODE_STRING Source
    );

NTSYSAPI
NTSTATUS
NTAPI
RtlAppendUnicodeToString(
    OUT PUNICODE_STRING Destination,
    IN PWSTR Source
    );

NTSYSAPI
LONG
NTAPI
RtlCompareUnicodeString(
    IN PUNICODE_STRING String1,
    IN PUNICODE_STRING String2,
    IN BOOLEAN CaseInSensitive
    );

NTSYSAPI
VOID
NTAPI
RtlCopyUnicodeString(
    OUT PUNICODE_STRING DestinationString,
    IN PUNICODE_STRING SourceString
    );

NTSYSAPI
NTSTATUS
NTAPI
RtlDowncaseUnicodeString(
    OUT PUNICODE_STRING DestinationString,
    IN PUNICODE_STRING SourceString,
    IN BOOLEAN AllocateDestinationString
    );

NTSYSAPI
BOOLEAN
NTAPI
RtlEqualUnicodeString(
    IN PUNICODE_STRING String1,
    IN PUNICODE_STRING String2,
    IN BOOLEAN CaseInSensitive
    );

NTSYSAPI
NTSTATUS
NTAPI
RtlIntegerToUnicodeString(
    IN ULONG Value,
    IN ULONG Base,
    OUT PUNICODE_STRING String
    );

NTSYSAPI
NTSTATUS
NTAPI
RtlUnicodeStringToInteger(
    IN PUNICODE_STRING String,
    IN ULONG Base,
    OUT PULONG Value
    );

NTSYSAPI
NTSTATUS
NTAPI
RtlOemStringToUnicodeString(
    OUT PUNICODE_STRING DestinationString,
    IN POEM_STRING SourceString,
    IN BOOLEAN AllocateDestinationString
    );

NTSYSAPI
BOOLEAN
NTAPI
RtlPrefixUnicodeString(
    IN PUNICODE_STRING String1,
    IN PUNICODE_STRING String2,
    IN BOOLEAN CaseInSensitive
    );

NTSYSAPI
WCHAR
NTAPI
RtlUpcaseUnicodeChar(
    IN WCHAR SourceCharacter
    );

NTSYSAPI
NTSTATUS
NTAPI
RtlUpcaseUnicodeString(
    OUT PUNICODE_STRING DestinationString,
    IN PUNICODE_STRING SourceString,
    IN BOOLEAN AllocateDestinationString
    );

NTSYSAPI
ULONG
NTAPI
RtlxAnsiStringToUnicodeSize(
    IN PANSI_STRING AnsiString
    );

NTSYSAPI
ULONG
NTAPI
RtlxOemStringToUnicodeSize(
    IN POEM_STRING OemString
    );

// Rtl Misc Operations
NTSYSAPI
NTSTATUS
NTAPI
NtReplyPort(
	IN HANDLE	hPort,
	OUT PVOID	pReply
);

NTSYSAPI
NTSTATUS
NTAPI
NtClose(
	IN HANDLE	hObject
);

NTSYSAPI
ULONG
NTAPI
RtlNtStatusToDosError(
	NTSTATUS	status
);

NTSYSAPI
UINT
NTAPI
RtlGetLongestNtPathLength();

NTSYSAPI
UINT
NTAPI
RtlDetermineDosPathNameType_U(
	IN PWSTR	Path
);

NTSYSAPI
UINT
NTAPI
RtlIsDosDeviceName_U(
	IN PWSTR	Path
);

NTSYSAPI
BOOLEAN
NTAPI
RtlDosPathNameToNtPathName_U(
    IN PCWSTR			DosName,
    OUT PUNICODE_STRING	NtName,
    OUT PCWSTR			*DosFilePath OPTIONAL,
    OUT PUNICODE_STRING	NtFilePath OPTIONAL
);

// Rtl Large Integer Operations

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
//   ��������!!!!!!  � ���� ����� � ���� ��������� ��������� � ���
//   ����:  RtlLargeInt�egerLessThanZero($a)
//   �����: RtlLargeInt�egerLessThanZero ($a)
//
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#define RtlLargeInt�egerLessThanZero ($a)	(($a).HighPart &lt; 0)
#define Li2Double(x)					((double)((x).HighPart) * 4.294967296E9 + (double)((x).LowPart))

NTSYSAPI
LARGE_INTEGER
NTAPI
RtlEnlargedIntegerMultiply(
	IN LONG lMultiplicand,
	IN LONG lMultiplier
	);

NTSYSAPI
ULONG
NTAPI
RtlEnlargedUnsignedDivide(
	IN LARGE_INTEGER	liDividend,
	IN ULONG			uDivisor,
	OUT PULONG			puRemainder OPTIONAL
	);

NTSYSAPI
LARGE_INTEGER
NTAPI
RtlEnlargedUnsignedMultiply(
	IN ULONG	uMultiplicand,
	IN ULONG	uMultiplier
	);

NTSYSAPI
LARGE_INTEGER
NTAPI
RtlExtendedIntegerMultiply(
	IN LARGE_INTEGER	liMultiplicand,
	IN LONG				lMultiplier
	);

NTSYSAPI
LARGE_INTEGER
NTAPI
RtlExtendedLargeIntegerDivide(
	IN LARGE_INTEGER	liDividend,
	IN ULONG			uDivisor,
	OUT PULONG			puRemainder OPTIONAL
	);

NTSYSAPI
LARGE_INTEGER
NTAPI
RtlLargeIntegerAdd(
	IN LARGE_INTEGER	liAddend1,
	IN LARGE_INTEGER	liAddend2
	);

NTSYSAPI
LARGE_INTEGER
NTAPI
RtlLargeIntegerDivide(
	IN LARGE_INTEGER	liDividend,
	IN LARGE_INTEGER	liDivisor,
	OUT PLARGE_INTEGER	pliRemainder OPTIONAL
	);

NTSYSAPI
LARGE_INTEGER
NTAPI
RtlLargeIntegerNegate(
	IN LARGE_INTEGER	liSubtrahend
	);

NTSYSAPI
LARGE_INTEGER
NTAPI
RtlLargeIntegerSubtract(
	IN LARGE_INTEGER	liMinuend,
	IN LARGE_INTEGER	liSubtrahend
	);

// Debug Functions
typedef struct _DEBUG_BUFFER
{
    HANDLE	SectionHandle;
    PVOID	SectionBase;
    PVOID	RemoteSectionBase;
    ULONG	SectionBaseDelta;
    HANDLE	EventPairHandle;
    ULONG	Unknown[2];
    HANDLE	RemoteThreadHandle;
    ULONG	InfoClassMask;
    ULONG	SizeOfInfo;
    ULONG	AllocatedSize;
    ULONG	SectionSize;
    PVOID	ModuleInformation;
    PVOID	BackTraceInformation;
    PVOID	HeapInformation;
    PVOID	LockInformation;
    PVOID	Reserved[8];
} DEBUG_BUFFER, *PDEBUG_BUFFER;

typedef enum
{
     AdjustCurrentProcess,
     AdjustCurrentThread
}
ADJUST_PRIVILEGE_TYPE; 

#define PDI_MODULES		0x01
#define PDI_BACKTRACE	0x02
#define PDI_HEAPS		0x04
#define PDI_HEAP_TAGS	0x08
#define PDI_HEAP_BLOCKS	0x10
#define PDI_LOCKS		0x20

typedef struct _DEBUG_MODULE_INFORMATION // c.f. SYSTEM_MODULE_INFORMATION
{
    ULONG	Reserved[2];
    ULONG	Base;
    ULONG	Size;
    ULONG	Flags;
    USHORT	Index;
    USHORT	Unknown;
    USHORT	LoadCount;
    USHORT	ModuleNameOffset;
    CHAR	ImageName[256];
} DEBUG_MODULE_INFORMATION, *PDEBUG_MODULE_INFORMATION;

typedef struct _DEBUG_HEAP_INFORMATION
{
    ULONG	Base;
    ULONG	Flags;
    USHORT	Granularity;
    USHORT	Unknown;
    ULONG	Allocated;
    ULONG	Committed;
    ULONG	TagCount;
    ULONG	BlockCount;
    ULONG	Reserved[7];
    PVOID	Tags;
    PVOID	Blocks;
} DEBUG_HEAP_INFORMATION, *PDEBUG_HEAP_INFORMATION;

typedef struct _DEBUG_LOCK_INFORMATION // c.f. SYSTEM_LOCK_INFORMATION
{
    PVOID	Address;
    USHORT	Type;
    USHORT	CreatorBackTraceIndex;
    ULONG	OwnerThreadId;
    ULONG	ActiveCount;
    ULONG	ContentionCount;
    ULONG	EntryCount;
    ULONG	RecursionCount;
    ULONG	NumberOfSharedWaiters;
    ULONG	NumberOfExclusiveWaiters;
} DEBUG_LOCK_INFORMATION, *PDEBUG_LOCK_INFORMATION;


NTSYSAPI
PDEBUG_BUFFER
NTAPI
RtlCreateQueryDebugBuffer(
    IN ULONG Size,
    IN BOOLEAN EventPair
    );

NTSYSAPI
NTSTATUS
NTAPI
RtlQueryProcessDebugInformation(
    IN ULONG ProcessId,
    IN ULONG DebugInfoClassMask,
    IN OUT PDEBUG_BUFFER DebugBuffer
    );

NTSYSAPI
NTSTATUS
NTAPI
RtlDestroyQueryDebugBuffer(
    IN PDEBUG_BUFFER DebugBuffer
    );

NTSYSAPI
NTSTATUS
NTAPI
NtLoadDriver(
    // "\\Registry\\Machine\\System\\CurrentControlSet\\Services\\&lt;DriverName&gt;"
	IN PUNICODE_STRING RegistryPath
);

NTSYSAPI
NTSTATUS
NTAPI
NtUnloadDriver(
    // "\\Registry\\Machine\\System\\CurrentControlSet\\Services\\&lt;DriverName&gt;"
	IN PUNICODE_STRING RegistryPath
);

NTSYSAPI
NTSTATUS
NTAPI
RtlAdjustPrivilege(
	IN ULONG Privilege,
	IN BOOLEAN NewValue,
	IN BOOLEAN ForThread,
	OUT PBOOLEAN OldValue
);

//-------------------

#define SYSTEM_INFORMATION_CLASS SYSTEMINFOCLASS

NTSYSAPI
NTSTATUS
NTAPI
ZwQuerySystemInformation (
    IN SYSTEM_INFORMATION_CLASS SystemInformationClass,
    OUT PVOID                   SystemInformation,
    IN ULONG                    Length,
    OUT PULONG                  ReturnLength
);

NTSYSAPI
NTSTATUS
NTAPI
ZwOpenProcess (
    OUT PHANDLE             ProcessHandle,
    IN ACCESS_MASK          DesiredAccess,
    IN POBJECT_ATTRIBUTES   ObjectAttributes,
    IN PCLIENT_ID           ClientId OPTIONAL
);

NTSYSAPI
NTSTATUS
NTAPI
ZwClose(
  __in  HANDLE Handle
);

NTSYSAPI
NTSTATUS
NTAPI
ZwSetInformationProcess (
    IN HANDLE           ProcessHandle,
    IN PROCESSINFOCLASS ProcessInformationClass,
    IN PVOID            ProcessInformation,
    IN ULONG            ProcessInformationLength
);


NTSYSAPI
NTSTATUS
NTAPI
ZwQueryInformationThread (
    IN HANDLE           ThreadHandle,
    IN THREADINFOCLASS  ThreadInformationClass,
    OUT PVOID           ThreadInformation,
    IN ULONG            ThreadInformationLength,
    OUT PULONG          ReturnLength OPTIONAL
);

NTSYSAPI
NTSTATUS
NTAPI
ZwShutdownSystem(DWORD Action);

NTSYSAPI
PVOID
NTAPI
RtlImageNtHeader (
    IN PVOID BaseAddress
);

NTSYSAPI
NTSTATUS
NTAPI
ZwQueryInformationProcess (
    IN HANDLE           ProcessHandle,
    IN PROCESSINFOCLASS ProcessInformationClass,
    OUT PVOID           ProcessInformation,
    IN ULONG            ProcessInformationLength,
    OUT PULONG          ReturnLength OPTIONAL
);

NTSYSAPI
NTSTATUS
NTAPI
ZwQueryInformationFile(
  __in   HANDLE FileHandle,
  __out  PIO_STATUS_BLOCK IoStatusBlock,
  __out  PVOID FileInformation,
  __in   ULONG Length,
  __in   FILE_INFORMATION_CLASS FileInformationClass
);

NTSYSAPI
NTSTATUS
NTAPI
ZwAllocateVirtualMemory (
    IN HANDLE       ProcessHandle,
    IN OUT PVOID    *BaseAddress,
    IN ULONG        ZeroBits,
    IN OUT PSIZE_T  RegionSize,
    IN ULONG        AllocationType,
    IN ULONG        Protect
);

NTSYSAPI
NTSTATUS
NTAPI
ZwWriteVirtualMemory(
    IN HANDLE ProcessHandle,
    IN PVOID  BaseAddress,
    IN PVOID  Buffer,
    IN ULONG  NumberOfBytesToWrite,
    OUT PULONG NumberOfBytesWritten OPTIONAL
);

NTSYSAPI  
NTSTATUS 
NTAPI 
ZwProtectVirtualMemory( 
  IN HANDLE               ProcessHandle, 
  IN OUT PVOID            *BaseAddress, 
  IN OUT PULONG           NumberOfBytesToProtect, 
  IN ULONG                NewAccessProtection, 
  OUT PULONG              OldAccessProtection
); 

NTSYSAPI  
NTSTATUS 
NTAPI 
ZwMapViewOfSection( 
    IN HANDLE SectionHandle, 
    IN HANDLE ProcessHandle, 
    IN OUT PVOID *BaseAddress, 
    IN ULONG ZeroBits, 
    IN ULONG CommitSize, 
    IN OUT PLARGE_INTEGER SectionOffset OPTIONAL, 
    IN OUT PSIZE_T ViewSize, 
    IN SECTION_INHERIT InheritDisposition, 
    IN ULONG AllocationType, 
    IN ULONG Protect
);  

NTSYSAPI  
NTSTATUS
NTAPI
ZwQueueApcThread(
	HANDLE hThread,
	PKNORMAL_ROUTINE ApcRoutine,
	PVOID ApcContext,
	PVOID Argument1,
	PVOID Argument2
);

NTSYSAPI  
NTSTATUS
NTAPI
ZwResumeThread( 
	DWORD ThreadHandle,
	DWORD PreviousSuspendCount
);

NTSYSAPI
NTSTATUS 
NTAPI 
ZwSetContextThread(
	IN HANDLE 	ThreadHandle, 
	IN PCONTEXT 	Context	 
);

/*
NTSYSAPI
NTSTATUS 
NTAPI 
ZwMapViewOfSection(
  __in     HANDLE SectionHandle,
  __in     HANDLE ProcessHandle,
  __inout  PVOID *BaseAddress,
  __in     ULONG_PTR ZeroBits,
  __in     SIZE_T CommitSize,
  __inout  PLARGE_INTEGER SectionOffset,
  __inout  PSIZE_T ViewSize,
  __in     SECTION_INHERIT InheritDisposition,
  __in     ULONG AllocationType,
  __in     ULONG Win32Protect
);
*/

typedef enum _WINSTATIONINFOCLASS {
    WinStationInformation = 8
} WINSTATIONINFOCLASS;

BOOLEAN WinStationQueryInformationW(
  __in          HANDLE hServer,
  __in          ULONG LogonId,
  __in          WINSTATIONINFOCLASS WinStationInformationClass,
  __out         PVOID pWinStationInformation,
  __in          ULONG WinStationInformationLength,
  __out         PULONG pReturnLength
);


BOOL __stdcall WinStationTerminateProcess(HANDLE, DWORD, DWORD);

NTSYSAPI  
NTSTATUS
NTAPI 
RtlImageDirectoryEntryToData(
    IN PVOID Base,
    IN BOOLEAN MappedAsImage,
    IN USHORT DirectoryEntry,
    OUT PULONG Size
    );

typedef enum _KPROFILE_SOURCE
{
	ProfileTime,
	ProfileAlignmentFixup,
	ProfileTotalIssues,
	ProfilePipelineDry,
	ProfileLoadInstructions,
	ProfilePipelineFrozen,
	ProfileBranchInstructions,
	ProfileTotalNonissues,
	ProfileDcacheMisses,
	ProfileIcacheMisses,
	ProfileCacheMisses,
	ProfileBranchMispredictions,
	ProfileStoreInstructions,
	ProfileFpInstructions,
	ProfileIntegerInstructions,
	Profile2Issue,
	Profile3Issue,
	Profile4Issue,
	ProfileSpecialInstructions,
	ProfileTotalCycles,
	ProfileIcacheIssues,
	ProfileDcacheAccesses,
	ProfileMemoryBarrierCycles,
	ProfileLoadLinkedIssues,
	ProfileMaximum
} KPROFILE_SOURCE, *PKPROFILE_SOURCE;

NTSYSAPI NTSTATUS NTAPI NtQueryIntervalProfile( KPROFILE_SOURCE ProfileSource, 
#ifndef WIN64
																				PULONG Interval
#else
																				PULONGLONG Interval
#endif								
																										); 

NTSYSAPI 
NTSTATUS
NTAPI

RtlCreateUserThread(
  IN HANDLE               ProcessHandle,
  IN PSECURITY_DESCRIPTOR SecurityDescriptor OPTIONAL,
  IN BOOLEAN              CreateSuspended,
  IN ULONG                StackZeroBits,
  IN OUT PULONG           StackReserved,
  IN OUT PULONG           StackCommit,
  IN PVOID                StartAddress,
  IN PVOID                StartParameter OPTIONAL,
  OUT PHANDLE             ThreadHandle,
  OUT PCLIENT_ID          ClientID );

void _chkstk(int);
double atan(double);

NTSYSAPI 
VOID
NTAPI

KiUserApcDispatcher(
  IN PVOID                Unused1,
  IN PVOID                Unused2,
  IN PVOID                Unused3,
  IN PVOID                ContextStart,
  IN PVOID                ContextBody );

VOID WINAPI RtlGetNtVersionNumbers(LPDWORD pMajor, LPDWORD pMinor, LPDWORD pBuild);

#ifdef __cplusplus
}


#pragma warning(default : 4200)

#endif
#endif
