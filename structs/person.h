

#pragma once
struct Person {
  char *first_name;
  char *last_name;
  int age;
};

void person_json(struct Person);
