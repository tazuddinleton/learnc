/**
 * Write a program in C to count the total number of words in a string.
*/
#include <stdio.h>

int main() {
    char s[] = "Hello world";
    int i = 0;
    int count = 0;

    for(; s[i] != '\0'; i++) {
        if (count == 0 && s[i] != ' '){
            count++;
        }
        if (s[i] == ' ' && s[i+1] != ' ' && s[i+1] != '\0') {
            count++;
        }
    }

    printf("Number of words in the string is: %d\n", count);

}