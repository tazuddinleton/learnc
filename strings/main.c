

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

size_t string_len(char *str) {
  size_t l = 0;
  while (str[l] != '\0') {
    l++;
  }
  return l;
}

char *string_concat(char *str1, char *str2) {

  size_t str1_len = string_len(str1);
  size_t str2_len = string_len(str2);
  char *new_string = malloc(str1_len + str2_len + 1);

  int idx = 0;
  for (; idx < str1_len; idx++) {
    new_string[idx] = str1[idx];
  }

  printf("found null at : %d for %s\n", idx, str1);

  int str2_pointer = 0;
  for (; str2_pointer < str2_len; str2_pointer++) {
    new_string[idx + str2_pointer] = str2[str2_pointer];
  }
  return new_string;
}

int main(int argc, char *argv[]) {

  char *str1 = "Hello";
  char *str2 = " World!";

  printf("concatenated: %s\n", string_concat(str1, str2));

  return EXIT_SUCCESS;
}
