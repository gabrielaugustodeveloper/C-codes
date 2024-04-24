#include <stdio.h>

int main() {
    float VET[100];
    float soma = 0;

    printf("Digite os 100 números reais:\n");
    for (int i = 0; i < 100; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%f", &VET[i]);
    }

    for (int i = 0; i < 100; i++) {
        soma += VET[i];
    }

    printf("A soma dos elementos do vetor eh: %.2f\n", soma);

    return 0;
}
