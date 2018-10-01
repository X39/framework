#pragma once
#include <stdbool.h>




// type of a keycode.
typedef int keycode;

#define KEY_ANY ((keycode)0)
// callback for key. Will receive the actual keycode and additional data
// that was referenced via push.
// should return true if the keycode got handled.
typedef bool(*keycallback)(keycode key, void* data);
// key structure. Contains all data relevant to a single key.
typedef struct
{
	keycode code;
	void* data;
	keycallback callback;
} key;
// keylist structure. Allows easy management of multiple
// key structures. Should be created and manipulated
// via its corresponding keylist_XXXXX methods.
typedef struct {
	key* keys;
	unsigned int top;
	unsigned int size;
} keylist;
typedef keylist* p_keylist;

// Creates a new keylist pointer.
// Might return a NULL pointer, if malloc fails.
p_keylist keylist_create(void);
// Destroys the provided keylist pointer.
// If NULL pointer passed, nothing will happen.
void keylist_destroy(p_keylist);
// Grows provided keylist.
// Growth formular: newsize = cursize * cursize
// If cursize is 0, newsize will be 1.
// Returns false if the realloc call fails.
bool keylist_grow(p_keylist);
// Shrinks a keylist to keylist.top.
// Returns false if the realloc call fails.
bool keylist_shrink(p_keylist);
// Adds provided key to the keylist.
// Returns false if a grow is required and
// keylist_grow returns false.
bool keylist_push(p_keylist, keycode, keycallback, void*);
// Iterates over the different keys and checks if
// provided keycode matches any key inside of it.
// Returns true if keycode was handled.
bool keylist_handle(p_keylist, keycode);

// Executes int getch(void) twice to receive a full
// keycode.
keycode get_key(void);