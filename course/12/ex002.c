#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor; // Ponteiro para armazenar o endereço do vetor alocado
    int tamanhoInicial = 3, quantidade;

    // a) Aloca inicialmente um vetor com 3 inteiros
    vetor = (int *) malloc(tamanhoInicial * sizeof(int));

    // Verifica se a alocação de memória foi bem-sucedida
    if (vetor == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1; // Sai do programa se a alocação falhar
    }

    // b) Pergunta ao usuário quantos valores ele quer informar
    printf("Quantos valores você deseja informar? ");
    scanf("%d", &quantidade);

    // c) Se a quantidade for maior que 3, use REALLOC para ajustar o tamanho do vetor
    if (quantidade > tamanhoInicial) {
        vetor = (int *) realloc(vetor, quantidade * sizeof(int));

        // Verifica se a re-alocação de memória foi bem-sucedida
        if (vetor == NULL) {
            printf("Erro de realocação de memória.\n");
            return 1; // Sai do programa se a realocação falhar
        }
    }

    // d) Leia os valores informados pelo usuário
    for (int i = 0; i < quantidade; i++) {
        printf("Informe o valor para a posição %d: ", i);
        scanf("%d", &vetor[i]);
    }

    // e) Apresente os valores armazenados no vetor
    printf("Os valores informados são:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%d\n", vetor[i]);
    }

    // f) Libere a memória alocada
    free(vetor);
    vetor = NULL; // Define o ponteiro como NULL por segurança

    return 0;
}
