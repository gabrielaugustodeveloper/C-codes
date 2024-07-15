#include <stdio.h>

int main() {
    float VET[100]; // Declara um vetor de 100 elementos do tipo float
    float soma = 0; // Inicializa a variável soma com 0

    // Solicita ao usuário para digitar 100 números reais
    printf("Digite os 100 números reais:\n");
    for (int i = 0; i < 100; i++) { // Loop para ler os 100 valores
        printf("Digite o valor %d: ", i + 1);
        scanf("%f", &VET[i]); // Lê cada valor e armazena no vetor VET
    }

    // Calcula a soma dos elementos do vetor
    for (int i = 0; i < 100; i++) { // Loop para percorrer o vetor VET
        soma += VET[i]; // Adiciona o valor de cada elemento do vetor à variável soma
    }

    // Exibe a soma dos elementos do vetor
    printf("A soma dos elementos do vetor eh: %.2f\n", soma); // Mostra o resultado da soma

    return 0; // Finaliza o programa
}