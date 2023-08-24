/**
 * Write a program in C to print the array elements using recursion.
*/
#include <stdio.h>

void print(int elem[], int len, int index);

int main () {
    int elem[] = {1,2,3,4,5,6,7,8,9};

    print(elem, 9, 0);
}


void print(int elem[], int len, int index) {
    if (index == len) {
        return;
    }
    printf("elem: %d = %d\n", index, elem[index]);
    print(elem, len, index+1);
}