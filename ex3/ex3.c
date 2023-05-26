#include <stdio.h>

int main() {
    int age = 10;
    int height = 72;

    

    printf("I am %d years old.\n", age);
    printf("I am %d inches tall\n", height);



    int* p = &age;
    printf("Formatting pointer addres with %%p %p\n", p);
    printf("Hex integer with %%x %x\n", age);

    
    return 0;
}