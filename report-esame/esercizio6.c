#include <stdio.h>
#define N_KID  5

typedef struct{
    char nome[30];
    int ingressi;
}attivita;

typedef struct{
    char id[7];
    attivita* elenco;
    int n;
} bambino;


void raggruppaBambini(bambino b[], int n, int conteggi[10]){
    for(int k = 0; k<10; k++) conteggi[k] = 0;
    for(int i = 0; i < n; i++){
        if(b[i].n > 45) conteggi[9]++; //più di 45 attività
        else if(b[i].n > 39) conteggi[8] ++; //missplacement della quadra nel codice non intenzionale
        else if(b[i].n > 34) conteggi[7] ++;
        else if(b[i].n > 29) conteggi[6] ++;
        else if(b[i].n > 24)conteggi[5] ++;
        else if(b[i].n > 19) conteggi[4] ++;
        else if(b[i].n > 14) conteggi[3] ++;
        else if(b[i].n > 9) conteggi[2] ++;
        else if(b[i].n > 4) conteggi[1] ++;
        else conteggi[0] ++;
    }
}
void raggruppaBambini1(bambino b[], int n, int conteggi[10]){
    for(int k = 0; k<10; k++) conteggi[k] = 0;
    for(int i = 0; i < n; i++){
        if(b[i].n > 45) conteggi[9]++;
        else
            conteggi[b[i].n/5]++;
    }
}
void attivitaPreferite(bambino b[], int n, attivita* preferite[]){
    for(int i = 0; i < n; i++){
        int fav = 0;
        for(int j = 0; j < b[i].n; j++)
            if(b[i].elenco[j].ingressi > b[i].elenco[fav].ingressi) fav = j;
        preferite[i]= &b[i].elenco[fav];
    }
}
int piuAttivi(bambino b[], int n, int min, bambino* selezionati[]){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(b[i].n >= min) selezionati[count++]= &b[i]; //almeno quindi >=
    }
    return count;
}

int main(){
    int min = 4;
    int conteggi[10];
    attivita elenco[][5] = {
        {{"calcio", 7}, {"tiro alla fune", 6}, {"yoyo", 1}, {"judo", 5}},
        {{"calcio", 3}, {"tiro alla fune", 2}, {"yoyo", 5}, {"judo", 4}},
        {{"calcio", 12}, {"tiro alla fune", 1}},
        {{"calcio", 3}, {"tiro alla fune", 3}, {"yoyo", 3}, {"judo", 3},{"freccette", 4}},
        {{"calcio", 1}, {"tiro alla fune", 2}, {"yoyo", 8}}
        };
    bambino b[N_KID] = {
        {"000001", elenco[0] , 4},
        {"000002", elenco[1] , 4},
        {"000003", elenco[2] , 2},
        {"000004", elenco[3] , 5},
        {"000005", elenco[4] , 3}
    };
    attivita* preferite[N_KID];
    bambino* selezionati[N_KID];

    raggruppaBambini1(b, N_KID, conteggi);
    attivitaPreferite(b, N_KID, preferite);

    int sel = piuAttivi(b, N_KID, min, selezionati);

    printf("conterggi:   ");
    for(int k = 0; k<10; k++) printf("%d ", conteggi[k]);
    printf("\nselezionati: \n");
    for(int s = 0; s < sel; s++){
        printf("id: %s attività:%d\n", selezionati[s]->id, selezionati[s]->n);
    }

    printf("Attività preferite: \n");
    for(int i = 0; i < N_KID; i++){
        printf("id: %s, attività: %s\n", b[i].id, preferite[i]->nome);
    }
}
