
#include <stdio.h>
#include <string.h>
int main() {

	char line[] = "Hello world! What a nice day!";

	char *delims = " ,.;";
	char *token = strtok(line, delims);

	while (token != NULL) {
		printf("Token: %s\n", token);
		token = strtok(NULL, delims);
	}

	return 0;
}
