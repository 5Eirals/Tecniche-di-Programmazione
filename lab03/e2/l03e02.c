#include <stdio.h>

int main(void) {
    int days, dd, mm, yy;

    printf("scrivi una data (formato gg/mm/aaaa): ");
    scanf ("%d/%d/%d", &dd,&mm,&yy);
    printf("ho letto: %02d/%02d/%04d\n", dd,mm,yy); // aggiunta per verificare il corretto input
    printf("scrivi N (numero di giorni dopo la data): ");
    scanf ("%d", &days);
    printf("ho letto: %d\n", days);


    return 0;
}
