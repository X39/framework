#pragma once


typedef int color;
typedef char icon;

typedef struct
{
	icon icon;
	color color;
} tile;



#define G_LIST_NAME tilelist
#define G_LIST_INNERTYPE tile

#include "../generic/g_list.h.txt"

#undef G_LIST_NAME
#undef G_LIST_INNERTYPE
