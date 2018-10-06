#include "keyhandling.h"
#include <stdio.h>
#include <malloc.h>

// Add implementation-relevant headers
// below here.
#if defined(_WIN32)
#include <conio.h>
#else
#error NO IMPLEMENTATION AVAILABLE
#endif

#if defined(_WIN32) && defined(_MSC_VER)
#define getch _getch
#endif

p_keylist keylist_create(void)
{
	p_keylist list = malloc(sizeof(keylist));
	if (list == NULL)
	{
		return NULL;
	}
	list->top = 0;
	list->size = 0;
	list->keys = 0;
	return list;
}
void keylist_destroy(p_keylist list)
{
	if (list == NULL)
	{
		return;
	}
	if (list->size > 0)
	{
		free(list->keys);
	}
	free(list);
	return true;
}
bool keylist_grow(p_keylist list)
{
	key* tmp;
	unsigned int newsize = list->size * 2;
	if (newsize < list->size)
	{ // Integer Overflow
		return false;
	}
	if (list->size == 0)
	{
		list->keys = malloc(sizeof(key));
		if (list->keys == NULL)
		{
			return false;
		}
		list->size = 1;
		return true;
	}
	else
	{
		tmp = realloc(list->keys, sizeof(key) * newsize);
		if (tmp == NULL)
		{
			return false;
		}
		list->keys = tmp;
		list->size = newsize;
		return true;
	}
}
bool keylist_shrink(p_keylist list)
{
	key* tmp;
	if (list->size == 0)
	{
		return true;
	}
	else
	{
		tmp = realloc(list->keys, sizeof(key) * list->top);
		if (tmp == NULL)
		{
			return false;
		}
		list->keys = tmp;
		list->size = list->top;
		return true;
	}
}
bool keylist_push(p_keylist list, keycode k, keycallback cb, void* data)
{
	if (list->top == list->size && !keylist_grow(list))
	{
		return false;
	}
	list->keys[list->top].code = k;
	list->keys[list->top].callback = cb;
	list->keys[list->top].data = data;
	list->top++;
	return true;
}
bool keylist_handle(p_keylist list, keycode k)
{
	unsigned int i;
	for (i = 0; i < list->top; i++)
	{
		if ((k == list->keys[i].code || list->keys[i].code == KEY_ANY) && list->keys[i].callback(k, list->keys[i].data))
		{
			return true;
		}
	}
	return false;
}

keycode get_key(void)
{
#if defined(_WIN32)
	int i = getch();
	i = i << 8 | getch();
	return (keycode)i;
#else
#error MISSING IMPLEMENTATION FOR "keycode get_key(void)
#endif
}
