/**
 * Write a program in C to demonstrate the use of the &(address of) and *(value at address) operators.
*/
#include <stdio.h>

int main() {
    // Declaring a number
    int num = 10;
    // declaring a pointer to number and assigning the address of the number to the pointer
    int *numPtr = &num;
    // changing the value of num using its pointer
    *numPtr = 20;
}