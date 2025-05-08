#include <math.h>
#include <stdio.h>

#define MAX_NUM 17

char*  convert (char* number, int start_base, int end_base);

int main(void){
    char n1[MAX_NUM];
    int base1, base2;

    printf("Enter number and base: \n");
    scanf(" %s %d", &n1, &base1);
    printf("Enter conversion base: \n");
    scanf(" %d", &base2);

    printf("Converting %s in base %d to base %d : \n", n1, base1, base2);
    printf(convert(n1, base1, base2));
    return 0;
}

char* convert (char* number, int start_base, int end_base){
    static char res[MAX_NUM];
    int len= 0, num = 0, b = 1;
    for(; number[++len] != '\0';);
    for(int i = len-1; i >= 0; i--){
        num += (number[i] - '0') * b;
        b *= start_base;
    }

    int p, i = 0;
    for(p = 1; end_base*p <= num; p *= end_base);
    while(p>0){
        if(p<=num){
            res[i++] = num/p + '0';
            num %= p;
        } else {
            res[i++] = '0';
        }

        p/= end_base;
    }
    res[i] = '\0';

    return res;
}