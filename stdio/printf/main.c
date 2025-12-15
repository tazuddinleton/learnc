#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	// 1. printf
	printf("printf: Hello world\n");

	// 2. fprintf()

	FILE *f = fopen("fprintf.output", "w");
	fprintf(f, "fprintf: Hello world using fprintf\n");

	// 3. sprintf, writes to a string

	int size = 13;
	char *hello_world = malloc(size);
	sprintf(hello_world, "%s %s\n", "Hello", "World! asdfasf");

	printf("sprintf: %s\n", hello_world);

	// 4. snprintf
	//
	char *h2 = malloc(size);
	snprintf(h2, size, "%s %s\n", "Hello", "World!   ");

	printf("snprintf: %s\n", h2);

	printf("## ***hello***");
}
