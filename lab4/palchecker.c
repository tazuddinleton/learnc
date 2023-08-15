#include <stdio.h>

void checkPalindrome(int num);
int main() {
    int input;
    printf("Enter a number: \n");
    scanf("%d", &input);

    checkPalindrome(input);

}


void checkPalindrome(int num) {
    if (num < 10) {
        printf("Palindrome\n");
        return;
    }
    int temp = num;
    int rev = 0;
    while (temp != 0) {
        rev = rev*10 + temp%10;
        temp /= 10;
    }
    if (rev == num) {
        printf("Palindrome\n");
    } else {
        printf("Not a Palindrome\n");
    }
}