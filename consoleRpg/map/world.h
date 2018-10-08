#pragma once

#include "entity.h"
#include "block.h"
#include <stdio.h>
#include <stdbool.h>

#define WORLD_INDEX(W,X,Y) ((Y) * (W)->width + (X))

typedef struct
{
	unsigned int width;
	unsigned int height;
	p_entitylist entities;
	block* blocks;
} world;

typedef world * p_world;

p_world world_create(void);
void world_destroy(p_world);
bool world_resize(p_world, unsigned int, unsigned int);



//Returns true if the move succeeded. False if it did not.
bool world_moveentity(p_world, p_entity, movedir);


void world_save(p_world, FILE*);
void world_load(p_world, FILE*);