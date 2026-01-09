

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	unsigned char *data;
	size_t cap;
	size_t size;
} File;

File *read_all_bytes(FILE *f) {

	File *my_file = malloc(sizeof(File));
	my_file->cap = 256;
	my_file->size = 0;
	my_file->data = malloc(sizeof(unsigned char *) * my_file->cap);

	size_t buff_size = 256;
	unsigned char buffer[buff_size];

	while (1) {

		// Resize if needed
		if (my_file->size - my_file->cap < buff_size) {
			size_t new_cap = my_file->cap * 2;
			my_file->data =
				realloc(my_file->data, sizeof(unsigned char *) * new_cap);
			if (my_file->data == NULL) {
				perror("Reallocation failed");
				exit(1);
			}
			my_file->cap = new_cap;
		}

		// Read the chunk from the stream
		const size_t ret_code = fread(buffer, sizeof(unsigned char), 256, f);
		printf("fread just read : %ld bytes\n", ret_code);
		if (ret_code > 0) {
			// Append to my file
			memcpy(my_file->data + my_file->size, buffer, ret_code);
			my_file->size += ret_code;
		}

		if (feof(f)) {
			printf("End of file detected\n");
			break;
		}

		if (ferror(f)) {
			printf("File error detected\n");
			break;
		}
	}

	return my_file;
}

File *read_file(char *filename) {
	FILE *f = fopen(filename, "rb");
	if (!f) {
		perror("File open failed");
		exit(1);
	}
	File *fl = read_all_bytes(f);
	printf("%ld bytes read from %s\n", fl->size, filename);
	return fl;
}

int main() {

	File *f = read_file("../Assignments_7–10.md");
	printf("File size: %ld\n", f->size);

	return 0;
}
