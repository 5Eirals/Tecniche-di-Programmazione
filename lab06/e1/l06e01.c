#include <stdio.h>

#define INFILE "lab06/e1/input.txt"
#define MAXSIZE 20

int main(void){
    FILE *fin;
    int table[MAXSIZE][MAXSIZE], r, c, points[MAXSIZE];
    if((fin=fopen(INFILE,"r"))==NULL){
        printf("Errore apertura file\n");
        return 1;
    }

    fscanf(fin," %d %d",&r, &c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            fscanf(fin," %d", &table[i][j]);
        }
    }

    for(int i = 0; i < r; i++){
        points[i] = 0;
    }

    for(int k=0;k<c;k++){
        int first = 0, maxscore = 0;
        for(int i=0;i<r;i++){
            points[i] += table[i][k];
            if(points[i]>maxscore){
                maxscore = points[i];
                first = i;
            }
        }
        printf("Alla <%d> giornata la squadra <%d> capolista\n", k+1, first+1);
    }

    return 0;
}
