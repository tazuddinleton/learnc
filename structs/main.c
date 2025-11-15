

#include "person.h"
#include "point.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  printf("finally learning what c structs are about\n");

  struct Point p;
  p.X = 10;
  p.Y = 10;
  p.Z = 11;

  struct Point p2 = {0};
  struct Point p3 = {10, 10, 3};
  struct Person person = {0};
  struct Person person2 = {.last_name = "Taz", .age = 35};

  // print_point(p);
  point_json(p);
  point_json(p2);
  point_json(p3);
  person_json(person);
  person_json(person2);

  return EXIT_SUCCESS;
}

void print_point(struct Point p) {
  printf("The point p: x = %d, y = %d, z = %d\n", p.X, p.Y, p.Z);
}

void point_json(struct Point p) {
  printf("{\n\t\"X\":%d,\n\t\"Y\":%d,\n\t\"Z\":%d\n\b}", p.X, p.Y, p.Z);
  printf("\n");
}

void person_json(struct Person p) {
  printf("{\n\t\"firstName\":%s,\n\t\"lastName\":%s,\n\t\"age\":%d\n\b}",
         p.first_name, p.last_name, p.age);
  printf("\n");
}
