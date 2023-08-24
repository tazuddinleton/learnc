#include <stdio.h>

// Fibonacci series using iterative process
void fib(int i, int j, int k, int n);

// Fibonacci series using recursive process
int fibRec(int n);

int main() {
    // fib(0, 1, 1, 10);

    for (int i = 0; i < 10; i++) {
        int f = fibRec(i);
        printf("fib %d: %d\n", i+1, f);
    }
}

// fib: 0, 1, 1, 2, 3, 5, 8...
void fib(int i, int j, int k, int n) {
    if (k > n) {
        return;
    }
    printf("fib %d: %d\n", k, i);
    fib(j, i+j, k+1, n);
}

int fibRec(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    else {
        return fibRec(n-1) + fibRec(n-2);
    }
}

/**
 * 
 * fibRec(0) => 0
 * fibRec(1) => 1
 * fibRec(2) => fibRec(1) + fibRec(0) => 1+0 => 1
 * fibRec(3) => fibRec(2) + fibRec(1) => fibRec(1) + fibRec(0) + 1 => 1+0+1 => 2
 * fibRec(4) => fibRec(3) + fibRec(2) => fibRec(2) + fibRec(1) + fibRec(1) + fibRec(0) => fibRec(1) + fibRec(0) + 1 + 1 + 0 => 1 + 0 + 1 + 1 + 0 => 3
 * ...
 * 
*/