

#include <stdio.h>
#define RESET "\x1b[0m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
#define T "\x1b[94m"

int main() {

	printf("Hello T " T "World!" RESET "\n");
	printf("Hello Red " RED "World!" RESET "\n");
	printf("Hello Green " GREEN "World!" RESET "\n");
	printf("Hello Yellow " YELLOW "World!" RESET "\n");
	printf("Hello Blue " BLUE "World!" RESET "\n");
	printf("Hello Magenta " MAGENTA "World!" RESET "\n");
	printf("Hello Cyan " CYAN "World!" RESET "\n");
	printf("Hello White " WHITE "World!" RESET "\n");
	return 0;
}
