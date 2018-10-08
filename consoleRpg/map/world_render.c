#include "world_render.h"
#include "../console/render.h"

#include <malloc.h>


tile* world_render_create_buff(p_world w)
{
	if (w->width == 0 || w->height == 0)
	{
		return NULL;
	}
	tile** buff = malloc(sizeof(tile) * (w->height * w->width));
	if (buff == NULL)
	{
		return NULL;
	}
	world_render_clear_buff(w, buff);
	return buff;
}
void world_render_clear_buff(p_world w, tile* buff)
{
	for (unsigned int y = 0; y < w->height; y++)
	{
		for (unsigned int x = 0; x < w->width; x++)
		{
			buff[y * w->width + x].icon = ' ';
			buff[y * w->width + x].color = 0;
		}
	}
}
void world_render_destroy_buff(tile* buff)
{
	free(buff);
}

void world_render(p_world w, p_tilelist tiles, tile* buff)
{
	if (w->width == 0 || w->height == 0)
	{
		return;
	}
	world_render_clear_buff(w, buff);
	for (unsigned int x = 0; x < w->width; x++)
	{
		for (unsigned int y = 0; y < w->height; y++)
		{
			unsigned int index = WORLD_INDEX(w, x, y);
			if (w->blocks[index].tileid == (unsigned int)~0)
			{
				continue;
			}
			buff[index] = tiles->data[w->blocks[index].tileid];
		}
	}
	for (unsigned int i = 0; i < w->entities->top; i++)
	{
		p_entity ent = w->entities->data[i];
		if (ent->posx >= w->width || ent->posy >= w->height || ent->tileid >= tiles->top)
		{
			continue;
		}
		buff[ent->posy * w->width + ent->posx] = tiles->data[ent->tileid];
	}
	dimensions dim = { w->width, w->height };
	set_console_tiles(get_console(), buff, dim);
}