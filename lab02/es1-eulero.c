#include <stdio.h>

int main (void){
    int a, b;

    printf("enter two numbers: \n");
    scanf(" %d %d", &a, &b);

    if ( a < b){
        a = a + b;
        b = a - b;
        a = a - b;
    }

    printf("a:%d b:%d \n", a, b);

    int resto = a % b;
    while (resto != 0){
        a = b;
        b = resto;
        resto = a % b;
    }

    printf("Least common divisor is: %d\n", b);

    return 0;
}