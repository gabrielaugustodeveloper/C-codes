#include <stdio.h>

int mdc(int a, int b) {
    int resto;
    
    while (b != 0) {
        resto = a % b;
        a = b;
        b = resto;
    }

    return a;
}

int main() {
    int num1, num2;

    printf("Digite dois numeros inteiros(separados por espaco): ");
    scanf("%d %d", &num1, &num2);

    printf("O MDC de %d e %d e: %d\n", num1, num2, mdc(num1, num2));

    return 0;
}