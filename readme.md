Parse `ExportTable` of a DLL and find target function by hash. 

## Compile on Linux
`nim c -d:release --d:mingw --opt:size --passC:"-masm=intel" main.nim`

> Note    
> Ordinal `0x7FB` was taken from `user32.dll` on a Windows 7 x64 machine. Might be different on other systems.