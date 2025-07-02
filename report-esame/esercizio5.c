#include <stdio.h>

int funzione1(){
    char* vet = "one";
    for (int i = 0; vet[i] != '\0'; i++)
        printf("%c", *(vet + i) +1);
    return 0;
}

int funzione2(){
    char* vet = "one";
    for (int i = 0; vet[i] != '\0'; i++)
        printf("%s", vet + i);
    return 0;
}

int funzione3(){
    int val = 0x88112233;
    int *p = &val;
    printf("%x", *p);
    return 0;
}

int funzione4(){
    int val = 0x88112233;
    char *p = (char *)&val;
    printf("%x", *p);
    return 0;
}

int funzione5(){
    int val = 0x44112233;
    char *p = (char *)&val;
    for (int i = sizeof(val)-1; i >= 0; i--)
        printf("%x", p[i]);
    return 0;
}


int main(){
    funzione1();
    printf("\n");
    funzione2();
    printf("\n");
    funzione3();
    printf("\n");
    funzione4();
    printf("\n");
    funzione5();
    printf("\n");
    return 0;
}