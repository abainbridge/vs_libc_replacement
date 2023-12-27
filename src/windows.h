#pragma once


#include <stdlib.h>


#ifdef __cplusplus
extern "C"
{
#endif


#define LOWORD(l) ((l) & 0xffff)
#define HIWORD(l) (((l) >> 16) & 0xffff)

#define CW_USEDEFAULT ((int)0x80000000)
#define WS_OVERLAPPED 0x00000000L
#define WS_THICKFRAME       0x00040000L
#define WS_MINIMIZEBOX      0x00020000L
#define WS_MAXIMIZEBOX      0x00010000L
#define WS_SYSMENU 0x00080000L
#define WS_VISIBLE 0x10000000L
#define WS_POPUP 0x80000000L
#define WS_CAPTION 0x00C00000L     /* WS_BORDER | WS_DLGFRAME  */

#define DM_BITSPERPEL           0x00040000L
#define DM_PELSWIDTH            0x00080000L
#define DM_PELSHEIGHT           0x00100000L

#define WS_OVERLAPPEDWINDOW (WS_OVERLAPPED     | \
                             WS_CAPTION        | \
                             WS_SYSMENU        | \
                             WS_THICKFRAME     | \
                             WS_MINIMIZEBOX    | \
                             WS_MAXIMIZEBOX)

#define BI_RGB        0L
#define DIB_RGB_COLORS 0 // Not palettized.

#define MAKEINTRESOURCEA(i) ((char *)((ULONG_PTR)((WORD)(i))))
#define MAKEINTRESOURCE MAKEINTRESOURCEA
#define IDC_ARROW MAKEINTRESOURCE(32512)
#define IDC_IBEAM MAKEINTRESOURCE(32513)
#define IDC_SIZEWE MAKEINTRESOURCE(32644)
#define IDC_SIZENS MAKEINTRESOURCE(32645)

#define IMAGE_ICON 1
#define WM_SETICON 0x80
#define ICON_SMALL 0
#define ICON_BIG 1

#define SW_SHOWMAXIMIZED    3
#define SW_MAXIMIZE         3
#define SW_RESTORE          9

// File
#define CREATE_NEW          1
#define CREATE_ALWAYS       2
#define OPEN_EXISTING       3
#define OPEN_ALWAYS         4
#define TRUNCATE_EXISTING   5
#define GENERIC_READ    (0x80000000L)
#define GENERIC_WRITE   (0x40000000L)
#define GENERIC_EXECUTE (0x20000000L)
#define GENERIC_ALL     (0x10000000L)
#define INVALID_HANDLE_VALUE ((HANDLE)(LONG_PTR)-1)
#define FILE_BEGIN           0
#define FILE_CURRENT         1
#define FILE_END             2
#define INVALID_SET_FILE_POINTER ((DWORD)-1)

#define HEAP_ZERO_MEMORY 0x8      


typedef enum {

    DISP_CHANGE_SUCCESSFUL = 0,
    CDS_FULLSCREEN = 0x4,

    MAX_PATH = 260,

    VK_MENU = 0x12,

    WM_SIZE = 0x5,
    WM_SETFOCUS = 0x7,
    WM_KILLFOCUS = 0x8,
    WM_CLOSE = 0x10,
    WM_SETCURSOR = 0x20,
    WM_WINDOWPOSCHANGED = 0x47,
    WM_KEYDOWN = 0x100,
    WM_KEYUP = 0x101,
    WM_CHAR = 0x102,
    WM_NCLBUTTONDOWN = 0xA1,
    WM_NCRBUTTONDOWN = 0xA4,
    WM_NCMBUTTONDOWN = 0xA7,
    WM_SYSKEYDOWN = 0x104,
    WM_SYSKEYUP = 0x105,
    WM_SYSCHAR = 0x106,
    WM_LBUTTONDOWN = 0x201,
    WM_LBUTTONUP = 0x202,
    WM_RBUTTONDOWN = 0x204,
    WM_RBUTTONUP = 0x205,
    WM_MBUTTONDOWN = 0x207,
    WM_MBUTTONUP = 0x208,
    WM_MOUSEMOVE = 0x200,
    WM_MOUSEWHEEL = 0x20A,
    WM_EXITMENULOOP = 0x212,
    WM_DROPFILES = 0x233,
};


typedef short SHORT;
typedef unsigned short WORD;
typedef unsigned DWORD;
typedef long LONG;
typedef unsigned UINT;
typedef __int64 LONGLONG;
#define _W64 __w64
typedef _W64 unsigned long ULONG_PTR, *PULONG_PTR;
typedef ULONG_PTR DWORD_PTR, *PDWORD_PTR;
typedef _W64 unsigned int UINT_PTR, *PUINT_PTR;
typedef _W64 long LONG_PTR, *PLONG_PTR;
typedef UINT_PTR            WPARAM;
typedef LONG_PTR            LPARAM;
typedef LONG_PTR            LRESULT;
#define VOID void
typedef int                 BOOL;
typedef WORD                ATOM;
typedef unsigned char       BYTE;

typedef void *HANDLE;
typedef HANDLE HGLOBAL;
#define DECLARE_HANDLE(name) struct name##__{int unused;}; typedef struct name##__ *name
DECLARE_HANDLE(HINSTANCE);
DECLARE_HANDLE(HWND);
DECLARE_HANDLE(HDROP);
DECLARE_HANDLE(HICON);
DECLARE_HANDLE(HBRUSH);
DECLARE_HANDLE(HMENU);
DECLARE_HANDLE(HDC);
typedef HINSTANCE HMODULE;
typedef HICON HCURSOR;
typedef LONG HRESULT;

#define CALLBACK __stdcall
#define WINAPI __stdcall
#define WINBASEAPI __declspec(dllimport)
#define WINUSERAPI __declspec(dllimport)
#define DECLSPEC_IMPORT __declspec(dllimport)
#define STDAPICALLTYPE __stdcall
#define SHSTDAPI_(type) DECLSPEC_IMPORT type STDAPICALLTYPE
#define WINGDIAPI DECLSPEC_IMPORT
#define STDAPI extern "C" HRESULT STDAPICALLTYPE
#define DECLSPEC_NORETURN __declspec(noreturn)

typedef int (WINAPI *FARPROC)();
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);

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

typedef struct tagPOINT {
    LONG  x;
    LONG  y;
} POINT;

typedef struct tagMSG {
    HWND        hwnd;
    unsigned    message;
    WPARAM      wParam;
    LPARAM      lParam;
    DWORD       time;
    POINT       pt;
#ifdef _MAC
    DWORD       lPrivate;
#endif
} MSG;

typedef struct tagWINDOWPOS {
    HWND    hwnd;
    HWND    hwndInsertAfter;
    int     x;
    int     y;
    int     cx;
    int     cy;
    UINT    flags;
} WINDOWPOS;

typedef struct tagRECT {
    LONG    left;
    LONG    top;
    LONG    right;
    LONG    bottom;
} RECT;

typedef struct _POINTL {
    LONG x;
    LONG y;
} POINTL;

typedef struct tagWNDCLASSA {
    UINT        style;
    WNDPROC     lpfnWndProc;
    int         cbClsExtra;
    int         cbWndExtra;
    HINSTANCE   hInstance;
    HICON       hIcon;
    HCURSOR     hCursor;
    HBRUSH      hbrBackground;
    char const *lpszMenuName;
    char const *lpszClassName;
} WNDCLASSA;
typedef WNDCLASSA WNDCLASS;

typedef struct _devicemodeA {
    #define CCHDEVICENAME 32
    BYTE dmDeviceName[CCHDEVICENAME];
    WORD dmSpecVersion;
    WORD dmDriverVersion;
    WORD dmSize;
    WORD dmDriverExtra;
    DWORD dmFields;
    union {
        /* printer only fields */
        struct {
            short dmOrientation;
            short dmPaperSize;
            short dmPaperLength;
            short dmPaperWidth;
            short dmScale;
            short dmCopies;
            short dmDefaultSource;
            short dmPrintQuality;
        };
        /* display only fields */
        struct {
            POINTL dmPosition;
            DWORD  dmDisplayOrientation;
            DWORD  dmDisplayFixedOutput;
        };
    };
    short dmColor;
    short dmDuplex;
    short dmYResolution;
    short dmTTOption;
    short dmCollate;
    #define CCHFORMNAME 32
    BYTE   dmFormName[CCHFORMNAME];
    WORD   dmLogPixels;
    DWORD  dmBitsPerPel;
    DWORD  dmPelsWidth;
    DWORD  dmPelsHeight;
    union {
        DWORD  dmDisplayFlags;
        DWORD  dmNup;
    };
    DWORD  dmDisplayFrequency;
    DWORD  dmICMMethod;
    DWORD  dmICMIntent;
    DWORD  dmMediaType;
    DWORD  dmDitherType;
    DWORD  dmReserved1;
    DWORD  dmReserved2;
    DWORD  dmPanningWidth;
    DWORD  dmPanningHeight;
} DEVMODEA;
typedef DEVMODEA DEVMODE;

typedef struct tagBITMAPINFOHEADER{
    DWORD      biSize;
    LONG       biWidth;
    LONG       biHeight;
    WORD       biPlanes;
    WORD       biBitCount;
    DWORD      biCompression;
    DWORD      biSizeImage;
    LONG       biXPelsPerMeter;
    LONG       biYPelsPerMeter;
    DWORD      biClrUsed;
    DWORD      biClrImportant;
} BITMAPINFOHEADER;

typedef struct tagRGBQUAD {
    BYTE    rgbBlue;
    BYTE    rgbGreen;
    BYTE    rgbRed;
    BYTE    rgbReserved;
} RGBQUAD;

typedef struct tagBITMAPINFO {
    BITMAPINFOHEADER    bmiHeader;
    RGBQUAD             bmiColors[1];
} BITMAPINFO;

typedef struct tagWINDOWPLACEMENT {
    UINT  length;
    UINT  flags;
    UINT  showCmd;
    POINT ptMinPosition;
    POINT ptMaxPosition;
    RECT  rcNormalPosition;
} WINDOWPLACEMENT;

typedef struct _OVERLAPPED {
    ULONG_PTR Internal;
    ULONG_PTR InternalHigh;
    union {
        struct {
            DWORD Offset;
            DWORD OffsetHigh;
        } DUMMYSTRUCTNAME;
        void *Pointer;
    } DUMMYUNIONNAME;

    HANDLE  hEvent;
} OVERLAPPED;

typedef struct _SECURITY_ATTRIBUTES {
    DWORD nLength;
    void *securityDescriptor;
    BOOL bInheritHandle;
} SECURITY_ATTRIBUTES;


// Clipboard.
#define CF_TEXT             1
WINUSERAPI int WINAPI OpenClipboard(HWND hWndNewOwner);
WINUSERAPI int WINAPI CloseClipboard(void);
WINUSERAPI HANDLE WINAPI GetClipboardData(unsigned uFormat);
WINUSERAPI int WINAPI EmptyClipboard(void);
WINUSERAPI HANDLE WINAPI SetClipboardData(unsigned uFormat, HANDLE hMem);

// Locks.
WINBASEAPI void * WINAPI GlobalLock(HGLOBAL hMem);
WINBASEAPI int WINAPI GlobalUnlock(HGLOBAL hMem);

// Window handle.
WINUSERAPI int WINAPI ScreenToClient(HWND hWnd, POINT *point);
WINUSERAPI HWND WINAPI GetDesktopWindow(VOID);
WINUSERAPI BOOL WINAPI GetWindowRect(HWND hWnd, RECT *rect);
#define GetModuleHandle GetModuleHandleA
WINBASEAPI HMODULE WINAPI GetModuleHandleA(char const *moduleName);
#define RegisterClass RegisterClassA
WINUSERAPI ATOM WINAPI RegisterClassA(WNDCLASSA const *wndClass);
#define ChangeDisplaySettings ChangeDisplaySettingsA
#define CreateWindow CreateWindowA
#define CreateWindowA(className, windowName, style, x, y, \
    nWidth, nHeight, hWndParent, hMenu, hInstance, param)\
    CreateWindowExA(0L, className, windowName, style, x, y, \
    nWidth, nHeight, hWndParent, hMenu, hInstance, param)
WINUSERAPI HWND WINAPI CreateWindowExA(DWORD exStyle, char const *className, char const *windowName,
    DWORD style, int x, int y, int width, int height,
    HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, void *param);
WINUSERAPI BOOL WINAPI DestroyWindow(HWND hWnd);
WINUSERAPI BOOL WINAPI GetWindowPlacement(HWND hWnd, WINDOWPLACEMENT *wndpl);
WINUSERAPI BOOL WINAPI ShowWindow(HWND hWnd, int nCmdShow);
WINUSERAPI BOOL WINAPI BringWindowToTop(HWND hWnd);
WINUSERAPI BOOL WINAPI SetForegroundWindow(HWND hWnd);
#define SetWindowText SetWindowTextA
WINUSERAPI BOOL WINAPI SetWindowTextA(HWND hWnd, char const *string);

// Device context.
WINUSERAPI HDC WINAPI GetDC(HWND hWnd);
WINGDIAPI int WINAPI SetDIBitsToDevice(HDC hdc, int xDest, int yDest, DWORD w, DWORD h, int xSrc,
    int ySrc, UINT StartScan, UINT cLines, const void *vBits, const BITMAPINFO *bmi, UINT ColorUse);
WINUSERAPI int WINAPI ReleaseDC(HWND hWnd, HDC hDC);

WINUSERAPI HANDLE WINAPI LoadImageA(HINSTANCE hInst, char const *name, UINT type, int cx, int cy, UINT fuLoad);


// Misc.
#define OutputDebugString OutputDebugStringA
WINBASEAPI void WINAPI OutputDebugStringA(char const *outputString);

WINUSERAPI SHORT WINAPI GetAsyncKeyState(int vKey);
WINUSERAPI LONG WINAPI ChangeDisplaySettingsA(DEVMODEA *devMode, DWORD flags);
WINUSERAPI BOOL WINAPI AdjustWindowRect(RECT *rect, DWORD style, BOOL menu);
WINBASEAPI DECLSPEC_NORETURN VOID WINAPI ExitProcess(UINT exitCode);

// Load DLL.
#define LoadLibrary LoadLibraryA
WINBASEAPI HMODULE WINAPI LoadLibraryA(char const *libFileName);
WINBASEAPI FARPROC WINAPI GetProcAddress(HMODULE hModule, char const *procName);

// Mouse.
#define HTCLIENT 1
WINUSERAPI int WINAPI GetCursorPos(POINT *point);
WINUSERAPI HWND WINAPI SetCapture(HWND hWnd);
WINUSERAPI BOOL WINAPI ReleaseCapture(VOID);
WINUSERAPI int WINAPI ShowCursor(BOOL bShow);
WINUSERAPI HCURSOR WINAPI SetCursor(HCURSOR hCursor);
#define LoadCursor LoadCursorA
WINUSERAPI HCURSOR WINAPI LoadCursorA(HINSTANCE hInstance, char const *cursorName);

// Messages.
#define PM_REMOVE 1
#define PeekMessage PeekMessageA
#define DispatchMessage DispatchMessageA
#define SendMessage SendMessageA
#define DefWindowProc DefWindowProcA
WINUSERAPI int WINAPI PeekMessage(MSG *msg, HWND hWnd, unsigned wMsgFilterMin, unsigned wMsgFilterMax, unsigned wRemoveMsg);
WINUSERAPI int WINAPI TranslateMessage(const MSG *msg);
WINUSERAPI LRESULT WINAPI DispatchMessageA(const MSG *msg);
WINUSERAPI LRESULT WINAPI SendMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
WINUSERAPI LRESULT WINAPI DefWindowProcA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

// Timing.
WINBASEAPI int WINAPI QueryPerformanceCounter(LARGE_INTEGER *performanceCount);
WINBASEAPI int WINAPI QueryPerformanceFrequency(LARGE_INTEGER *frequency);
WINBASEAPI void WINAPI Sleep(DWORD milliseconds);

// Memory allocation / free.
#define GMEM_DDESHARE 0x2000
WINBASEAPI HGLOBAL WINAPI GlobalAlloc(unsigned flags, size_t numBytes);
WINBASEAPI HANDLE WINAPI GetProcessHeap(void);
WINBASEAPI HANDLE WINAPI HeapCreate(DWORD flOptions, size_t initialSize, size_t maximumSize);
WINBASEAPI void * WINAPI HeapAlloc(HANDLE hHeap, DWORD dwFlags, size_t bytes);
WINBASEAPI int WINAPI HeapFree(HANDLE hHeap, DWORD dwFlags,void *mem);

// File IO.
WINBASEAPI BOOL WINAPI CloseHandle(HANDLE hObject);
WINBASEAPI HANDLE WINAPI CreateFileA(const char *fileName, DWORD desiredAccess, DWORD shareMode,
                                     SECURITY_ATTRIBUTES *securityAttributes, DWORD dwCreationDisposition, 
                                     DWORD flagsAndAttributes, HANDLE hTemplateFile);
WINBASEAPI BOOL WINAPI ReadFile(HANDLE file, void *buf, DWORD numBytesToRead, DWORD *numBytesRead, OVERLAPPED *overlapped);
WINBASEAPI DWORD WINAPI SetFilePointer(HANDLE hFile, LONG distanceToMove, LONG *distanceToMoveHigh, DWORD moveMethod);

// Alloc/free.
//WINBASEAPI void * WINAPI VirtualAlloc(void *lpAddress, size_t dwSize, DWORD flAllocationType, DWORD flProtect);
//WINBASEAPI BOOL WINAPI VirtualFree(void *addr, size_t size, DWORD freeType);
WINBASEAPI HANDLE WINAPI GetProcessHeap(void);
WINBASEAPI void * WINAPI HeapAlloc(HANDLE hHeap, DWORD flags, size_t numBytes);
WINBASEAPI void * WINAPI HeapReAlloc(HANDLE hHeap, DWORD flags, void *mem, size_t numBytes);


#ifdef __cplusplus
}
#endif
