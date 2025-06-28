#include <stdio.h>

void ruota(int* v, int N, int P, int dir);

void printArray(int* v, int N);

int main(void){
    int V[8] = {0,1,2,3,4,5,6}, N = 7, P, dir;

    printArray(V, N);
    printf("Inserisci la posizione [< 7] e la direzione della rotazione [-1, +1]: \n");
    scanf(" %d %d", &P, &dir);

    if(P<0 || P>7){
        printf("Posizione invalida\n");
        return 1;
    }

    if(dir != 1 && dir != -1){
        printf("Direnzione invalida\n");
        return 1;
    }

    ruota(V, N, P, dir);
    printArray(V, N);

    return 0;
}

void printArray(int* v, int N){
    printf("[ ");
    for(int i = 0; i < N; i++)
        printf("%d ", v[i]);
    printf("]\n");
}

void ruota(int* v, int N, int P, int dir){
    if(dir == -1)
        P = N - P%N;
    else
        P = P%N;

    int copy[N];
    for(int i = 0; i < N; i++){
        copy[(i+P)%N] = v[i];
    }
    for(int i = 0; i < N; i++){
        v[i] = copy[i];
    }
}