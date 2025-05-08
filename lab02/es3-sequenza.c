#include <stdio.h>

int sequenza(FILE *fin);

int main (void){
    FILE *fin;

    if ((fin=fopen("lab02/sorgente.txt","r"))==NULL){
        printf("File not found \n");
        return 1;
    }

    printf("The length of the longest number sequence is : %d\n", sequenza(fin));

    fclose(fin);
    return 0;
}

int sequenza(FILE *fin){
    int seq = 1, max = 1, last=-10000000, read;
    while(!feof(fin)){
        if (feof(fin)){
            return max;
        }

        fscanf(fin, " %d", &read);
        if(read == last)
            seq++;
        else{
            if(seq > max) max = seq;
            seq = 1;
        }
        last = read;
    }

    return max;
}