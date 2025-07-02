#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LUNGH 10

void readFile(char* filename, int* cc){
    char input[MAX_LUNGH];
    FILE* fp = fopen(filename, "r");
    while(fscanf(fp, "%s", input) == 1){
        cc[strlen(input) - 1]++;
    }

    fclose(fp);
}

int printHistogram(int* cc){
    int i,j,max=0;
    for(i=0; i<MAX_LUNGH; i++){
        printf("%4d", i+1);
        for(j=0; j<cc[i]; j++) printf("*");printf("\n");
        if(cc[i] > cc[max]) max = i;
    }
    return max +1;
}

int main(int argc, char* argv[]){
    int cc[MAX_LUNGH] = {0};
    char parola[MAX_LUNGH];
    readFile(argv[1], cc);
    printf("lunghezza con più parole: %d\n", printHistogram(cc));
}