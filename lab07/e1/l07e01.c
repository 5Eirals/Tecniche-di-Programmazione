#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLOG 1000
#define MAXLEN 30
#define NDATA 7
#define LOGFILE "lab07/e1/corse.txt"

typedef enum comando_e {
    r_date,
    r_partenza,
    r_capolinea,
    r_ritardo,
    r_ritardo_tot,
    r_fine
}comando_e;

typedef struct data{
    int gg;
    int mm;
    int yy;
} data;

comando_e leggiComando(char* str);
void printDate(char table[MAXLOG][NDATA][MAXLEN], int n);
void printStop(char table[MAXLOG][NDATA][MAXLEN], int n);
void printDestination(char table[MAXLOG][NDATA][MAXLEN], int n);
void printDelay(char table[MAXLOG][NDATA][MAXLEN], int n);
void printTotalDelay(char table[MAXLOG][NDATA][MAXLEN], int n);
int compareData(data a, data b);

int main(void){
    FILE* filelog;
    char log[MAXLOG][NDATA][MAXLEN];
    char Menu[MAXLOG] =
        "MENU:\n\telencare tutte le corse partite in un certo intervallo di date: <date>\n\telencare tutti le corse "
        "partite da una certa fermata: <partenza>\n\telencare tutti le corse aventi una data destinazione: <capolinea>"
        "\n\telencare tutte le corse che hanno raggiunto la destinazione in ritardo in un certo intervallo di date: "
        "<ritardo>\n\telencare il ritardo complessivo accumulato dalle corse identificate da un certo codice di tratta:"
        " <ritardo_tot>\n\tqualsiasi altro comando per uscire\n";
    char command[MAXLEN];
    int entries, loop = 1;

    if((filelog = fopen(LOGFILE, "r")) == NULL){
        printf("Errore apertura file\n");
        return 1;
    }

    fscanf(filelog, " %d", &entries);
    for(int i = 0; i < entries; i++)
        for(int j = 0; j < NDATA; j++)  fscanf(filelog, " %s", log[i][j]);

    do{
        printf("%s Inserisci comando: ", Menu);
        scanf(" %s", command);
        switch(leggiComando(command)){
            case r_date: printDate(log, entries); break;
            case r_partenza: printStop(log, entries); break;
            case r_capolinea: printDestination(log, entries); break;
            case r_ritardo: printDelay(log, entries); break;
            case r_ritardo_tot: printTotalDelay(log, entries); break;
            case r_fine: loop = 0; break;
        }
    } while(loop);

    fclose(filelog);
    return 0;
}

comando_e leggiComando(char* str){
    if(strcmp(str, "date") == 0) return r_date;
    if(strcmp(str, "partenza") == 0) return r_partenza;
    if(strcmp(str, "capolinea") == 0) return r_capolinea;
    if(strcmp(str, "ritardo") == 0) return r_ritardo;
    if(strcmp(str, "ritardo_tot") == 0) return r_ritardo_tot;
    return r_fine;
}

int compareData(data a, data b){
    if(a.yy > b.yy)
        return 1;
    if(a.yy == b.yy)
        if (a.mm > b.mm) return 1;
            if(a.mm == b.mm){
                if (a.gg > b.gg) return 1;
                if(a.gg == b.gg) return 0;
            }
    return -1;
}

void printDate(char table[MAXLOG][NDATA][MAXLEN], int n){
    data inizio, fine;
    printf("Inserisci la data di inizio: <gg/mm/yyy>: ");
    scanf("%d/%d/%d", &inizio.gg, &inizio.mm, &inizio.yy);
    printf("Inserisci la data di fine: <gg/mm/yyy>: ");
    scanf("%d/%d/%d", &fine.gg, &fine.mm, &fine.yy);

    for(int i = 0; i < n; i++){
        data log;
        sscanf(table[i][3], "%d/%d/%d", &log.yy, &log.mm, &log.gg);
        if (compareData(log, inizio) >= 0 && compareData(log, fine) <= 0){
            for(int j = 0; j < NDATA; j++)
                printf("%s ", table[i][j]);
            printf("\n");
        }
    }
}

void printStop(char table[MAXLOG][NDATA][MAXLEN], int n){
    char stop[MAXLEN];
    printf("Inserisci la fermata di partenza: ");
    scanf(" %s", stop);
    for(int i = 0; i < n; i++){
        if(strcmp(table[i][1], stop) == 0){
            for(int j = 0; j < NDATA; j++)
                printf("%s ", table[i][j]);
            printf("\n");
        }
    }
}

void printDestination(char table[MAXLOG][NDATA][MAXLEN], int n){
    char stop[MAXLEN];
    printf("Inserisci la fermata di destinazione: ");
    scanf(" %s", stop);
    for(int i = 0; i < n; i++){
        if(strcmp(table[i][2], stop) == 0){
            for(int j = 0; j < NDATA; j++)
                printf("%s ", table[i][j]);
            printf("\n");
        }
    }
}

void printDelay(char table[MAXLOG][NDATA][MAXLEN], int n){
    data inizio, fine;
    printf("Inserisci la data di inizio: <gg/mm/yyy>: ");
    scanf("%d/%d/%d", &inizio.gg, &inizio.mm, &inizio.yy);
    printf("Inserisci la data di fine: <gg/mm/yyy>: ");
    scanf("%d/%d/%d", &fine.gg, &fine.mm, &fine.yy);

    for(int i = 0; i < n; i++){
        data log;
        sscanf(table[i][3], "%d/%d/%d", &log.yy, &log.mm, &log.gg);
        if (compareData(log, inizio) >= 0 && compareData(log, fine) <= 0){
            if(atoi(table[i][6]) > 0){
                for(int j = 0; j < NDATA; j++)
                    printf("%s ", table[i][j]);
                printf("\n");
            }
        }
    }
}

void printTotalDelay(char table[MAXLOG][NDATA][MAXLEN], int n){
    char code[MAXLEN];
    int tot = 0;
    printf("Inserisci il codice della tratta: ");
    scanf(" %s", code);
    for(int i = 0; i < n; i++){
        if(strcmp(table[i][0], code) == 0){
            int delay = atoi(table[i][6]);
            tot += delay;
        }
    }

    printf("Il ritardo acculumato dalla fermata %s : %d\n", code, tot);
}
