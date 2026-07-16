#ifndef HASHMAP_H
#define HASHMAP_H

#include <stddef.h>

typedef enum {
	SUCCESS_ADDED,
	SUCCESS_UPDATED,
	SUCCESS_RESIZED,
	FAILED_OUT_OF_MEMORY
} INSERTION_STATUS;

typedef struct {
	void **buckets;
	size_t cap;
	size_t size;
} map_t;

// initializes the HashMap with given capacity
map_t *map_create(size_t cap);
// frees the whole hashMap
void map_destroy(map_t *map);
// clears the elements of the map, so it can be re-used
void map_clear(map_t *map);
// find the element by the key, returns NULL if not found
void *map_get(map_t *map, void *key);
// remove the item from map_t and the caller is responsible for cleanup
void *map_remove(map_t *map, void *key);
// insert an item to map
INSERTION_STATUS map_put(map_t *map, const void *key, size_t len_key, void *val,
						 size_t len_val);
// check if an item is present with the given key
int map_has(map_t *map, const void *key);
// check the map size
size_t map_size(map_t *map);
// calculate the load factor, size/cap
double map_load_factor(map_t *map);
// resize the map to a new size
int map_resize(map_t *map, size_t new_cap);

#endif // !DEBUG HASHMAP_H
