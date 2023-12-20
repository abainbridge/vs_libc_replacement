#pragma once

#include "stdlib_common.h"


#ifdef __cplusplus
extern "C"
{
#endif


#define NULL 0

void *malloc(size_t size);
void free(void *mem);
unsigned long strtoul(const char *s, char **p, int base);
void exit(int code);


#ifdef __cplusplus
}
#endif
