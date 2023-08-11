#include <stdio.h>
#include <assert.h>

int main() {
    double start;
    double end;
    double step;

    printf("Please enter start: ");
    scanf("%lf", &start);

    printf("Please enter end: ");
    scanf("%lf", &end);
    assert(start < end);   

    printf("Please enter step: ");
    scanf("%lf", &step);
    assert(step > 0);

    double inc = start;

    while(inc < end) {
        printf("%lf\n", inc);
        inc += step;        
    }    

    return 0;
}