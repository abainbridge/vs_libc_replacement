#pragma once


#include <windows.h>


#ifdef __cplusplus
extern "C"
{
#endif


typedef enum PROCESS_DPI_AWARENESS {
    PROCESS_DPI_UNAWARE = 0,
    PROCESS_SYSTEM_DPI_AWARE = 1,
    PROCESS_PER_MONITOR_DPI_AWARE = 2
} PROCESS_DPI_AWARENESS;


STDAPI SetProcessDpiAwareness(PROCESS_DPI_AWARENESS value);


#ifdef __cplusplus
}
#endif
