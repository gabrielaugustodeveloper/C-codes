#include <stdio.h>

int main() {
    int contador;
    int num;
    int maior;

    contador = 1;

    printf("Digite o numero %d: ", contador);
    scanf("%d", &num);

    maior = num;

    while (contador < 10) {
        contador++; 

        printf("Digite o numero %d: ", contador);
        scanf("%d", &num);

        if (num > maior) {
            maior = num;
        }
    }

    printf("O maior numero fornecido foi: %d\n", maior);

    return 0;
}