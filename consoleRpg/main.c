#include <stdio.h>
#include <stdlib.h>

#include "key/keys_qwertz_german.h"
#include "map/world.h"
#include "map/world_render.h"
#include "map/tile.h"



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
bool cb_key_move(keycode k, void* data)
{
	p_entity ent = data;
	switch (k)
	{
		case KEY_UPARROW:
			if (ent->posy == 0)
			{
				ent->posy = 30;
			}
			else
			{
				ent->posy--;
			}
			return true;
		case KEY_DOWNARROW:
			if (ent->posy == 30)
			{
				ent->posy = 0;
			}
			else
			{
				ent->posy++;
			}
			return true;
		case KEY_LEFTARROW:
			if (ent->posx == 0)
			{
				ent->posx = 120;
			}
			else
			{
				ent->posx--;
			}
			return true;
		case KEY_RIGHTARROW:
			if (ent->posx == 120)
			{
				ent->posx = 0;
			}
			else
			{
				ent->posx++;
			}
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
	p_tilelist tiles = tilelist_create();
	tilelist_push(tiles, (tile) { 'X', 0 });
	tilelist_push(tiles, (tile) { '@', 0 });
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

	keylist_push(klist, KEY_ANY, cb_key_any, NULL);
	keylist_push(klist, KEY_ESC, cb_key_esc, &exit);
	keylist_push(klist, KEY_UPARROW, cb_key_move, ent);
	keylist_push(klist, KEY_DOWNARROW, cb_key_move, ent);
	keylist_push(klist, KEY_RIGHTARROW, cb_key_move, ent);
	keylist_push(klist, KEY_LEFTARROW, cb_key_move, ent);


	world->width = 120;
	world->height = 30;
	tile** buff = world_render_create_buff(world);
	while (!exit)
	{
		world_render(world, tiles, buff);
		keylist_handle(klist, get_key());
		system("cls");
	}

	keylist_destroy(klist);
}