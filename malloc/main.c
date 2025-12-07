

#include <stdio.h>
#include <stdlib.h>

char *get_full_greeting(char *greeting, char *name, int size) {
	char *full_greeting = malloc(sizeof(char *) * size);
	snprintf(full_greeting, size, "%s %s!", greeting, name);
	return full_greeting;
}

int *initialize_scalar_list(int size, int multiplier) {
	int *result = malloc(size * sizeof(int));
	if (result == NULL) {
		return NULL;
	}

	for (int i = 0; i < size; i++) {
		result[i] = i * multiplier;
	}
	return result;
}

int main() {
	printf("greeting: %s\n", get_full_greeting("Hello,", "Taz", 12));

	printf("size of array: 10\n");
	int scalar_size = 10;
	int multiplier = 2;
	int *scalar_list = initialize_scalar_list(scalar_size, multiplier);
	for (int i = 0; i < scalar_size; i++) {
		printf("scalar item: %d => %d\n", i, scalar_list[i]);
	}

	return 0;
}
