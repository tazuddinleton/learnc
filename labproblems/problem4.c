#include <stdio.h>

int isPrime(int num);
int main() {

    printf("Enter a number to check if it is prime: \n");
    int num;
    scanf("%d", &num);
    if (isPrime(num)) {
        printf("Prime\n");
    } else{
        printf("Not prime\n");
    }
}


int isPrime(int num) {
    for (int i = 2; i < num/2; i++) {
        if (num % i == 0) {
            // The number is not prime
            return 0;
        }
    }
    // The number is prime
    return 1;
}