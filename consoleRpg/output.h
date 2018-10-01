# 1 ".\\map\\entity.h"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 ".\\map\\entity.h"
       

typedef struct
{
 int id;
} entity;

void entity_destroy(entity*);






# 1 ".\\map\\../generic/g_list.h.txt" 1
# 19 ".\\map\\../generic/g_list.h.txt"
# 1 "c:\\mingw\\lib\\gcc\\mingw32\\6.3.0\\include\\stdbool.h" 1 3 4
# 20 ".\\map\\../generic/g_list.h.txt" 2
# 28 ".\\map\\../generic/g_list.h.txt"
typedef struct {
    entity* * data;
    unsigned int top;
    unsigned int size;
} entitylist;

typedef entitylist * p_entitylist;

p_entitylist entitylist_create(void);
void entitylist_destroy(p_entitylist);

# 38 ".\\map\\../generic/g_list.h.txt" 3 4
_Bool 
# 38 ".\\map\\../generic/g_list.h.txt"
    entitylist_grow(p_entitylist);

# 39 ".\\map\\../generic/g_list.h.txt" 3 4
_Bool 
# 39 ".\\map\\../generic/g_list.h.txt"
    entitylist_shrink(p_entitylist);

# 40 ".\\map\\../generic/g_list.h.txt" 3 4
_Bool 
# 40 ".\\map\\../generic/g_list.h.txt"
    entitylist_push(p_entitylist, entity*);

# 41 ".\\map\\../generic/g_list.h.txt" 3 4
_Bool 
# 41 ".\\map\\../generic/g_list.h.txt"
    entitylist_pop(p_entitylist, entitylist *);
# 16 ".\\map\\entity.h" 2
