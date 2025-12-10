

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

	size_t size = 4096;
	char *buffer = malloc(sizeof(char) * size);
	char c;
	int idx = 0;
	char *delim = " .,;";
	while ((c = getc(f)) != EOF) {
		// printf("the char: %c\n", c);
		if (c == '\n') {
			// printf("strtok called \n");
			char *token = strtok(buffer, delim);
			while (token != NULL) {
				token = strtok(NULL, delim);
				printf("Token: %s\n", token);
				StringVector_add(v, token);
			}
		} else if (idx == size - 1) {
			size = size * 2;
			char *new_buffer = realloc(buffer, size);
			if (new_buffer == NULL) {
				perror("Realloc failed");
				exit(1);
			}
			buffer = new_buffer;
		}
		buffer[idx++] = c;
	}

	printf("The size of StringVector: %d\n", v->size);
	printf("The cap of StringVector: %d\n", v->cap);
	printf("The value at 1 of StringVector: %s\n", StringVector_get_at(v, 1));
	printf("The value at 240 of StringVector: %s\n",
		   StringVector_get_at(v, 240));

	StringVector_free(v);
	free(buffer);
	printf("freed v\n");

	return 0;
}
