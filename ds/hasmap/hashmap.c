

// Linked list for chaining
// Hash function to get the index

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 50000 // the capacity of the array of the buckets
#define HASH 5381

// Linkde list node
typedef struct Node {
	char *key;		   // pointer to a char is 8 bytes
	char *value;	   // pointer to a char is 8 bytes
	struct Node *next; // pointer to a node is also 8 bytes
} Node;				   // so total memory 24 bytes

// We need a helper to create node
Node *create_node(char *key, char *value) {
	Node *node = malloc(sizeof(Node));
	assert(node != NULL);

	node->key = strdup(key);
	node->value = strdup(value);
	return node;
}

// We need the define the hashmap itself
typedef struct Map {
	unsigned long cap;
	// single asterisk would refer to the node's memory location, but we
	// need a pointer to that memeory
	// this become an array of pointers which holds pointer to a node
	Node **buckets; // 8 bytes

} Map;

// We need a helper function to create the hashmap
Map *create_map() {
	Map *map = malloc(sizeof(Map));
	assert(map != NULL);
	map->cap = CAPACITY;

	Node **bucekts = calloc(CAPACITY, sizeof(Node *));
	assert(bucekts != NULL);
	map->buckets = bucekts;

	return map;
}

// Now we need the hash function the engine
unsigned long has_function(char *key) {
	// We'll use DJB2 algorithm for hasing
	unsigned long hash = HASH;
	char c;
	while ((c = *key++)) {
		hash = (hash << 5) + hash + c;
	}
	return hash % CAPACITY;
}

// Helper function to insert the entry
void insert(Map *map, char *key, char *value) {
	assert(map != NULL);

	unsigned long index = has_function(key);
	Node *head = map->buckets[index];
	if (head == NULL) {
		// bucket is empty so add a node and return
		map->buckets[index] = create_node(key, value);
		return;
	}

	// bucket is not empty so check if the key already exist in the chain
	Node *curr = head;
	Node *prev = curr;
	while (curr != NULL) {
		if (strcmp(curr->key, key) == 0) {
			// Match found, update the value and return
			free(curr->value); // free before using strdup, because strdup
							   // allocates new memory
			curr->value = strdup(value);
			return;
		}
		prev = curr;
		curr = curr->next;
	}

	// Exausted the chain, no match found, append a node and return
	prev->next = create_node(key, value);
}

char *get_value(Map *map, char *key) {
	unsigned long index = has_function(key);

	Node *node = map->buckets[index];

	if (node != NULL) {
		return node->value;
	}

	// return NULL if not found
	return NULL;
}

void free_map(Map *map) {
	if (map == NULL) {
		return;
	}
	// Now for each bucket we need to free everything

	for (int i = 0; i < CAPACITY; i++) {
		Node *node = map->buckets[i];
		while (node != NULL) {
			Node *temp = node;
			node = node->next;

			free(temp->key);
			free(temp->value);
			free(temp);
		}
	}
}

int main(int argc, char *argv[]) {
	Map *map = create_map();
	insert(map, "Hello", "World");

	printf("%s\n", get_value(map, "Hello"));

	return 0;
}
