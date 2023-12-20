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


typedef struct _FILE {
    int i;
} FILE;


FILE *fopen(const char *filename, const char *mode);
int fclose(FILE *f);
int fgetc(FILE *f);
size_t fread(void *destv, size_t size, size_t nmemb, FILE *f);
long ftell(FILE *f);
int fseek(FILE *f, long off, int whence);

int __cdecl vsprintf(char *string, const char *format, va_list ap);

#ifdef __cplusplus
}
#endif
