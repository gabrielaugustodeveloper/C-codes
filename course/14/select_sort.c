#include <stdio.h>

// Função de ordenação usando o método de seleção
void select_sort(int vetor[], int tam) {
    int menor, troca;

    // Loop externo percorre todos os elementos do vetor
    for (int i = 0; i < (tam - 1); i++) {
        menor = i; // Supõe que o menor elemento está na posição atual

        // Loop interno compara o elemento atual com os seguintes
        for (int j = (i + 1); j < tam; j++) {
            if (vetor[j] < vetor[menor]) { // Encontra o menor elemento restante
                menor = j; // Atualiza a posição do menor elemento
            }
        }

        // Realiza a troca do menor elemento encontrado com o atual
        if (i != menor) {
            troca = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = troca;
        }
    }
}

int main() {
    // Vetor desordenado
    int vetor[6] = {8, 3, 1, 42, 12, 5};
     
    // Chama a função para ordenar o vetor usando o método de seleção
    select_sort(vetor, 6);

    // Exibe o vetor ordenado
    printf("Vetor ordenado: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
