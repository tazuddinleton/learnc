#include "hashmap.h"
#include <stdlib.h>

map_t *map_create(size_t cap) {
	// create map
	map_t *map = malloc(sizeof(map_t *));
	map->cap = cap;
	map->size = 0;
	map->buckets = calloc(cap, sizeof(void *));
	return map;
}
// frees the whole hashMa
void map_destroy(map_t *map) {
	free(map->buckets);
	free(map);
}

INSERTION_STATUS map_put(map_t *map, const void *key, size_t len_key, void *val,
						 size_t len_val) {

	/**
	 * cases for insertions:
	 * 1. buckets is empty
	 * 2. buckets is not empty and key does not exist
	 * 3. buckets is not empty and key exist
	 * 4. size = cap, need to resize
	 *
	 */

	// we need hash function
	// we need resize function
	// need to decide strategy for collision handling
	// need to decide the hasing algorithm
	return SUCCESS_ADDED;
}

/* We'll use FNV1a for hashing*/
#define PRIME 0x01000193
#define HASH 0x811c9dc5
unsigned long map_hash(map_t *map, void *key, size_t len_key) {
	unsigned long hash = HASH;

	unsigned char *byte = (unsigned char *)key;
	for (int i = 0; i < len_key; i++) {
		hash ^= byte[i];
		hash *= PRIME;
	}

	return hash & (map->cap - 1);
}
