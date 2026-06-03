

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
  printf("name of the program in argv[0]: %s\n", argv[0]);
  int c;
  if (strcmp(argv[0], "./upper") == 0) {
    while ((c = getchar()) != EOF) {
      putchar(toupper(c));
    }
  } else if (strcmp(argv[0], "./lower") == 0) {
    while ((c = getchar()) != EOF) {
      putchar(tolower(c));
    }
  } else {
    perror("Invalid argument given");
    exit(1);
  }
  return 0;
}
