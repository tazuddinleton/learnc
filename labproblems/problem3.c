#include <stdio.h>

int fact(int n);
int main() {
    
    int num;
    printf("Enter number to find factorial of: \n");
    scanf("%d", &num);
    printf("factorial of %d: %d\n", num, fact(num));
}

// 2! = 2 * 1 = 2
// 3! = 3 * 2 * 1 = 6
int fact(int n) {
    if (n == 1) {
        return n;
    } else {
        return n * fact(n-1);
    }
}