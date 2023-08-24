
/**
 * Write a program in C to count the total number of characters in a string.
*/
#include <stdio.h>

int main() {

    char s[] = "Hello world";
    int i = 0;
    for(;s[i] != '\0'; i++);

    printf("Length of the string: %d\n", i);
    
}