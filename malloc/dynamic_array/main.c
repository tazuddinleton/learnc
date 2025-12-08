

#include <stdio.h>
#include <stdlib.h>

/*
 * IntVec is an array of integer, that dynamically grows.
 * */
typedef struct {
	int *data;
	int cap;
	int size;
} IntVec;

void throw_if_null(IntVec *v) {
	if (v == NULL) {
		perror("NULL pointer is given where IntVec was expected\n");
		exit(1);
	}
}

IntVec *create_vec() {
	IntVec *v = malloc(sizeof(IntVec));
	v->cap = 10;
	v->size = 0;
	v->data = malloc(v->cap * sizeof(int));
	if (!v || !v->data) {
		perror("Allocation failed");
		exit(1);
	}
	return v;
}

void free_vec(IntVec *v) {
	if (v) {
		free(v->data);
		free(v);
	}
}

IntVec *resize(IntVec *v) {
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

void push_back(IntVec *v, int val) {
	throw_if_null(v);
	if (v->size == v->cap) {
		resize(v);
	}
	v->data[v->size++] = val;
}

void pop_back(IntVec *v) {
	throw_if_null(v);
	if (v->size == 0) {
		perror("Index out of range");
		exit(1);
	}
	v->size--;
}

int get_at(IntVec *v, int index) {
	throw_if_null(v);
	if (index > 0 && index <= v->size) {
		return v->data[index];
	}
	fprintf(stderr, "Index out of range");
	exit(1);
}

int main() {

	printf("hello world!");

	IntVec *v = create_vec();
	for (int i = 0; i < 10000; i++) {
		push_back(v, i * 3);
	}

	printf("The size of IntVec: %d\n", v->size);
	printf("The cap of IntVec: %d\n", v->cap);
	printf("The value at 240 of IntVec: %d\n", get_at(v, 240));
	printf("The value at 240 of IntVec: %d\n", get_at(v, 240));

	free_vec(v);
	printf("freed v\n");

	return 0;
}
