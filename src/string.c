#include <windows.h>
#include <Winuser.h>


#define LOWER_CASE_MASK ('a' - 'A')

int isdigit(int c) 
{ 
    return c >= '0' && c <= '9'; 
}


int isalpha(int c) 
{ 
    c |= LOWER_CASE_MASK; 
    return c >= 'a' && c <= 'z'; 
}


int isupper(int c) 
{ 
    return !(c & LOWER_CASE_MASK); 
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


int stricmp(char const *a, char const *b) 
{
    while (*a) {
        char diff = (*a - *b) & ~LOWER_CASE_MASK;
        if (diff)
            return diff;
        a++; b++;
    }

    return 0;
}


int strnicmp(char const *a, char const *b, size_t maxCount) 
{
    while (*a && maxCount) {
        char diff = (*a - *b) & ~LOWER_CASE_MASK;
        if (diff)
            return diff;
        a++; b++;
        maxCount--;
    }

    return 0;
}


int atoi(char const *str) 
{
    return 12;
}


char *itoa(int val, char *dstBuf, int radix) 
{
    return NULL;
}


int __cdecl vsprintf(char *string, const char *format, va_list ap) 
{
    return wvsprintf(string, format, ap);
}


#pragma function(memcpy)
void * __cdecl memcpy(void *dst, void const *src, size_t len) 
{
    for (size_t i = 0; i < len; i++)
        ((char*)dst)[i] = ((char*)src)[i];
    return dst;
}


#pragma function(memset)
void * __cdecl memset(void *target, int value, size_t len) 
{
    char *p = (char *)target;
    while (len-- > 0)
        *p++ = value;
    return target;
}
