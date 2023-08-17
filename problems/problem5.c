/**
 * Write a program in C to calculate the sum of numbers from 1 to n using recursion.
*/
#include <stdio.h>

int sumFirstN(int n);
int doSum(int num, int n, int total);

int main() {
    printf("Sum of first 10 numbers: %d\n", sumFirstN(100));

    return 0;
}

int sumFirstN(int n) {
    return doSum(0, n, 0);
}

int doSum(int num, int n, int total) {
    if (num > n) {
        return total;
    }
    return doSum(num+1, n, total+num);
}
