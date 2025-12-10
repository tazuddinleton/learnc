

#include "intvec.h"
#include <stdio.h>
#include <stdlib.h>

void throw_if_null(IntVector *v) {
	if (v == NULL) {
		perror("NULL pointer is given where IntVec was expected\n");
		exit(1);
	}
}

IntVector *IntVector_create() {
	IntVector *v = malloc(sizeof(IntVector));
	v->cap = 10;
	v->size = 0;
	v->data = malloc(v->cap * sizeof(int));
	if (!v || !v->data) {
		perror("Allocation failed");
		exit(1);
	}
	return v;
}

void IntVector_free(IntVector *v) {
	if (v) {
		free(v->data);
		free(v);
	}
}

IntVector *resize(IntVector *v) {
	throw_if_null(v);
	int new_cap = v->cap * 2;
	printf("current cap: %d, next cap: %d\n", v->cap, new_cap);
	int *new_data = realloc(v->data, new_cap * sizeof(int));
	if (new_data == NULL) {
		perror("Realloc failed\n");
		exit(1);
	}
	v->data = new_data;
	v->cap = new_cap;
	return v;
}

void IntVector_push_back(IntVector *v, int val) {
	throw_if_null(v);
	if (v->size == v->cap) {
		resize(v);
	}
	v->data[v->size++] = val;
}

void IntVector_pop_back(IntVector *v) {
	throw_if_null(v);
	if (v->size == 0) {
		perror("Index out of range");
		exit(1);
	}
	v->size--;
}

int IntVector_get_at(IntVector *v, int index) {
	throw_if_null(v);
	if (index > 0 && index <= v->size) {
		return v->data[index];
	}
	fprintf(stderr, "Index out of range");
	exit(1);
}
