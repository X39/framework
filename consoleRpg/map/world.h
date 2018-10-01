#pragma once

#include "entity.h"
#include <stdio.h>

typedef struct
{
	unsigned int width;
	unsigned int height;
	p_entitylist entities;
} world;

typedef world * p_world;

p_world world_create(void);
void world_destroy(p_world);

void world_save(p_world, FILE*);
void world_load(p_world, FILE*);