#include <stdio.h>

int findMax(int a, int b, int c);

int main() {
    int a, b, c;
    printf("Enter 3 numbers: \n");
    scanf("%d %d %d", &a, &b, &c);
    printf("The max of the 3 numbers is : %d\n", findMax(a, b, c));
    return 0;
}

int findMax(int a, int b, int c) {
    return a > b ? a > c ? a: c: b > c ? b : c;
}


