

#include <stdio.h>
#include <stdlib.h>

typedef struct coordinate {
  int x;
  int y;
  int z;
} coordinate_t;

coordinate_t new_coordinate(int x, int y, int z) {
  coordinate_t c;
  c.x = x;
  c.y = y;
  c.z = z;
  return c;
}

int main(int argc, char *argv[]) {

  int numbers[5] = {1, 2, 3, 4, 5};
  int *numbers2 = numbers;
  int *numbers3 = numbers;

  printf("%d\n", *numbers);
  printf("%d\n", *numbers2);
  printf("%d\n", *numbers3);

  *numbers = 44;
  printf("%d\n", *numbers);
  printf("%d\n", *numbers2);
  printf("%d\n", *numbers3);

  printf("Dereferencing: \n");

  printf("%d\n", *(numbers3 + 3));

  coordinate_t coords[5];
  coordinate_t *ptr = coords;

  *ptr = new_coordinate(1, 2, 3);
  ptr[1] = new_coordinate(11, 22, 33);
  *(ptr + 2) = new_coordinate(111, 222, 333);

  printf("coords[0]: %d, %d, %d\n", ptr->x, ptr->y, ptr->z);
  printf("coords[1]: %d, %d, %d\n", (ptr + 1)->x, (ptr + 1)->y, (ptr + 1)->z);
  printf("coords[2]: %d, %d, %d\n", (*(ptr + 2)).x, (ptr + 2)->y, ptr[2].z);

  int *ptr_int = (int *)ptr;

  printf("ptr_int[0]: %d\n", *ptr_int);
  printf("ptr_int[1]: %d\n", ptr_int[1]);
  printf("ptr_int[2]: %d\n", ptr_int[2]);
  printf("ptr_int[3]: %d\n", ptr_int[3]);
  printf("ptr_int[4]: %d\n", ptr_int[4]);
  printf("ptr_int[5]: %d\n", ptr_int[5]);
  printf("ptr_int[6]: %d\n", ptr_int[6]);
  printf("ptr_int[7]: %d\n", ptr_int[7]);
  printf("ptr_int[8]: %d\n", ptr_int[8]);

  int *numbers4 = malloc(1 * sizeof(int));
  numbers4[0] = 100;
  numbers4[100] = 233;

  printf("numbers4[1]: %d\n", numbers4[1]);
  printf("numbers4[100]: %d\n", numbers4[100]);
  printf("numbers4[101]: %d\n", numbers4[101]);

  return EXIT_SUCCESS;
}
