

#include <stddef.h>

typedef struct ByteVector {
	unsigned char *data;
	size_t size;
	size_t cap;
} ByteVector;

ByteVector *ByteVector_create();
void ByteVector_append(ByteVector *v, unsigned char *data, size_t size);
