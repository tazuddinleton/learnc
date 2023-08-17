/**
 *  Write a program in C to add two numbers using pointers.
*/
#include <stdio.h>

int main() {
    int num1 = 10;
    int num2 = 20;

    int *num1Ptr = &num1;
    int *num2Ptr = &num2;

    int result = *num1Ptr + *num2Ptr;
}