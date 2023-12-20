#pragma once


#ifdef __cplusplus
extern "C"
{
#endif


#define HIWORD(l) (((l) >> 16) & 0xffff)


typedef enum {
    VK_MENU = 0x12,

    WM_CHAR = 0x102,
    WM_EXITMENULOOP = 0x0212,
    WM_KEYDOWN = 0x0100,
    WM_KEYUP = 0x0101,
    WM_KILLFOCUS = 0x0008,
    WM_LBUTTONDOWN = 0x0201,
    WM_LBUTTONUP = 0x0202,
    WM_MBUTTONDOWN = 0x0207,
    WM_MBUTTONUP = 0x0208,
    WM_MOUSEMOVE = 0x0200,
    WM_MOUSEWHEEL = 0x020A,
    WM_NCLBUTTONDOWN = 0x00A1,
    WM_NCMBUTTONDOWN = 0x00A7,
    WM_NCRBUTTONDOWN = 0x00A4,
    WM_RBUTTONDOWN = 0x0204,
    WM_RBUTTONUP = 0x0205,
    WM_SETFOCUS = 0x0007,
    WM_SYSCHAR = 0x0106,
    WM_SYSKEYDOWN = 0x0104,
    WM_SYSKEYUP = 0x0105,
};


typedef short SHORT;
typedef unsigned short WORD;
typedef unsigned DWORD;
typedef long LONG;
typedef __int64 LONGLONG;
typedef unsigned* DWORD_PTR;


typedef union _LARGE_INTEGER {
    struct {
        DWORD LowPart;
        LONG HighPart;
    } DUMMYSTRUCTNAME;
    struct {
        DWORD LowPart;
        LONG HighPart;
    } u;
    LONGLONG QuadPart;
} LARGE_INTEGER;


typedef void *HANDLE;
typedef HANDLE HGLOBAL;
#define DECLARE_HANDLE(name) struct name##__{int unused;}; typedef struct name##__ *name
DECLARE_HANDLE(HINSTANCE);
DECLARE_HANDLE(HWND);
DECLARE_HANDLE(HDROP);


#define WINAPI __stdcall
#define WINBASEAPI __declspec(dllimport)
#define WINUSERAPI __declspec(dllimport)

// #define EXTERN_C extern "C"
// #define DECLSPEC_IMPORT __declspec(dllimport)
// #define STDAPICALLTYPE __stdcall
// #define SHSTDAPI_(type) EXTERN_C DECLSPEC_IMPORT type STDAPICALLTYPE


// Clipboard.
#define CF_TEXT             1
WINUSERAPI int WINAPI OpenClipboard(HWND hWndNewOwner);
WINUSERAPI int WINAPI CloseClipboard(void);
WINUSERAPI HANDLE WINAPI GetClipboardData(unsigned uFormat);
WINUSERAPI int WINAPI EmptyClipboard(void);
WINUSERAPI HANDLE WINAPI SetClipboardData(unsigned uFormat, HANDLE hMem);


WINBASEAPI void * WINAPI GlobalLock(HGLOBAL hMem);
WINBASEAPI int WINAPI GlobalUnlock(HGLOBAL hMem);

WINBASEAPI void WINAPI OutputDebugString(char *outputString);

WINUSERAPI SHORT WINAPI GetAsyncKeyState(int vKey);


// Timing.
WINBASEAPI int WINAPI QueryPerformanceCounter(LARGE_INTEGER *performanceCount);
WINBASEAPI int WINAPI QueryPerformanceFrequency(LARGE_INTEGER *frequency);
WINBASEAPI void WINAPI Sleep(DWORD milliseconds);

// Memory allocation / free.
#define GMEM_DDESHARE       0x2000
WINBASEAPI HGLOBAL WINAPI GlobalAlloc(unsigned uFlags, size_t dwBytes);
WINBASEAPI HANDLE WINAPI GetProcessHeap(void);
WINBASEAPI void * WINAPI HeapAlloc(HANDLE hHeap, DWORD dwFlags, size_t bytes);
WINBASEAPI int WINAPI HeapFree(HANDLE hHeap, DWORD dwFlags,void *mem);


#ifdef __cplusplus
}
#endif
