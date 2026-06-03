

#include <stdio.h>
int main(int argc, char *argv[]) {

  char ***result_cointainer[50];
  char **result[50];
  char *buffer[50];

  char *p;

  printf("size of int: %lu\n", sizeof(int));
  printf("size of pinter: %lu\n", sizeof(p));
  printf("size of *[50]: %lu\n", sizeof(buffer));
  printf("size of **[50]: %lu\n", sizeof(result));
  printf("size of ***[50]: %lu\n", sizeof(result_cointainer));

  return 0;
}
