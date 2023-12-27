#include <assert.h>
//#include <windows.h>

void assert(int expression) {
    if (!expression)
        __debugbreak();
    //_CrtDbgBreak();
}
