#include <assert.h>
#include <windows.h>

HANDLE _crtheap = NULL;

unsigned _tls_array[10];
unsigned _tls_index;


// pointers to initialization sections

typedef void(__cdecl *_PVFV)(void);

// Create table of C static initializer functions that the linker will magically populate.
#pragma data_seg(".CRT$XIA")
_PVFV __xi_a[1] = { NULL };
#pragma data_seg(".CRT$XIZ")
_PVFV __xi_z[1] = { NULL };

// Same for C++ static initializers.
#pragma data_seg(".CRT$XCA")
_PVFV __xc_a[1] = { NULL };
#pragma data_seg(".CRT$XCZ")
_PVFV __xc_z[1] = { NULL };

#pragma data_seg()  // reset data segment to the normal one.
//#pragma comment(linker, "/merge:.CRT=.data")


int __cdecl __purecall(void) {
    return 0;
}


void _initterm(_PVFV * pfbegin, _PVFV * pfend) {
    // * walk the table of function pointers from the bottom up, until
    // * the end is encountered.  Do not skip the first entry.  The initial
    // * value of pfbegin points to the first valid entry.  Do not try to
    // * execute what pfend points to.  Only entries before pfend are valid.
    while (pfbegin < pfend) {
        // if current table entry is non-NULL, call thru it.
        if (*pfbegin != NULL)
            (**pfbegin)();
        ++pfbegin;
    }
}


int __stdcall WinMain(HINSTANCE _hInstance, HINSTANCE _hPrevInstance, char *cmdLine, int _iCmdShow);

// Set this as the entry point in the linker options.
void premain(void) {
    //  Initialize the "big-block" heap.
    _crtheap = GetProcessHeap();
    assert((int)_crtheap);
//    HeapCreate(0, 4096, 0);

    // initialize floating point package, if present
//     if (_FPinit != NULL &&
//         _IsNonwritableInCurrentImage((PBYTE)&_FPinit))
//     {
//         (*_FPinit)(initFloatingPrecision);
//     }
//     _initp_misc_cfltcvt_tab();

    // Init static C variables.
    _initterm(__xi_a, __xi_z);

#if defined (_RTC)
    atexit(_RTC_Terminate);
#endif

    // Init static C++ variables.
    _initterm(__xc_a, __xc_z);

// #ifndef CRTDLL
//     /*
//     * If we have any dynamically initialized __declspec(thread)
//     * variables, then invoke their initialization for the thread on
//     * which the DLL is being loaded, by calling __dyn_tls_init through
//     * a callback defined in tlsdyn.obj.  We can't rely on the OS
//     * calling __dyn_tls_init with DLL_PROCESS_ATTACH because, on
//     * Win2K3 and before, that call happens before the CRT is
//     * initialized.
//     */
//     if (__dyn_tls_init_callback != NULL &&
//         _IsNonwritableInCurrentImage((PBYTE)&__dyn_tls_init_callback)) {
//         __dyn_tls_init_callback(NULL, DLL_THREAD_ATTACH, NULL);
//     }
// #endif

    WinMain(0, 0, 0, 0);
    exit(0);
}
