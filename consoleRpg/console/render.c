#include "render.h"

#if defined(_WIN32)
#include <Windows.h>
#include <malloc.h>
#else
#error NO IMP
#endif

dimensions get_dimensions(void)
{
	dimensions dim;

#if defined(_WIN32)
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	dim.width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	dim.height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
#else
#error NO IMP
#endif

	return dim;
}
consoleref get_console(void)
{
	return GetStdHandle(STD_OUTPUT_HANDLE);
}

void set_console_tiles(consoleref console, const tile** tarr, dimensions dim)
{
#if defined(_WIN32)
	COORD dwBufferSize = { dim.width, dim.height };
	COORD dwBufferCoord = { 0, 0 };
	SMALL_RECT rcRegion = { 0, 0, dim.width - 1, dim.height - 1 };

	PCHAR_INFO buffer = alloca(sizeof(CHAR_INFO) * (dim.height * dim.width));
	for (unsigned int x = 0; x < dim.width; x++)
	{
		for (unsigned int y = 0; y < dim.height; y++)
		{
			buffer[y * dim.width + x].Char.AsciiChar = tarr[y][x].icon;
			buffer[y * dim.width + x].Attributes = tarr[y][x].color;
		}
	}
	WriteConsoleOutput(console, buffer, dwBufferSize, dwBufferCoord, &rcRegion);
#else
#error NO IMP
#endif
}