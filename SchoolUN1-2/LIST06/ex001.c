#include <stdio.h>

int main() {
    int arrayA[10]; // Declaração do arrayA com 10 elementos
    int arrayB[10]; // Declaração do arrayB com 10 elementos

    // Solicita ao usuário para digitar os valores do arrayA
    printf("Digite os valores do array:\n");
    for (int i = 0; i < 10; i++) { // Loop para ler os 10 valores
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &arrayA[i]); // Lê cada valor e armazena no arrayA
        
        // Verifica se o valor lido é par
        if (arrayA[i] % 2 == 0){
            // Se for par, divide o valor por 2 e armazena no arrayB
            arrayB[i] = arrayA[i] / 2;
        }
        else {
            // Se for ímpar, multiplica o valor por 3 e armazena no arrayB
            arrayB[i] = arrayA[i] * 3;
        }
    }

    // Exibe os valores armazenados no arrayA
    for (int i = 0; i < 10; i++) {
        printf("Elemento %d do arrayA:\n", i + 1);
        printf("%d\n", arrayA[i]);
    }

    // Exibe os valores armazenados no arrayB
    for (int i = 0; i < 10; i++) {
        printf("Elemento %d do arrayB:\n", i + 1);
        printf("%d\n", arrayB[i]);
    }

    return 0; // Finaliza o programa
}