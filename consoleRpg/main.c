#include <stdio.h>
#include <stdlib.h>

#include "console/keys_qwertz_german.h"
#include "map/world.h"
#include "map/world_render.h"
#include "console/tile.h"



bool cb_key_any(keycode k, void* data)
{
	if ((k >= KEY_0 && k <= KEY_9) || (k >= KEY_A_BIG && k <= KEY_Z_BIG) || (k >= KEY_A_LOW && k <= KEY_Z_LOW))
	{
		printf("%c", k >> 8);
		return true;
	}
	else if (k == KEY_ENTER)
	{
		printf("\n");
		return true;
	}
	else if (k == KEY_BACKSPACE)
	{
		printf("\b \b");
		return true;
	}
	return false;
}
bool cb_key_esc(keycode k, void* data)
{
	*((bool*)data) = true;
	return true;
}
typedef struct
{
	p_entity ent;
	p_world w;
} cb_key_move_data;
bool cb_key_move(keycode k, void* data)
{
	p_entity ent = ((cb_key_move_data*)data)->ent;
	p_world w = ((cb_key_move_data*)data)->w;
	switch (k)
	{
		case KEY_UPARROW:
			world_moveentity(w, ent, MOVE_UP);
			return true;
		case KEY_DOWNARROW:
			world_moveentity(w, ent, MOVE_DOWN);
			return true;
		case KEY_LEFTARROW:
			world_moveentity(w, ent, MOVE_LEFT);
			return true;
		case KEY_RIGHTARROW:
			world_moveentity(w, ent, MOVE_RIGHT);
			return true;
	}
	return false;
}

int main(int argc, char** argv)
{
	const int worldsize_x = 200;
	const int worldsize_y = 200;
	const int entity_count = 200;
	const int viewport_dim_x = 40;
	const int viewport_dim_y = 20;

	int i;
	p_keylist klist = keylist_create();
	viewport view = {
		0,
		0,
		viewport_dim_x,
		viewport_dim_y
	};
	bool exit = false;
	p_world world = world_create();
	world_resize(world, worldsize_x, worldsize_y);
	p_tilelist tiles = tilelist_create();
	/* 0 */ tilelist_push(tiles, (tile) { 'X', FOREGROUND_BLACK | BACKGROUND_GRAY  });
	/* 1 */ tilelist_push(tiles, (tile) { '@', FOREGROUND_YELLOW | BACKGROUND_GRAY  });
	/* 2 */ tilelist_push(tiles, (tile) { (char)218, FOREGROUND_GREEN | BACKGROUND_GRAY }); //Top-Left
	/* 3 */ tilelist_push(tiles, (tile) { (char)217, FOREGROUND_GREEN | BACKGROUND_GRAY }); //Bot-Right
	/* 4 */ tilelist_push(tiles, (tile) { (char)192, FOREGROUND_GREEN | BACKGROUND_GRAY }); //Bot-Left
	/* 5 */ tilelist_push(tiles, (tile) { (char)191, FOREGROUND_GREEN | BACKGROUND_GRAY }); //Top-Right
	/* 6 */ tilelist_push(tiles, (tile) { (char)179, FOREGROUND_GREEN | BACKGROUND_GRAY }); //Straight-UpDown
	/* 7 */ tilelist_push(tiles, (tile) { (char)196, FOREGROUND_GREEN | BACKGROUND_GRAY }); //Straight-LeftRight
	p_entity ent;
	for (i = 0; i < entity_count - 1; i++)
	{
		ent = entity_create();
		ent->tileid = 0;
		ent->posx = rand() % worldsize_x;
		ent->posy = rand() % worldsize_y;
		entitylist_push(world->entities, ent);
	}
	ent = entity_create();
	ent->tileid = 0;
	ent->posx = worldsize_x / 2;
	ent->posy = worldsize_y / 2;
	ent->tileid = 1;
	entitylist_push(world->entities, ent);

	for (unsigned int x = 0; x < world->width; x++)
	{
		for (unsigned int y = 0; y < world->height; y++)
		{
			if (x == 0 || y == 0 || x == world->width - 1 || y == world->height - 1)
			{
				world->blocks[WORLD_INDEX(world, x, y)].passable = false;
				world->blocks[WORLD_INDEX(world, x, y)].tileid =
					(x == 0 && y == 0) ? 2 :
					(x == world->width - 1 && y == world->height - 1) ? 3 :
					(x == 0 && y == world->height - 1) ? 4 :
					(x == world->width - 1 && y == 0) ? 5 :
					(x == 0 && y != world->height - 1) ? 6 :
					(x == world->width - 1 && y != world->height - 1) ? 6 :
					7;
			}
		}
	}

	cb_key_move_data move_data = { ent, world };
	keylist_push(klist, KEY_ANY, cb_key_any, NULL);
	keylist_push(klist, KEY_ESC, cb_key_esc, &exit);
	keylist_push(klist, KEY_UPARROW, cb_key_move, &move_data);
	keylist_push(klist, KEY_DOWNARROW, cb_key_move, &move_data);
	keylist_push(klist, KEY_RIGHTARROW, cb_key_move, &move_data);
	keylist_push(klist, KEY_LEFTARROW, cb_key_move, &move_data);

	tile* buff = world_render_create_buff(&view);
	while (!exit)
	{
		view.x = ent->posx - viewport_dim_x / 2;
		view.y = ent->posy - viewport_dim_y / 2;
		world_render(world, tiles, buff, &view);
		keylist_handle(klist, get_key());
		//system("cls");
	}

	keylist_destroy(klist);
}