#include <stdio.h>

int main(void){
    int a = 0, b = 1, N, temp;

    printf("Enter a fibonacci last index: \n");
    scanf(" %d", &N);

    if(N >= 0){
        printf(" 0");
    }
    if(N >= 1){
        printf(" 1");
    }
    while(N>1){
        temp = a + b;
        if (temp < 0){
            printf("\n\nExited integer memory limit \n");
            return 1;
        }
        a = b;
        b = temp;
        N -= 1;
        printf(" %d", temp);
    }

    printf("\n");
    return 0;
}