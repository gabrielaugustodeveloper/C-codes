#include <stdio.h>

int num1;
int num2;

int main () {

printf("Digite o primeiro numero:");
scanf("%d", &num1);
printf("Digite o segundo numero:");
scanf("%d", &num2);

printf("Soma: %d\n", num1 + num2);
printf("Subtracao: %d\n", num1 - num2);
printf("Multiplicacao: %d\n", num1 * num2);
printf("Divisao: %d\n", num1 / num2);
printf("Resto da divisao: %d\n", num1 % num2);


}