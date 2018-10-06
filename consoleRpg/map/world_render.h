#pragma once
#include "world.h"
#include "../console/tile.h"

// ToDo: Introduce proper world-renderer that will allow for stuff
//       like viewport.

// Creates a buffer, capable of holding the whole world.
// Needs to be recreated as soon as the width or heigth of the world changes.
tile* world_render_create_buff(p_world);
void world_render_destroy_buff(tile*);
void world_render_clear_buff(p_world, tile*);

void world_render(p_world, p_tilelist, tile*);