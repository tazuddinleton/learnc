

#include "str_vec.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	FILE *f = fopen("../../Assignments_7–10.md", "r");
	if (f == NULL) {
		perror("Failed to open file");
		exit(1);
	}

	StringVector *v = StringVector_create();

	size_t size = 256;
	char *buffer = malloc(sizeof(char) * size);
	char c;
	int idx = 0;
	char *delim = " .,;";

	while ((c = getc(f)) != EOF) {
		if (c == '\n' || c == EOF) {
			buffer[idx++] = '\0';
			char *token = strtok(buffer, delim);
			while (token != NULL) {
				StringVector_add(v, strdup(token));
				token = strtok(NULL, delim);
			}
			idx = 0;
			continue;
		} else if (idx + 1 >= size) {
			size = size * 2;
			char *new_buffer = realloc(buffer, size);
			if (new_buffer == NULL) {
				perror("Realloc failed");
				exit(1);
			}
			buffer = new_buffer;
		} else {
			buffer[idx++] = c;
		}
	}

	for (int i = 0; i < v->size; i++) {
		printf("word at: %d is %s\n", i, v->data[i]);
	}

	printf("The size of StringVector: %d\n", v->size);
	printf("The cap of StringVector: %d\n", v->cap);
	printf("The value at 0 of StringVector: %s\n", StringVector_get_at(v, 100));
	printf("The value at 1 of StringVector: %s\n", StringVector_get_at(v, 200));
	printf("The value at 2 of StringVector: %s\n", StringVector_get_at(v, 300));

	StringVector_free(v);
	free(buffer);
	printf("freed v\n");

	return 0;
}
