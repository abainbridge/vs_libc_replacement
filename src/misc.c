#include <windows.h>


int __cdecl __purecall(void)
{
    return 0;
}


void exit(int code) {
    ExitProcess(code);
}


// Set this as the entry point in the linker options.
void premain(void)
{
    WinMain(0, 0, 0, 0);
    exit(0);
}
