#include "world_render.h"
#include "../console/render.h"

#include <malloc.h>


void world_render(p_world w, p_tilelist tiles, tile* buff, unsigned int buffw, p_viewport view)
{
	if (w->width == 0 || w->height == 0)
	{
		return;
	}
	if (view->x + view->w > w->width) { view->x = w->width - view->w; }
	if (view->x < 0) { view->x = 0; }
	if (view->y + view->h > w->height) { view->y = w->height - view->h; }
	if (view->y < 0) { view->y = 0; }

	//Set background to gray
	for (unsigned int y = 0; y < view->h; y++)
	{
		for (unsigned int x = 0; x < view->w; x++)
		{
			buff[y * buffw + x].icon = ' ';
			buff[y * buffw + x].color = BACKGROUND_GRAY;
		}
	}

	for (unsigned int x = view->x; x < view->x + view->w; x++)
	{
		for (unsigned int y = view->y; y < view->y + view->h; y++)
		{
			unsigned int viewindex = VIEW_INDEX(view, buffw, x, y);
			unsigned int worldindex = WORLD_INDEX(w, x, y);
			if (w->blocks[worldindex].tileid == (unsigned int)~0)
			{
				continue;
			}
			buff[viewindex] = tiles->data[w->blocks[worldindex].tileid];
		}
	}
	for (unsigned int i = 0; i < w->entities->top; i++)
	{
		p_entity ent = w->entities->data[i];
		if (
			ent->tileid >= tiles->top ||
			view->x > ent->posx ||
			view->x + view->w <= ent->posx ||
			view->y > ent->posy ||
			view->y + view->h <= ent->posy
			)
		{
			continue;
		}
		buff[(ent->posy - view->y) * buffw + (ent->posx - view->x)] = tiles->data[ent->tileid];
	}
}