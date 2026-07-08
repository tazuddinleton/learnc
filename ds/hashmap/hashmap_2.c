

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct Map {
	size_t size;
	size_t cap;
	void **buckets;
} Map;

const size_t BASE = 0x811c9dc5;
const size_t PRIME = 0x01000193;

size_t hash(Map *m, char *str) {
	size_t h = BASE;
	while (*str) {
		h ^= *str++;
		h *= PRIME;
	}

	return h & (m->cap - 1);
}

Map init(size_t cap) {
	Map m = {0, cap};
	m.buckets = malloc(sizeof(void *) * cap);
	assert(m.buckets != NULL);

	return m;
}

int main(int argc, char *argv[]) { return 0; }
