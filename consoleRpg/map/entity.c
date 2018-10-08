#include "entity.h"

#define G_LIST_NAME entitylist
#define G_LIST_INNERTYPE entity*
#define G_LIST_CODE_DESTROY for (int i = 0; i < list->top; i++)\
								entity_destroy(list->data[i]);
#include "../generic/g_list.c.txt"

#undef G_LIST_NAME
#undef G_LIST_INNERTYPE
#undef G_LIST_CODE_DESTROY

p_entity entity_create(void)
{
	p_entity ent = malloc(sizeof(entity));
	if (ent == NULL)
	{
		return NULL;
	}
	return ent;
}

void entity_destroy(p_entity ent)
{
	free(ent);
}