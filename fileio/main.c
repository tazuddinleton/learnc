

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const size_t buffer_size = 128;

int main(int argc, char *argv[]) {

  printf("hello world!\n");

  FILE *f = fopen("data.csv", "r");

  if (!f) {
    perror("cannot open data.csv\n");
    return EXIT_FAILURE;
  }

  char buff[buffer_size];

  while (fgets(buff, sizeof(buff), f)) {
    printf("chunk size: %zu, len: %lu, data: %s\n", sizeof(buff), strlen(buff),
           buff);
  };

  return EXIT_SUCCESS;
}
