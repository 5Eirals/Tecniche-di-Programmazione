#include <stdio.h>
#include <ctype.h>

#define FILE_ERROR 0
#define ENCODING_ERROR 126 //char: ~

int codifica(FILE *fin, FILE *fout);
int decodifica(FILE *fin, FILE *fout);

char encode(char c, char prev);
char decode(char c, char prev);


int main(void) {
    FILE *fin, *fout;

    char input[50];
    char output[50];
    char command;

    // printf("Insert the input file name <name.txt> :\n");
    // scanf(" %s", input);
    // printf(input);
    // printf("Insert the output file name <name.txt> :\n");
    // scanf(" %s", output);
    // printf(output);

    printf("Select encoding <E> or decoding <D> mode: \n");
    scanf(" %c", &command);

    if ((fin = fopen("lab04/e2/input.txt", "r")) == NULL) {
      printf("Error opening input file\n");
      return FILE_ERROR;
    }
    if ((fout = fopen("lab04/e2/output.txt", "w")) == NULL) {
        printf("Error opening output file\n");
        return FILE_ERROR;
    }

    switch (command) {
      case 'E': return codifica(fin, fout);
      case 'D': return decodifica(fin, fout);
      default: printf("Invalid command\n"); return FILE_ERROR;
    }

}

int codifica(FILE *fin, FILE *fout) {
    int char_count = 0;
    char current_char;
    char previous_char = 0;

    while (!feof(fin)) {
        fscanf(fin, "%c", &current_char);
        if( current_char != EOF) {
            fprintf(fout, "%c", encode(current_char, previous_char));
            previous_char = current_char;
            char_count++;
        }
    }

    return char_count;
}

int decodifica(FILE *fin, FILE *fout) {
    int char_count = 0;
    char current_char;
    char previous_char = 0;

    while (!feof(fin)) {
        fscanf(fin, "%c", &current_char) ;
        if( current_char != EOF) {
            fprintf(fout, "%c", decode(current_char, previous_char));
            previous_char = current_char;
            char_count++;
        }
    }

    return char_count;
}

char encode(char c, char prev) {
    static int k = 0;
    int h = 0;

    if(isdigit(c)){
        char res = c + k;
        k = (k + 1)%9;
        return res;
    }

    if(isalpha(c) && isalpha(prev)){
        if(prev >= 'a' && prev <= 'z'){
            h = prev - 'a';
            char res = (c >= 'a' ? 'a':'A') + (c - h)%26;
            return res;
        }
        if(prev >= 'A' && prev <= 'Z'){
            h = prev - 'A';
            char res = (c >= 'a' ? 'a':'A') + (c - h)%26;
            return res;
        }
        return ENCODING_ERROR;

    }

    return c;
}

char decode(char c, char prev) {
    static int k = 0;
    int h = 0;

    if(isdigit(c)){
        char res = c - k;
        k = (k + 1)%9;
        return res;
    }

    if(isalpha(c) && isalpha(prev)){
        if(prev >= 'a' && prev <= 'z'){
            h = prev - 'a';
            char res = 'a' + (c - h)%26;
            return res;
        }
        if(prev >= 'A' && prev <= 'Z'){
            h = prev - 'A';
            char res = 'A' + (c - h)%26;
            return res;
        }
        return ENCODING_ERROR;
    }

    return c;
}