#include <stdio.h>

int main() {

    int int_val = 10;        
    printf("Signed integer %%d %d \n", int_val);
    printf("You can also use %%i %i \n", int_val);
    unsigned int uint_val = 10;
    printf("Unsigned integer %%u %u \n", uint_val);

    long long_val = 99999999999;
    printf("Formatting long with %%ld %ld \n", long_val);
    printf("You can also use %%li %li \n", long_val);

    long long long_long_val = 9090909090909090;
    printf("Formatting long long with %%lld %lld \n", long_long_val);
    printf("You can also use %%lli %lli \n", long_long_val);

    unsigned long long u_long_long_val = 9090909090909090;
    printf("Formatting unsigned long long with %%llu %lld \n", u_long_long_val);    

    float float_val = 2.04521;
    printf("Formatting floating point number with %%.2f %.2f \n", float_val);    

    double double_val = 2.0452125815441955;
    printf("Formatting double precision floating point number with %%.12lf %.12lf \n", double_val);

    double science_val = 9124510010101000;
    printf("Formatting scientific notation with %%E %E \n", science_val);

    char a_char = 'A';
    printf("Formatting character with %%c %c \n", a_char);

    char* a_string = "Hello world!";
    printf("Formatting string %%s %s \n", a_string);
    printf("Formatting pointer (the locaton of \"Hello world!\" %%p %p \n", a_string);
    
    
    printf("Hex of 10 is %%x %x \n", int_val);    
    printf("Octal of 10 is %%o %o \n", int_val);    
    
    return 0;
}