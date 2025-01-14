#include <stdio.h>

// Função de ordenação usando o método de inserção
void insert_sort(int vetor[], int tam) {
    int troca;

    // Percorre o vetor a partir do segundo elemento (índice 1)
    for (int i = 1; i < tam; i++) {
        int proximo = i; // Índice do próximo elemento a ser comparado

        // Responsável por deslocar elementos maiores para frente e inserir o elemento na posição correta
        while ((proximo != 0) && (vetor[proximo] < vetor[proximo - 1])) {
            // Realiza a troca entre o elemento atual e o anterior
            troca = vetor[proximo];
            vetor[proximo] = vetor[proximo - 1];
            vetor[proximo - 1] = troca;

            // Move para o elemento anterior
            proximo--;
        }
    }
}

int main() {
    // Vetor desordenado
    int vetor[6] = {8, 3, 1, 42, 12, 5};

    // Chama a função para ordenar o vetor usando o método de inserção
    insert_sort(vetor, 6);

    // Exibe o vetor ordenado
    printf("Vetor ordenado: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
