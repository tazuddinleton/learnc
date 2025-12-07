

#include <stdio.h>
#include <stdlib.h>

char *get_full_greeting(char *greeting, char *name, int size) {
	char *full_greeting = malloc(sizeof(char *) * size);
	snprintf(full_greeting, size, "%s %s!", greeting, name);
	return full_greeting;
}

int main() {
	printf("greeting: %s\n", get_full_greeting("Hello,", "Taz", 12));
	return 0;
}
