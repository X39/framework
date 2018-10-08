#include "world.h"
#include <malloc.h>

p_world world_create(void)
{
	world * w = malloc(sizeof(world));
	if (w == NULL)
	{
		return NULL;
	}
	if (!(w->entities = entitylist_create()))
	{
		return NULL;
	}

	w->height = 0;
	w->width = 0;
	w->blocks = NULL;
	return w;
}
void world_destroy(p_world w)
{
	entitylist_destroy(w->entities);
	free(w);
}
bool world_resize(p_world w, unsigned int width, unsigned int height)
{
	block* blocks;
	if (width == 0 || height == 0)
	{
		if (w->blocks)
		{
			free(w->blocks);
			w->blocks = NULL;
		}
	}
	else
	{
		if (w->blocks)
		{
			blocks = realloc(w->blocks, sizeof(block) * (width * height));
		}
		else
		{
			blocks = malloc(sizeof(block) * (width * height));
		}
		if (blocks == NULL)
		{
			return false;
		}
		w->blocks = blocks;
		for (unsigned int x = w->width; x < width; x++)
		{
			for (unsigned int y = w->height; y < height; y++)
			{
				unsigned int index = y * width + x;
				w->blocks[index].tileid = (unsigned int)~0;
			}
		}
	}
	w->width = width;
	w->height = height;
	return true;
}
bool world_moveentity(p_world w, p_entity e, movedir dir)
{
	unsigned int x = e->posx;
	unsigned int y = e->posy;
	e->direction = dir;
	block* b;
	switch (dir)
	{
		case MOVE_UP: if (y == 0) return false; y--; break;
		case MOVE_DOWN: if (y == w->height) return false; y++; break;
		case MOVE_LEFT: if (x == 0) return false; x--; break;
		case MOVE_RIGHT: if (x == w->width) return false; x++; break;
		default: return false;
	}
	b = w->blocks + WORLD_INDEX(w, x, y);

	if (b->passable)
	{
		for (unsigned int i = 0; i < w->entities->top; i++)
		{
			if (w->entities->data[i]->posx == x && w->entities->data[i]->posy == y)
			{
				return false;
			}
		}
		e->posx = x;
		e->posy = y;
		return true;
	}
	return false;
}

void world_save(p_world w, FILE* file)
{
	// ToDo
}
void world_load(p_world w, FILE* file)
{
	// ToDo
}