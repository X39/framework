#include "control.h"
#include <malloc.h>
#include <string.h>

#define G_LIST_NAME controllist
#define G_LIST_INNERTYPE p_control
#define G_LIST_CODE_DESTROY for (int i = 0; i < list->top; i++)\
								list->data[i]->vtable.destroy(list->data[i]);
#include "../generic/g_list.c.txt"
#undef G_LIST_NAME
#undef G_LIST_INNERTYPE
#undef G_LIST_CODE_DESTROY

p_control control_create(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{
	p_control cntrl = malloc(sizeof(control));
	memset(cntrl, 0, sizeof(cntrl));
	struct control_geometry geo = { x, y, width, height };
	cntrl->geometry = geo;
	cntrl->vtable.destroy = NULL;
	return cntrl;
}

void control_destroy(p_control cntrl)
{
	if (cntrl->vtable.destroy != NULL)
	{
		cntrl->vtable.destroy(cntrl);
	}
	free(cntrl);
}

void textblock_destroy(p_control cntrl)
{
	free(cntrl->data.textblock.text);
}
void textblock_render(p_control cntrl, tile* buff, size_t width, size_t height)
{
	//Render box
	for (unsigned int x = cntrl->geometry.x; x < cntrl->geometry.x + cntrl->geometry.width && x < width; x++)
	{
		for (unsigned int y = cntrl->geometry.y; y < cntrl->geometry.y + cntrl->geometry.height && y < height; y++)
		{
			if (
				x == cntrl->geometry.x ||
				y == cntrl->geometry.y ||
				x == cntrl->geometry.x + cntrl->geometry.width - 1 ||
				y == cntrl->geometry.y + cntrl->geometry.height - 1
				)
			{
				buff[RENDER_INDEX(width, x, y)].color = BACKGROUND_BLACK | FOREGROUND_RED_DARK;
				buff[RENDER_INDEX(width, x, y)].icon = '#';
			}
			else
			{
				buff[RENDER_INDEX(width, x, y)].color = BACKGROUND_BLACK | FOREGROUND_WHITE;
				buff[RENDER_INDEX(width, x, y)].icon = ' ';
			}
		}
	}
	//Count lines
	unsigned int lineCount = 0;
	unsigned int maxLines = cntrl->geometry.height - 2;
	for (unsigned int i = 0; i < cntrl->data.textblock.textlen; i++)
	{
		if (cntrl->data.textblock.text[i] == '\n')
		{
			lineCount++;
		}
	}
	if (lineCount > maxLines)
	{
		lineCount = maxLines;
	}

	//Render lines
	unsigned int posX = cntrl->geometry.x + 1;
	unsigned int posY = cntrl->geometry.y + 1;
	unsigned int line = 0;
	for (unsigned int i = 0; i < cntrl->data.textblock.textlen; i++)
	{
		if (cntrl->data.textblock.text[i] == '\n')
		{
			if (++line == lineCount)
			{
				break;
			}
			else
			{
				posY++;
				posX = cntrl->geometry.x + 1;
				continue;
			}
		}
		if (posX == cntrl->geometry.x + cntrl->geometry.width)
		{
			continue;
		}
		buff[RENDER_INDEX(width, posX, posY)].icon = cntrl->data.textblock.text[i];
		posX++;
	}
}
p_control control_create_textblock(unsigned int x, unsigned int y, unsigned int width, unsigned int height, char* text)
{
	if (height < 3)
	{
		height = 3;
	}
	if (width < 3)
	{
		width = 3;
	}
	p_control cntrl = control_create(x, y, width, height);
	cntrl->data.textblock.textlen = strlen(text);
	cntrl->data.textblock.text = malloc(sizeof(char) * (cntrl->data.textblock.textlen + 1));
	strcpy(cntrl->data.textblock.text, text);
	cntrl->vtable.destroy = textblock_destroy;
	cntrl->vtable.render = textblock_render;
	return cntrl;
}