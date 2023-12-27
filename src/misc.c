#include <assert.h>
#include <windows.h>

HANDLE _crtheap = NULL;

unsigned _tls_array[10];
unsigned _tls_index;


int __cdecl __purecall(void) {
    return 0;
}


int __stdcall WinMain(HINSTANCE _hInstance, HINSTANCE _hPrevInstance, char *cmdLine, int _iCmdShow);

// Set this as the entry point in the linker options.
void premain(void) {
    //  Initialize the "big-block" heap.
    _crtheap = GetProcessHeap();
    assert((int)_crtheap);
    HeapCreate(0, 4096, 0);

    WinMain(0, 0, 0, 0);
    exit(0);
}
