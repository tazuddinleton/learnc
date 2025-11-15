

#pragma once
typedef struct Person_Type {
  char *first_name;
  char *last_name;
  int age;
} Person;

void person_json(Person);
