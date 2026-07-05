#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 50000 // size of hasmap array

// Linked list node
typedef struct Node {
	char *key;
	char *value;
	struct Node *next;
} Node;

// the Hashmap
typedef struct Map {
	Node **buckets;
} Map;

// Uses DJB2 Algorithm
unsigned long hash_function(char *str) {
	unsigned long hash = 5381;
	int c;
	while ((c = *str++)) {
		hash = (hash << 5) + hash + c; // equivalent to hash * 33 + c
	}

	return hash % CAPACITY;
}

// Helper to create a node
Node *create_node(char *key, char *value) {
	Node *node = (Node *)malloc(sizeof(Node));

	assert(node != NULL);

	node->key = strdup(key);
	node->value = strdup(value);
	node->next = NULL;
	return node;
}

// Helper to create a Hashmap
Map *create_map() {
	Map *map = (Map *)malloc(sizeof(Map));
	// Allocate memrory for all buckets and initialize them to zero
	map->buckets = (Node **)calloc(CAPACITY, sizeof(Node *));
	return map;
}

// When inserting 3 cases to consider:
// 1. The bucket is empty, in this case just insert
// 2. The bucket contains the key already, in this case just update the value
// 3. The bucket contains a different key, that means a collision, in this case
// Walk through the linked list and append the node at the end
void insert(Map *map, char *key, char *value) {
	unsigned long index = hash_function(key);
	Node *node = create_node(key, value);

	Node *head = map->buckets[index];
	// Bucket empty, just insert
	if (head == NULL) {
		map->buckets[index] = node;
		return;
	}

	// Bucket is not empty, let's walk the chain

	Node *prev;
	Node *curr = head;
	while (curr != NULL) {
		if (strcmp(head->key, key) == 0) {
			// found the key, just update
			free(curr->value); // free the old memory, because strdup allocates
							   // new memory
			curr->value = strdup(value);
			return;
		}
		prev = curr;
		curr = curr->next;
	}
	// Key was not found in the chain, append at the end
	prev->next = node;
}

char *search(Map *map, char *key) {
	unsigned long index = hash_function(key);

	Node *curr = map->buckets[index];

	while (curr != NULL) {
		if (strcmp(key, curr->key) == 0) {
			// match found
			return curr->value;
		}
		curr = curr->next;
	}
	return NULL;
}

void free_map(Map *map) {
	if (map == NULL) {
		return;
	}

	for (int i = 0; i < CAPACITY; i++) {
		Node *curr = map->buckets[i];
		while (curr != NULL) {
			Node *temp = curr;
			curr = curr->next;

			free(temp->key);
			free(temp->value);
			free(temp);
		}
	}
	free(map->buckets);
	free(map);
}

int main(int argc, char *argv[]) {
	Map *map = create_map();
	insert(map, "Hello", "World!");
	insert(map, "abc", "1234545");
	insert(map, "ok", "200");

	printf("%s\n", search(map, "Hello"));
	printf("%s\n", search(map, "abc"));
	printf("%s\n", search(map, "ok"));

	free_map(map);
}
