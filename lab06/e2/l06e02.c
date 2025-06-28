#include <stdio.h>
#include <string.h>
#define INFILE "lab06/e2/sorgente.txt"
#define OUTFILE "lab06/e2/ricodificato.txt"
#define DICFILE "lab06/e2/dizionario.txt"
#define MAXLINE 200

int main(void){
    FILE *fin, *fout, *fdic;

    if((fdic = fopen(DICFILE, "r"))==NULL){
        printf("Errore apertura file\n");
        return 1;
    }

    int N;
    fscanf(fdic, " %d", &N);
    char trigger[N][MAXLINE];
    char replace[N][MAXLINE];
    for (int i = 0; i < N; i++)
        fscanf(fdic, " %s %s ", replace[i], trigger[i]);


    if((fin = fopen(INFILE, "r"))==NULL){
        printf("Errore apertura file\n");
        return 1;
    }
    if((fout = fopen(OUTFILE, "w"))==NULL){
        printf("Errore apertura file\n");
        return 1;
    }

    while(!feof(fin)){
        char str[MAXLINE];
        fgets(str, MAXLINE, fin);

        for (int i = 0; i < strlen(str); i++){
            for(int j = 0; j < N; j++){
                if(i == (strstr(str, trigger[j]) - str)){
                    fprintf(fout, "%s", replace[j]);
                    i += strlen(trigger[j]);
                    break;
                }
            }

            fprintf(fout, "%c", str[i]);
        }
    }



    fclose(fdic);
    fclose(fin);
    fclose(fout);
    return 0;
}