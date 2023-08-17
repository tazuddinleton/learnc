/**
 * Write a program in C to print the first 50 natural numbers using recursion.
*/

#include <stdio.h>

void printNum(int num);
int main() {
    printNum(0);

    return 0;
}

void printNum(int num) {
    if (num > 50) {
        return;
    }
    printf("%d\n", num);
    printNum(num+1);
}
