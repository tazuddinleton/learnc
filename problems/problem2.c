/**
 * Write a program in C to show the simple structure of a function.
*/
#include <stdio.h>

// This is a user defined function declaration
void greet(char* name);

// This is main function declaration
int main() {
    greet("Taz Uddin");

    return 0;
}
// This is a user defined function implementation
void greet(char* name) {
    printf("Hello %s\n", name);
}