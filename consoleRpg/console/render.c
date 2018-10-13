#include "render.h"

#if defined(_WIN32)
#include <Windows.h>
#include <malloc.h>
#else
#error NO IMP
#endif

dimensions get_console_dimensions(void)
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
tile* create_console_buffer(void)
{
	dimensions dim = get_console_dimensions();
	return malloc(sizeof(tile) * (dim.height * dim.width));
}
void clear_console_buffer(dimensions dim, tile* buff)
{
	for (unsigned int y = 0; y < dim.height; y++)
	{
		for (unsigned int x = 0; x < dim.width; x++)
		{
			buff[y * dim.width + x].icon = ' ';
			buff[y * dim.width + x].color = BACKGROUND_BLACK;
		}
	}
}

void set_console_tiles(consoleref console, const tile* tarr, dimensions dim)
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
			buffer[y * dim.width + x].Char.AsciiChar = tarr[y * dim.width + x].icon;
			buffer[y * dim.width + x].Attributes = tarr[y * dim.width + x].color;
		}
	}
	WriteConsoleOutput(console, buffer, dwBufferSize, dwBufferCoord, &rcRegion);
#else
#error NO IMP
#endif
}