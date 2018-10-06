#pragma once

#include "tile.h"


typedef struct
{
	unsigned int width;
	unsigned int height;
} dimensions;


#if defined(_WIN32)
#include <Windows.h>
typedef HANDLE consoleref;
#else
#error NO IMP
#endif

dimensions get_dimensions(void);
consoleref get_console(void);
void set_console_tiles(consoleref console, const tile** tarr, dimensions dim);
