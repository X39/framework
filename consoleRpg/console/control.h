#pragma once
#include "tile.h"

struct control;
struct control_geometry
{
	unsigned int x;
	unsigned int y;
	unsigned int width;
	unsigned int height;
};
struct control_vtable
{
	void(*render)(struct control*, tile*, size_t, size_t);
	void(*destroy)(struct control*);
};

#define RENDER_INDEX(W,X,Y) ((Y) * (W) + (X))

enum type
{
	TEXTBLOCK
};


struct textblock
{
	char* text;
	size_t textlen;
};

typedef struct control
{
	struct control_geometry geometry;
	struct control_vtable vtable;
	union
	{
		struct textblock textblock;
	} data;
	enum type dtype;
} control;
typedef control* p_control;

p_control control_create(unsigned int, unsigned int, unsigned int, unsigned int);
void control_destroy(p_control);

p_control control_create_textblock(unsigned int, unsigned int, unsigned int, unsigned int, char*);


#define G_LIST_NAME controllist
#define G_LIST_INNERTYPE p_control
#define G_LIST_CODE_DESTROY for (int i = 0; i < list->top; i++)\
								list->data[i]->vtable.destroy(list->data[i]);
#include "../generic/g_list.h.txt"
#undef G_LIST_NAME
#undef G_LIST_INNERTYPE
#undef G_LIST_CODE_DESTROY