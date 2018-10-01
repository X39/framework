#include "world_render.h"

#include <malloc.h>


tile** world_render_create_buff(p_world w)
{
	if (w->width == 0 || w->height == 0)
	{
		return NULL;
	}
	tile** buff = malloc(sizeof(tile*) * (w->height + 1));
	if (buff == NULL)
	{
		return NULL;
	}
	for (unsigned int i = 0; i < w->height; i++)
	{
		buff[i] = malloc(sizeof(tile) * w->width);
		buff[i][w->width].color = -1;
		buff[i][w->width].icon = '\0';
		if (buff[i] == NULL)
		{
			for (; i != ~0; i--)
			{
				free(buff[i]);
			}
			return NULL;
		}
	}
	buff[w->height] = NULL;
	world_render_clear_buff(w, buff);
	return buff;
}
void world_render_clear_buff(p_world w, tile** buff)
{
	for (unsigned int i = 0; i < w->height; i++)
		for (unsigned int j = 0; j < w->width; j++)
		{
			if (buff[i][j].icon != ' ')
			{
				buff[i][j].icon = ' ';
			}
		}
}
void world_render_destroy_buff(tile** buff)
{
	for (unsigned int i = 0; buff[i]; i++)
	{
		free(buff[i]);
	}
	free(buff);
}

void world_render(p_world w, p_tilelist tiles, tile** buff)
{
	if (w->width == 0 || w->height == 0)
	{
		return;
	}
	world_render_clear_buff(w, buff);
	for (unsigned int i = 0; i < w->entities->top; i++)
	{
		p_entity ent = w->entities->data[i];
		if (ent->posx >= w->width || ent->posy >= w->height || ent->tileid >= tiles->top)
		{
			continue;
		}
		buff[ent->posy][ent->posx] = tiles->data[ent->tileid];
	}
	char* linebuff = alloca(sizeof(char) * (w->height * (w->width + 1) + 1));
	linebuff[w->height * (w->width + 1)] = '\0';
	for (unsigned int i = 0, j = 0; i < w->height; i++)
	{
		for (j = 0; j < w->width; j++)
		{
			linebuff[i * w->width + j + i] = buff[i][j].icon;
		}
		linebuff[i * w->width + j + i] = '\n';
	}
	printf("%s", linebuff);
}