#include <stdio.h>

int main(void){
    int A[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 0, 1, 1}}, N, maxi=0, maxj=0, maxsum = 0;

    printf("Dimesione delle sottomatrici: ");
    scanf("%d", &N);

    for(int i = 0; i <= 3-N; i++)
        for(int j = 0; j <= 4 - N ; j++){
            int sum = 0;
            for(int k = i; k < i + N; k++){
                printf("\n");
                for(int l = j; l < j + N; l++){
                    printf("%d ", A[k][l]);
                    sum += A[k][l];
                }
            }
            printf("\n");

            if(sum > maxsum){
                maxsum = sum;
                maxi = i;
                maxj = j;
            }
        }

    printf("La sottomatrice con somma massima è:");
    for(int i = maxi; i < maxi + N; i++){
        printf("\n");
        for(int j = maxj; j < maxj + N ; j++)
            printf("%d ", A[i][j]);
    }


    return 0;
}