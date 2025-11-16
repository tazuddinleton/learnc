

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char bbuf[10000]; // to read a big file

int main(int argc, char *argv[]) {

  printf("hello world!\n");

  FILE *f = fopen("data.csv", "r");

  if (!f) {
    perror("cannot open data.csv\n");
  } else {
    printf("opened!\n");
  }

  char buff[1];
  while (fgets(buff, sizeof(buff), f)) {
    printf("csv line: %s\n", buff);
    printf("csv line len: %lu\n", strlen(buff));
  };

  return EXIT_SUCCESS;
}
