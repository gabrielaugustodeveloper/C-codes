#include <stdio.h>

// Função de ordenação usando o método Bubble Sort
void bubble_sort(int vetor[], int tam) {
    // Variável auxiliar para realizar trocas
    int proximo = 0;

    // Loop externo para passar por todo o vetor
    for (int i = 0; i < tam - 1; i++) { 
        // Loop interno para comparar pares de elementos
        for (int j = 0; j < tam - 1 - i; j++) { 
            // Se o elemento atual for maior que o próximo, realiza a troca
            if (vetor[j] > vetor[j + 1]) {
                proximo = vetor[j];          // Salva o elemento atual
                vetor[j] = vetor[j + 1];    // Move o próximo elemento para a posição atual
                vetor[j + 1] = proximo;     // Coloca o elemento salvo na posição seguinte
            }
        }
    }
}

int main() {
    // Vetor desordenado
    int vetor[6] = {8, 3, 1, 42, 12, 5};

    // Chama a função para ordenar o vetor usando o método Bubble Sort
    bubble_sort(vetor, 6);

    // Exibe o vetor ordenado
    printf("Vetor ordenado: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    return 0;
}
