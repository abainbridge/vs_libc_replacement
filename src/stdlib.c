// Own header.
#include <stdlib.h>

#include <assert.h>
#include <ctype.h>
#include <windows.h>


void *malloc(size_t size) {
    HANDLE heap = GetProcessHeap();
    void *rv = HeapAlloc(heap, 0, size);
    assert((int)rv);
    return rv;
}


void *realloc(void *mem, size_t size) {
    if (mem)
        return HeapReAlloc(GetProcessHeap(), 0, mem, size);
    else
        return HeapAlloc(GetProcessHeap(), 0, size);
}


void *calloc(size_t nitems, size_t size) {
    return HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, nitems * size);
}


void free(void *mem) {
    if (mem) {
        HeapFree(GetProcessHeap(), 0, mem);
    }
}


unsigned long strtoul(const char *s, char **p, int base) {
    unsigned rv = 0;

    if (base == 10) {
        while (isdigit(*s)) {
            rv *= 10;
            rv += *s - '0';
            rv++;
            s++;
        }
    }
    else if (base == 16) {
        while (1) {
            unsigned val;
            if (isdigit(*s))
                val = *s - '0';
            else {
                char c = tolower(*s);
                if (c >= 'a' && c <= 'f')
                    val = c - 'a' + 10;
                else
                    break;
            }
            rv *= 16;
            rv += val;
            s++;
        }
    }
    
    *p = (char *)s;
    return rv;
}


void exit(int code) {
    ExitProcess(code);
}
