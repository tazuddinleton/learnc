/**
 * Write a program in C to find the length of a string using library functions.
*/
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Write a program in C to find the length of a string using library functions.";

    printf("Number of characters in the string: %lu\n", strlen(str));
}