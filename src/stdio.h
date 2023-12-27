#pragma once

#include <crtdefs.h>

#ifdef __cplusplus
extern "C"
{
#endif

enum {
    SEEK_SET,
    SEEK_END,
    SEEK_CUR
};


#define EOF (-1)

typedef struct _FILE FILE;


FILE *fopen(const char *filename, const char *mode);
int fclose(FILE *f);
int fgetc(FILE *f);
size_t fread(void *buf, size_t size, size_t count, FILE *f);
long ftell(FILE *f);
int fseek(FILE *f, long off, int origin);

int __cdecl vsprintf(char *string, const char *format, va_list ap);

#ifdef __cplusplus
}
#endif
