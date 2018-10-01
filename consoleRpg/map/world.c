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
	return w;
}
void world_destroy(p_world w)
{
	entitylist_destroy(w->entities);
	free(w);
}

void world_save(p_world w, FILE* file)
{
	// ToDo
}
void world_load(p_world w, FILE* file)
{
	// ToDo
}