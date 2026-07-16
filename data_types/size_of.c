

#include <stdio.h>
int main(int argc, char *argv[]) {

	printf("%-20s %lu bytes\n", "long long ", sizeof(long long));
	printf("%-20s %lu byte\n", "char ", sizeof(char));
	printf("%-20s %lu bytes\n", "short ", sizeof(short));
	printf("%-20s %lu bytes\n", "int ", sizeof(int));
	printf("%-20s %lu bytes\n", "float ", sizeof(float));
	printf("%-20s %lu bytes\n", "double ", sizeof(double));
	printf("%-20s %lu bytes\n", "long ", sizeof(long));

	return 0;
}
