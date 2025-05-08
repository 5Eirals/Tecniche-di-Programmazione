#include <stdio.h>

int main (void){
    FILE *fin, *fout;

    if((fin = fopen("lab01/Operations.txt", "r")) == NULL){
      printf("Error opening file\n");
      return 1;
    }
    if((fout = fopen("lab01/Results.txt", "w")) == NULL){
        printf("Error opening file\n");
        return 2;
    }

    while(!feof(fin)){
        if(!feof(fin)){
            char operation;
            float a, b;
            fscanf(fin, " %c%f%f", &operation, &a, &b);
            switch (operation) {
                case '+':
                    fprintf(fout, "%.2f + %.2f = %.2f\n", a, b, a + b);
                    break;
                case '*':
                    fprintf(fout, "%.2f * %.2f = %.2f\n", a, b, a * b);
                    break;
                case '-':
                    fprintf(fout, "%.2f - %.2f = %.2f\n", a, b, a - b);
                    break;
                case '/':
                    fprintf(fout, "%.2f / %.2f = %.2f\n", a, b, a / b);
                    break;
                default:
                    fprintf(fout, "Invalid operation\n");
                break;
            }
        }
    }

    fclose(fin);
    fclose(fout);
}