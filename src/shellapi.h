#pragma once


#include "windows.h"


#ifdef __cplusplus
extern "C"
{
#endif


unsigned DragQueryFile(HDROP hDrop, unsigned iFile, char *file, unsigned cch);


#ifdef __cplusplus
}
#endif
