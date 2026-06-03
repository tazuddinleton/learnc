

#include "intvec.h"
#include <stdio.h>

int main() {

	printf("hello world!");

	IntVector *v = IntVector_create();
	for (int i = 0; i < 10000; i++) {
		IntVector_push_back(v, i * 3);
	}

	printf("The size of IntVec: %d\n", v->size);
	printf("The cap of IntVec: %d\n", v->cap);
	printf("The value at 240 of IntVec: %d\n", IntVector_get_at(v, 240));
	printf("The value at 240 of IntVec: %d\n", IntVector_get_at(v, 240));

	IntVector_free(v);
	printf("freed v\n");

	return 0;
}
