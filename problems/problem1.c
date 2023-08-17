/**
 * Write a C program to find squire of any number using a function
 * 
*/
#include <stdio.h>

float sqr(float num);
int main() {
    float input;
    printf("Enter a number: \n");
    scanf("%f", &input);
    printf("Squire of %.4f is %.4f\n", input, sqr(input));

    return 0;
}

float sqr(float num) {
    return num * num;
}