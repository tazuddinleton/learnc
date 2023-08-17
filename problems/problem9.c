/**
 * Write a program in C to find the length of a string without using library function.
*/
#include <stdio.h>

int main() {

    char str[100];
    scanf("%s", str);

    int i, l;
    for(i = 0; str[i] != '\0';) {
        i++;
    }
    
    printf("Lenght of string is: %d\n", i);

    return 0;
}