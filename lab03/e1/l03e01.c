 #include <stdio.h>
#define MAX 10

int main(void) {
    FILE *fin;
    int T1 = 0, T2 = 0, sensor = 1, data;
    float entry1 = 0, entry2 = 0;
    char *str[MAX];

    if((fin = fopen("lab03/e1/input.txt", "r")) == NULL){
        printf("Errore apertura file\n");
        return 1;
    }
    fscanf(fin, " %*s");
    while (!feof(fin)) {
        if(!feof(fin)){
            if(fscanf(fin, " %d ", &data) == 1){
                printf("Sensor: %s = %d, data: %d \n", sensor ? "T1" : "T2",sensor ? T1 : T2, data);
                if(sensor){
                    T1 = T1 + data;
                    entry1++;
                } else {
                    T2 = T2 + data;
                    entry2++;
                }
            } else if (fscanf(fin, " %d, ", &data) == 1) {
                printf("Sensor: %s = %d, data: %d \n", sensor ? "T1" : "T2",sensor ? T1 : T2, data);
                if(sensor){
                    T1 = T1 + data;
                    entry1++;
                } else {
                    T2 = T2 + data;
                    entry2++;
                }
            }else{
                fscanf(fin, "%s ", str);
                printf("Cambio sensore, last read: %s \n", str);
                sensor = sensor == 1 ? 0 : 1;
            }
        }
    }

    float avg_t1 = (float)T1/entry1;
    float avg_t2 = (float)T2/entry2;

    printf("Average for T1: %.2f \nAverage for T2: %.2f\n", avg_t1, avg_t2);

    fclose(fin);
    return 0;
}