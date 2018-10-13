#pragma once
#include "world.h"
#include "../console/tile.h"

typedef struct
{
	int x;
	int y;
	int w;
	int h;
} viewport;
typedef viewport* p_viewport;
#define VIEW_INDEX(V,W,X,Y) (((Y) - (V)->y) * (W) + ((X) - (V)->x))

// ToDo: Introduce proper world-renderer that will allow for stuff
//       like viewport.

// Creates a buffer, capable of holding the whole world.
// Needs to be recreated as soon as the width or heigth of the world changes.

void world_render(p_world, p_tilelist, tile*, unsigned int, p_viewport);