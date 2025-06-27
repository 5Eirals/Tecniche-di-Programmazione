#include <stdlib.h>
#include <stdio.h>
#define N 12

void printArray(int arr[], int size);
void insertionSort(int A[], int n);
void bubbleSort(int A[], int n);
void selectionSort(int A[], int n);

int main(void){
    int v[N] = {7, 12, 3, 4, 8, 1, 5, 9, 2, 6, 11, 10};

    selectionSort(v, N);

    return 0;
}

void printArray(int arr[], int size){
    printf("[");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void insertionSort(int A[], int n){
                                 // esecuzioni:
    for(int i = 1; i < n; i++){  //2N
        int x = A[i];            // N-1
        int j = i -1;            // N-1
        while(j>= 0 && x < A[j]){//N(N-1)/2 -1
            A[j+1] = A[j];       //N(N-1)/2
            j--;                 //N(N-1)/2
            printArray(A, n);
        }

        A[j+1] = x;            // N-1
        printf("\n");
        printArray(A, n);
        printf("\n");
    }


}

void bubbleSort(int A[], int n){
    int flag =1;
    for (int i = 0; i < n  && flag == 1; i++){
        flag = 0;
       for (int j = 0; j < n - i -1; j++){
           if (A[j] > A[j+1]){
               int temp = A[j];
               A[j] = A[j+1];
               A[j+1] = temp;
               flag = 1;
           }
           printArray(A, n);
       }
    }
}

void selectionSort(int A[], int n){
    int min;
    for(int i = 0; i < n; i++){
        min = i;
        for (int j = i+1; j < n; j++){
            if(A[j] < A[min]){
                min = j;
            }
        }
        if(min != i){
            int temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }

        printArray(A, n);
    }
}