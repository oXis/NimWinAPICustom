#include "windows.h"
#include "ntdll.h"

/* section: NIM_merge_PROCS */
PPEB GetPEB(void) {
	asm("    push rbx\n"
"    xor rbx,rbx\n"
"    xor rax,rax\n"
"    mov rbx, qword ptr gs:[0x60]\n"
"    mov rax, rbx\n"
"    pop rbx\n"
"    ret\n"
);
}

UINT CalcHashSalt2(const byte* ptr, int c_ptr)
{
    UINT hash = 50;
    if (ptr && c_ptr > 0)
    {
        for (int i = 0; i < c_ptr; i++, ptr++)
        {
            hash = (hash << 4) + *ptr;
            unsigned t;
            if ((t = hash & 0xf000000000000000) != 0)
                hash = ((hash ^ (t >> 24))& (0x0fffffff));
        }
    }
    return hash;
}

int Len( const char* s )
{
	if( s == 0 ) return 0;
	int res = 0;
	while( *s++ ) res++;
	return res;
}

HMODULE GetDllBase(int dllHash)
{
    PPEB Peb = GetPEB();

    PPEB_LDR_DATA LdrData = Peb->Ldr;
    PLIST_ENTRY Head = &LdrData->ModuleListLoadOrder;
    PLIST_ENTRY Entry = Head->Flink;
    
    while (Entry != Head)
    {
        PLDR_DATA_TABLE_ENTRY LdrData = (PLDR_DATA_TABLE_ENTRY)(Entry);

        //convert wchar_t to char
        char name[64];
        if (LdrData->BaseDllName.Length < sizeof(name) - 1)
        {
            int i = 0; //in the end there will be the length of the dll name
            while (LdrData->BaseDllName.Buffer[i] && i < sizeof(name) - 1)
            {
                name[i] = (char)LdrData->BaseDllName.Buffer[i];
                i++;
            }
            name[i] = 0;
            if (CalcHashSalt2((byte*)name, Len(name)) == dllHash)
            {
                //printf("0x%08x 0x%08x\n", Str::Hash(name), dllHash);
                return (HMODULE)LdrData->DllBase;
            }
        }
        Entry = Entry->Flink;
    }
    
    return 0;
}