#include <stdio.h>

int check(int a, int b, int c);

int main(void){
    int trashed = 0;
    int max = -1;
    int min = 10000000;
    int position = 0;
    int last = 0;
    int slast = 0;

    FILE *fin;

    if ((fin = fopen("lab04/e5/numeri.txt", "r")) == NULL){
        printf("Errore apertura file\n");
        return -1;
    }

    while(!feof(fin)){
        int scan;
        fscanf(fin, " %d", &scan);
        if(scan != EOF){
            if (max < scan)  max = scan;
            if (min > scan)  min = scan;

            if(position > 1) {
                if (check(slast, last, scan) == 0){
                    trashed ++;
                } else {
                    slast = last;
                    last = scan;
                }
            } else
            {
                slast = last;
                last = scan;
            }


            position++;
        }
    }

    printf("Numero massimo: %d\n", max);
    printf("Numero minimo: %d\n", min);
    printf("Numeri scartati : %d\n", trashed);

    fclose(fin);
    return 0;
}

int check(int a, int b, int c){
    int status = 0;

    if(a + b == c) status++;
    if(a - b == c) status++;
    if(a * b == c) status++;
    if(b != 0 && a / b == c) status++;

    return status;
}