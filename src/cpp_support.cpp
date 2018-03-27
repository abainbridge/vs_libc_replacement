#include <windows.h>


void * __cdecl operator new(size_t bytes)
{
    return HeapAlloc(GetProcessHeap(), 0, bytes);
}

void * __cdecl operator new[](size_t bytes)
{
    return HeapAlloc(GetProcessHeap(), 0, bytes);
}

void __cdecl operator delete(void *ptr)
{
    if (ptr) HeapFree(GetProcessHeap(), 0, ptr);
}

void __cdecl operator delete[](void *ptr)
{
    if (ptr) HeapFree(GetProcessHeap(), 0, ptr);
}
