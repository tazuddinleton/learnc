

#include "byte-vec.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ByteVector *ByteVector_create() {
	ByteVector *v = malloc(sizeof(ByteVector));
	v->data = malloc(sizeof(unsigned char *) * 10);
	v->cap = 10;
	v->size = 0;
	return v;
}

void resize(ByteVector *v) {
	size_t new_cap = v->cap * 2;
	void *new_data = malloc(sizeof(unsigned char *) * new_cap);
	if (new_data == NULL) {
		perror("Realloc failed\n");
		exit(1);
	}
	v->data = new_data;
	v->cap = new_cap;
}
void ByteVector_append(ByteVector *v, unsigned char *data_chunk, size_t size) {

	if (v->cap < v->size + size) {
		resize(v);
	}

	memcpy(v->data + v->size, data_chunk, size);
	v->size += size;
}
