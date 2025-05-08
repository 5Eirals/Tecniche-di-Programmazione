#include <stdio.h>

int main(void){
    //attenzione a non disallinearsi nella lettura
    FILE *fin;

    float T1 = 0.0, T2 = 0.0;
    int n1 = 0, n2 = 0, data, sensor;

    if((fin = fopen("lab03/e1/input.txt", "r")) == NULL){
        printf("Errore apertura file\n");
        return 1;
    }

    while(fscanf(fin, " T%d:", &sensor) != EOF){
        printf("reading T%d data", sensor);
        while(fscanf(fin, "%d", &data) == 1){
            if(sensor == 1){
                T1 += data;
                n1++;
            }
        }

        fscanf(fin, " ,"); // catch eventual commas
    }

    T1 /= n1;

    return 0;
}