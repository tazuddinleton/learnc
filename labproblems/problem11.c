/**
 * Write a program in C to convert the temperature input from Fahrenheit to Celsius and vice versa.
*/
#include <stdio.h>

// C = (F-32) / 1.8
// F = C * 1.8 + 32
float f2c(float f);
float c2f(float c);

int main() {

    int convType = 0;
    printf("Choose conversion: \n");
    printf("1. Farenheit to Celcius\n");
    printf("2. Celcius to Farenheit\n");

    scanf("%d", &convType);


    float f;
    float c;
    switch (convType)
    {
    case 1:
        printf("Enter farenheit: \n");
        scanf("%f", &f);
        printf("%.2f farenheit is %.2f celcius\n", f, f2c(f));
        break;
    case 2: 
        printf("Enter celcius: \n");
        scanf("%f", &c);
        printf("%.2f celcius is %.2f farenheit\n", c, c2f(c));
        break;
    
    default:
        printf("Invalid conversion type selected.\n");
        break;
    }
}

float f2c(float f) {
    return (f-32)/1.8;
}

float c2f(float c) {
    return (c * 1.8) + 32;
}