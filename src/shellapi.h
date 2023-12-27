#pragma once


#include "windows.h"


#ifdef __cplusplus
extern "C"
{
#endif


// Drag and drop.
#define DragQueryFile DragQueryFileA
SHSTDAPI_(UINT) DragQueryFileA(HDROP hDrop, UINT iFile, char *file, UINT cch);
SHSTDAPI_(void) DragAcceptFiles(HWND hWnd, BOOL fAccept);

#ifdef __cplusplus
}
#endif
