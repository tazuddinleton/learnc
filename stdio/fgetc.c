

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_line(FILE *f);

int main(int argc, char *argv[]) {

	FILE *f = fopen("./data", "r");

	char *line1 = get_line(f);

	while (line1 != NULL) {
		printf("%s\n", line1);
		line1 = get_line(f);
	}
	return 0;
}

char *get_line(FILE *f) {
	size_t buff_size = 4096;
	char *buff = malloc(sizeof(char *) * buff_size);
	int c, rc, idx = 0;

	while ((c = fgetc(f)) != EOF) {
		if (c == '\n') {
			printf("returning a new line : %s", buff);
			return buff;
		}
		if (idx == buff_size - 1) {
			rc++;
			buff_size = 2 * buff_size;
			char *new_buff = realloc(buff, buff_size);
			if (buff == NULL) {
				perror("realloc failed");
				exit(1);
			}
			buff = new_buff;
		}
		buff[idx] = (char)c;
		idx++;
	}

	printf("the buffer: %s\n", buff);

	printf("buff_size: %lu\n", buff_size);
	printf("total read: %d\n", idx);
	printf("total reallocation: %d\n", rc);
	return NULL;
}
