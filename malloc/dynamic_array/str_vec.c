

#include "str_vec.h"
#include <stdio.h>
#include <stdlib.h>

void throw_if_null(StringVector *v) {
	if (!v) {
		perror("NULL pointer is given where StringVector was expected\n");
		exit(1);
	}
}

void resize(StringVector *v) {
	int new_cap = v->cap * 2;
	char **new_data = malloc(sizeof(char **) * new_cap);
	if (new_data == NULL) {
		perror("Realloc failed!\n");
		exit(1);
	}
	v->cap = new_cap;
	v->data = new_data;
}

StringVector *IntVector_create() {
	int init_cap = 10;

	StringVector *v = malloc(sizeof(StringVector));

	v->size = 0;
	v->cap = init_cap;
	v->data = malloc(sizeof(char **) * init_cap);

	return v;
}

void IntVector_free(StringVector *v) {
	if (v) {
		free(v->data);
		free(v);
	}
}

void IntVector_add(StringVector *v, char *val) {
	throw_if_null(v);

	if (v->size == v->cap) {
		resize(v);
	}
	v->data[v->size++] = val;
}
