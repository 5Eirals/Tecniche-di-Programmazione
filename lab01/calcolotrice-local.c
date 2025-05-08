#include <stdio.h>

int main (void) {
    char operation;
    float a, b;

    printf("Please enter an operator [=, -, *, /]: ");
    operation = getchar();
    printf("Insert two numbers: ");
    scanf("%f%f", &a, &b);

    switch (operation) {
      case '+':
        printf("%.2f + %.2f = %.2f\n", a, b, a + b);
        break;
      case '*':
        printf("%.2f * %.2f = %.2f\n", a, b, a * b);
        break;
      case '-':
        printf("%.2f - %.2f = %.2f\n", a, b, a - b);
        break;
      case '/':
         printf("%.2f / %.2f = %.2f\n", a, b, a / b);
         break;
      default:
        printf("Invalid operator\n");
        break;
    }

  return 0;
}
