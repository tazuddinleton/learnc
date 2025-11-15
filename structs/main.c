

#include "typedef_person.h"
#include "typedef_point.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  printf("size of int: %zu\n", sizeof(int));
  printf("size of char: %zu\n", sizeof(char));
  printf("size of char*: %zu\n", sizeof(char *));
  printf("size of Point*: %zu\n", sizeof(Point));
  printf("size of Person*: %zu\n", sizeof(Person));

  printf("finally learning what c structs are about\n");

  Point p;
  p.X = 10;
  p.Y = 10;
  p.Z = 11;

  Point p2 = {0};
  Point p3 = {10, 10, 3};
  Person person = {0};
  Person person2 = {.last_name = "Taz", .age = 35};

  // print_point(p);
  point_json(p);
  point_json(p2);
  point_json(p3);
  person_json(person);
  person_json(person2);

  return EXIT_SUCCESS;
}

void print_point(Point p) {
  printf("The point p: x = %d, y = %d, z = %d\n", p.X, p.Y, p.Z);
}

void point_json(Point p) {
  printf("size of Point: %lu\n", sizeof(Point));

  printf("{\n\t\"X\":%d,\n\t\"Y\":%d,\n\t\"Z\":%d\n\b}", p.X, p.Y, p.Z);
  printf("\n");
}

void person_json(Person p) {
  printf("size of Person: %zu\n", sizeof(Person));
  printf("{\n\t\"firstName\":%s,\n\t\"lastName\":%s,\n\t\"age\":%d\n\b}",
         p.first_name, p.last_name, p.age);
  printf("\n");
}
