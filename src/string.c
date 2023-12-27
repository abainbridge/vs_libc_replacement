// #include <windows.h>
// #include <Winuser.h>
#include <stdlib.h>
//#include "stdlib_common.h"
#include <crtdefs.h>


#define LOWER_CASE_MASK ('a' - 'A')


const char *strchr(const char * str, int character) {
    while (*str) {
        if (*str == character)
            return str;
        str++;
    }

    return NULL;
}


int strncmp(char const *a, char const *b, size_t maxCount) 
{
    while (*a && maxCount) {
        if (*a != *b)
            return *a - *b;
        a++; b++;
        maxCount--;
    }

    return 0;
}


int stricmp(char const *a, char const *b) {
    while (*a) {
        char diff = (*a - *b) & ~LOWER_CASE_MASK;
        if (diff)
            return diff;
        a++; b++;
    }

    return 0;
}


int strnicmp(char const *a, char const *b, size_t maxCount) {
    while (*a && maxCount) {
        char diff = (*a - *b) & ~LOWER_CASE_MASK;
        if (diff)
            return diff;
        a++; b++;
        maxCount--;
    }

    return 0;
}


int atoi(char const *str) {
    return 12;
}


char *itoa(int val, char *dstBuf, int radix) {
    return NULL;
}


int vsprintf(char *string, const char *format, va_list ap) {
    memcpy(string, "hellosdf", 9);
    return 0;
}


#pragma function(memcpy)
void * __cdecl memcpy(void *dst, void const *src, size_t len) {
    for (size_t i = 0; i < len; i++)
        ((char*)dst)[i] = ((char*)src)[i];
    return dst;
}


#pragma function(memset)
void * __cdecl memset(void *target, int value, size_t len) {
    char *p = (char *)target;
    while (len-- > 0)
        *p++ = value;
    return target;
}


//#pragma function(memmove)
void * __cdecl memmove(void *dst, void const *src, size_t len) {
    char const *srcChar = (char const *)src;
    char *dstChar = (char *)dst;
    if (src > dst) {
        for (size_t i = 0; i < len; i++)
            dstChar[i] = srcChar[i];
    }
    else {
        for (size_t i = len - 1; i; i--)
            dstChar[i] = srcChar[i];
    }

    return dst;
}
