#ifndef _DEBUG

#include <stdlib.h>


void * __cdecl operator new(size_t bytes) {
    return malloc(bytes);
}

void * __cdecl operator new[](size_t bytes) {
    return malloc(bytes);
}

void __cdecl operator delete(void *ptr) {
    free(ptr);
}

void __cdecl operator delete[](void *ptr) {
    free(ptr);
}

#endif
