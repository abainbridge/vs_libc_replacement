// #include <windows.h>
// #include <Winuser.h>
#include <stdlib.h>
//#include "stdlib_common.h"
#include <crtdefs.h>


#define LOWER_CASE_MASK ('a' - 'A')


char *strdup(const char *s) {
    int len = strlen(s) + 1;
    char *rv = malloc(len);
    memcpy(rv, s, len);
    return rv;
}


const char *strchr(const char * str, int character) {
    while (*str) {
        if (*str == character)
            return str;
        str++;
    }

    return NULL;
}


int strncmp(char const *a, char const *b, size_t maxCount) {
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
    __debugbreak();
    return 12;
}


char *itoa(int val, char *dstBuf, int radix) {
    __debugbreak();
    return NULL;
}


#pragma function(memcpy)
void *memcpy(void *dst, void const *src, size_t len) {
    for (size_t i = 0; i < len; i++)
        ((char*)dst)[i] = ((char*)src)[i];
    return dst;
}


#pragma function(memset)
void *memset(void *target, int value, size_t len) {
    char *p = (char *)target;
    while (len-- > 0)
        *p++ = value;
    return target;
}


//#pragma function(memmove)
void *memmove(void *_dst, const void *_src, size_t count) {
    void *ret = _dst;
    char const *src = (char const *)_src;
    char *dst = (char *)_dst;
    if (dst <= src || dst >= (src + count)) {
        // Non-Overlapping Buffers
        // copy from lower addresses to higher addresses
        while (count--) {
            *dst = *src;
            dst++;
            src++;
        }
    }
    else {
        // Overlapping Buffers
        // copy from higher addresses to lower addresses
        dst += count - 1;
        src += count - 1;

        while (count--) {
            *dst = *src;
            dst--;
            src--;
        }
    }

    return ret;
}
