

#include <stdio.h>
#include <stdlib.h>

char *read_string() {
	size_t buffer_size = 1;
	char *buffer = malloc(sizeof(char) * buffer_size);

	char c;
	int idx = 0;
	while ((c = getc(stdin)) != '\n') {
		if (buffer_size - 1 == idx) {
			char *new_buffer = realloc(buffer, sizeof(char) * buffer_size * 2);
			if (new_buffer == NULL) {
				buffer[idx++] = '\0';
				return buffer;
			}
			buffer = new_buffer;
		}
		buffer[idx++] = c;
	}
	buffer[idx++] = '\0';
	return buffer;
}

int main() {
	char *string = read_string();
	printf("This is my string : %s", string);
	return 0;
}
