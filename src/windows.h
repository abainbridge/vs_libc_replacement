#pragma once


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
typedef HINSTANCE HMODULE;
typedef HICON HCURSOR;

#define CALLBACK __stdcall
#define WINAPI __stdcall
#define WINBASEAPI __declspec(dllimport)
#define WINUSERAPI __declspec(dllimport)
#define DECLSPEC_IMPORT __declspec(dllimport)
#define STDAPICALLTYPE __stdcall
#define SHSTDAPI_(type) DECLSPEC_IMPORT type STDAPICALLTYPE

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

// Misc.
WINBASEAPI void WINAPI OutputDebugString(char *outputString);
WINUSERAPI SHORT WINAPI GetAsyncKeyState(int vKey);
WINUSERAPI int WINAPI ScreenToClient(HWND hWnd, POINT *point);
#define DragQueryFile DragQueryFileA
SHSTDAPI_(UINT) DragQueryFileA(HDROP hDrop, UINT iFile, char *file, UINT cch);
WINUSERAPI HWND WINAPI GetDesktopWindow(VOID);
WINUSERAPI BOOL WINAPI GetWindowRect(HWND hWnd, RECT *rect);
#define GetModuleHandle  GetModuleHandleA
WINBASEAPI HMODULE WINAPI GetModuleHandleA(char *moduleName);
#define RegisterClass RegisterClassA
WINUSERAPI ATOM WINAPI RegisterClassA(WNDCLASSA const *wndClass);
#define ChangeDisplaySettings ChangeDisplaySettingsA
WINUSERAPI LONG WINAPI ChangeDisplaySettingsA(DEVMODEA *devMode, DWORD dwFlags);
WINUSERAPI BOOL WINAPI AdjustWindowRect(RECT *rect, DWORD dwStyle, BOOL bMenu);

// Load DLL.
#define LoadLibrary  LoadLibraryA
WINBASEAPI HMODULE WINAPI LoadLibraryA(char *libFileName);
WINBASEAPI FARPROC WINAPI GetProcAddress(HMODULE hModule, char *procName);

// Mouse.
#define HTCLIENT 1
WINUSERAPI int WINAPI GetCursorPos(POINT *point);
WINUSERAPI HWND WINAPI SetCapture(HWND hWnd);
WINUSERAPI BOOL WINAPI ReleaseCapture(VOID);

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
WINBASEAPI HGLOBAL WINAPI GlobalAlloc(unsigned uFlags, size_t dwBytes);
WINBASEAPI HANDLE WINAPI GetProcessHeap(void);
WINBASEAPI void * WINAPI HeapAlloc(HANDLE hHeap, DWORD dwFlags, size_t bytes);
WINBASEAPI int WINAPI HeapFree(HANDLE hHeap, DWORD dwFlags,void *mem);



#ifdef __cplusplus
}
#endif
