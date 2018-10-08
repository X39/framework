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
	int i;
	p_keylist klist = keylist_create();
	bool exit = false;
	p_world world = world_create();
	world_resize(world, 120, 20);
	p_tilelist tiles = tilelist_create();
	/* 0 */ tilelist_push(tiles, (tile) { 'X', FOREGROUND_GRAY });
	/* 1 */ tilelist_push(tiles, (tile) { '@', FOREGROUND_CYAN });
	/* 2 */ tilelist_push(tiles, (tile) { (char)218, FOREGROUND_GREEN }); //Top-Left
	/* 3 */ tilelist_push(tiles, (tile) { (char)217, FOREGROUND_GREEN }); //Bot-Right
	/* 4 */ tilelist_push(tiles, (tile) { (char)192, FOREGROUND_GREEN }); //Bot-Left
	/* 5 */ tilelist_push(tiles, (tile) { (char)191, FOREGROUND_GREEN }); //Top-Right
	/* 6 */ tilelist_push(tiles, (tile) { (char)179, FOREGROUND_GREEN }); //Straight-UpDown
	/* 7 */ tilelist_push(tiles, (tile) { (char)196, FOREGROUND_GREEN }); //Straight-LeftRight
	p_entity ent;
	for (i = 0; i < 100; i++)
	{
		ent = entity_create();
		ent->tileid = 0;
		ent->posx = rand() % 120;
		ent->posy = rand() % 30;
		entitylist_push(world->entities, ent);
	}
	ent->tileid = 1;

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


	tile* buff = world_render_create_buff(world);
	while (!exit)
	{
		world_render(world, tiles, buff);
		keylist_handle(klist, get_key());
		system("cls");
	}

	keylist_destroy(klist);
}