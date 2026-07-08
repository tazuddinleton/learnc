

// In this hashmap implementation we'll use
// the FNV1a which stands for Fowler-Nol-Vo algorithm.
// It uses an offset basis which acts as an initial hash value
// and a fnv1a prime which randomizes things
// to get the hash it starty off as the offset basis and for each byte
// XORs the hash by it. then multiplies by the prime
// and thus you get the hash. After that to fit the hash into the bucket size
// you have to either mod by the size of the bucekt or
// AND by the size-1, in this case ANDing is faster to calculate, but then you
// have to keep the bucket size 2^n, not just any number.
// To handle the collision, we'll use Linear Probing

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The bucket capacity, keeping it as 2^16 so we can apply ANDing the
// hash with it to keep the index within the bound
#define CAPACITY 65536
// The prime number to multiply the hash with
#define PRIME 0x01000193
// The initial hash value so it doesn't start with something like
#define BASE 0x811c9dc5

typedef struct Map {
	void **buckets;
} Map;

typedef struct MapEntry {
	void *key;
	void *value;
} MapEntry;

Map *create_map() {
	// allocate memory for the map itself
	Map *map = malloc(sizeof(Map));
	assert(map != NULL);

	// allocate memory for the full capacity
	void **bucekts = calloc(CAPACITY, sizeof(MapEntry *));
	assert(bucekts != NULL);

	map->buckets = bucekts;
	return map;
}

// Helper function to create map entry, we need to know the size of the key and
// value since we have no idea what data type are they
MapEntry *create_entry(void *key, size_t key_size, void *value,
					   size_t val_size) {

	// allocate for the map entry struct
	MapEntry *entry = malloc(sizeof(MapEntry));

	// allocate for the key
	entry->key = malloc(key_size);
	assert(entry->key != NULL);

	// copy the content of the key
	memcpy(entry->key, key, key_size);

	// allocate memory for the content of the value
	entry->value = malloc(val_size);
	assert(entry->value != NULL);
	memcpy(entry->value, value, val_size);

	return entry;
}

// Returns the index from the key
unsigned long hash(void *key, size_t key_size) {
	unsigned long hash = BASE;

	// we need to cast the void* into a byte*, so we can read byte by byte
	unsigned char *byte = (unsigned char *)key;

	for (int i = 0; i < key_size; i++) {
		hash ^= byte[i];
		hash *= PRIME;
	}

	// AND with the capacity - 1 to fit the index inside the bucket
	return hash & (CAPACITY - 1);
}

void insert(Map *map, void *key, size_t key_size, void *value,
			size_t val_size) {
	// See if the index is occupied, if yes keep checking the next place
	// until the end of the bucket, then wrap around from the beginning
	// if it is full throw error, in a production setup you'd be copying the
	// whole map to a larger capacity map

	unsigned long index = hash(key, key_size);

	for (int i = index; i < CAPACITY; i++) {
		if (map->buckets[index] == NULL) {
			map->buckets[index] = create_entry(key, key_size, value, val_size);
			return;
		}
	}

	for (int i = 0; i < index; i++) {
		if (map->buckets[index] == NULL) {
			map->buckets[index] = create_entry(key, key_size, value, val_size);
			return;
		}
	}

	printf("%s", "Bucket is full!");
	exit(1);
}

MapEntry *try_get(Map *map, void *key, size_t key_size) {
	unsigned long index = hash(key, key_size);

	for (int i = index; i < CAPACITY; i++) {
		MapEntry *entry = map->buckets[i];
		if (entry != NULL && memcmp(entry->key, key, key_size) == 0) {
			return entry;
		}
	}

	for (int i = 0; i < index; i++) {
		MapEntry *entry = map->buckets[i];
		if (entry != NULL && memcmp(entry->key, key, key_size) == 0) {
			return entry;
		}
	}
	return NULL;
}

int main(int argc, char *argv[]) {

	Map *map = create_map();
	char *key = "hello";
	char *value = "The new hash map implementation";

	insert(map, key, strlen(key), value, strlen(value));

	MapEntry *entry = try_get(map, key, strlen(key));

	if (entry != NULL) {
		printf("%s\n", (char *)entry->value);
	}

	int int_key = 1;
	insert(map, &int_key, sizeof(int), entry, sizeof(MapEntry));

	MapEntry *entry2 = (MapEntry *)try_get(map, &int_key, sizeof(int))->value;

	if (entry2 != NULL) {
		printf("%s", (char *)entry2->value);
	}

	return 0;
}
