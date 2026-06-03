

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {

	char *line = "L145";

	char arr[5];
	arr[0] = line[1];
	arr[1] = line[2];
	arr[2] = line[3];

	if (isdigit(arr)) {
	}
	printf("arr: %d, is_digit: %d\n", atoi(arr), isdigit(line[0]));

	return 0;
}
