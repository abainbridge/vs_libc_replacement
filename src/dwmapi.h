#pragma once

#ifdef __cplusplus
extern "C"
{
#endif


#define MONITOR_DEFAULTTONEAREST    0x00000002

    WINUSERAPI
        HMONITOR
        WINAPI
        MonitorFromWindow(
        _In_ HWND hwnd,
        _In_ DWORD dwFlags);


#ifdef __cplusplus
}
#endif
