#pragma once


#include "stdlib_common.h"


#ifdef __cplusplus
extern "C"
{
#endif


void *memset(void *dest, int ch, size_t count);
void *memcpy(void *dst, void const *src, size_t len);
int memcmp(const void *lhs, const void *rhs, size_t count);
void *memmove(void *dest, const void *src, size_t count);

char *strchr(const char *str, int ch);
int strcmp(const char *str1, const char *str2);
int stricmp(const char *str1, const char *str2);
int strncmp(const char *lhs, const char *rhs, size_t count); 
size_t strlen(const char *str);
char *strcat(char *dest, const char *src);
char *strcpy(char *dest, const char *src);

char *strdup(const char *str1);


#ifdef __cplusplus
}
#endif
