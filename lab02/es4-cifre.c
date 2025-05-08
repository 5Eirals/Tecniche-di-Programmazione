#include <stdio.h>

int main(void){
    int X, Y, P, even=0, odd=0, cifre=0;
    printf("Insert two numbers: \n");
    scanf(" %d %d", &X, &Y);

    printf("%d * %d = %d\n", X, Y, (P=X*Y));
    while(P>0){
        if(P%10%2==0){
          even++;
        } else {
          odd++;
        }

        cifre++;
        P=P/10;
    }

    printf("Il prodotto necessita di %d cifre decimali, di cui %d pari e %d dispari \n", cifre, even, odd);
    return 0;
}