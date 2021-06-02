Parse `ExportTable` of a DLL and find target function by hash. 

## Compile on Linux
`nim c -d:release --d:mingw --opt:size --passC:"-masm=intel" main.nim`