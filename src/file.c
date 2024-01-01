#ifndef _DEBUG

// Own header.
#include <stdio.h>

#include <assert.h>
#include <string.h>
#include <windows.h>


struct _FILE {
    HANDLE h;
};


WINBASEAPI DWORD WINAPI GetCurrentDirectoryA(DWORD nBufferLength, char *lpBuffer);

FILE *fopen(const char *filename, const char *mode) {
//    if (!strchr(mode, 'b')) return NULL; // Opening file in text mode is not supported.

    char path[256];
    GetCurrentDirectoryA(256, path);

    HANDLE hFile;
    if (strchr(mode, 'w'))
        hFile = CreateFileA(filename, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, 0, 0);
    else
        hFile = CreateFileA(filename, GENERIC_READ, 0, 0, OPEN_EXISTING, 0, 0);

    if (hFile == INVALID_HANDLE_VALUE)
        return NULL;

    FILE *file = malloc(sizeof(FILE));
    file->h = hFile;

    return file;
}


int fclose(FILE *f) {
    CloseHandle(f->h);
    free(f);
    return 0;
}


int fgetc(FILE *f) {
    char c;
    unsigned numBytesRead;
    if (!ReadFile(f->h, &c, 1, &numBytesRead, NULL))
        return EOF;
    if (numBytesRead == 0)
        return EOF;
    return c;
}


size_t fread(void *_buf, size_t size, size_t count, FILE *f) {
    char *buf = (char *)_buf;
    unsigned numBytesRead;
    if (!ReadFile(f->h, buf, size * count, &numBytesRead, NULL))
        return 0;
    if (numBytesRead % count != 0) {
        assert(0);
    }
    return numBytesRead;
}


long ftell(FILE *f) {
    unsigned offset = SetFilePointer(f->h, 0, 0, FILE_CURRENT);
    return offset & 0x7ffffff;
}


int fseek(FILE *f, long offset, int origin) {
    DWORD moveMethod = FILE_BEGIN;
    if (origin == SEEK_CUR)
        moveMethod = FILE_CURRENT;
    else if (origin == SEEK_END)
        moveMethod = FILE_END;
    unsigned result = SetFilePointer(f->h, offset, 0, moveMethod);
    if (result == INVALID_SET_FILE_POINTER)
        return -1;
//    f->flags &= ~_FILE_EOF;
    return 0;
}

#endif
