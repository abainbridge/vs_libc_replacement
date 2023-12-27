#pragma once

#include "stdlib_common.h"


#ifdef __cplusplus
extern "C"
{
#endif


#define NULL 0

void *malloc(size_t size);
void free(void *mem);
void *realloc(void *mem, size_t size);

unsigned long strtoul(const char *s, char **p, int base);
void exit(int code);

int atoi(char const *str);


#ifdef __cplusplus
}
#endif
