#include <ctype.h>
#include <stdlib.h>

// #define COBJMACROS
// #define NOMINMAX
// #define WIN32_LEAN_AND_MEAN
// #define _NO_CRT_STDIO_INLINE
// 
// #include <windows.h>

void *VirtualAlloc(void *addr, unsigned size, unsigned flAllocationType, unsigned flProtect);

#define PAGE_READWRITE         0x04     
#define MEM_COMMIT                  0x1000      
#define MEM_RESERVE                 0x2000      

void * __cdecl malloc(size_t size) {
    return 0;// VirtualAlloc(NULL, size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
}


void __cdecl free(void *mem) {
    NULL;
}


unsigned long strtoul(const char *s, char **p, int base) {
    unsigned rv = 0;
    while (isdigit(*s)) {
        rv *= 10;
        rv += *s - '0';
    }
    return rv;
}


void exit(int code) {
//    ExitProcess(code);
}
