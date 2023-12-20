//#include <windows.h>


unsigned _tls_array[10];


int __cdecl __purecall(void) {
    return 0;
}


// Set this as the entry point in the linker options.
// void premain(void) {
//     WinMain(0, 0, 0, 0);
//     exit(0);
// }


// int main();
// int __stdcall WinMain(HINSTANCE _hInstance, HINSTANCE _hPrevInstance, LPSTR cmdLine, int _iCmdShow) {
//     return main();
// }


void WinMainCRTStartup() {
}
