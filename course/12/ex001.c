#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array; // Declara um ponteiro para armazenar o endereço do array alocado
    int tamanho = 5; // Define o tamanho do array

    // a) Aloca dinamicamente um array de 5 números inteiros
    array = (int *) malloc(tamanho * sizeof(int));

    // Verifica se a alocação de memória foi bem-sucedida
    if (array == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1; // Sai do programa se a alocação falhar
    }

    // b) Pede para o usuário informar os 5 números no espaço alocado
    for (int i = 0; i < tamanho; i++) {
        printf("Informe o valor para a posição %d: ", i);
        scanf("%d", &array[i]);
    }

    // c) Mostra na tela os 5 valores
    printf("Os valores informados são:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d\n", array[i]);
    }

    // d) Libera a memória alocada
    free(array);
    array = NULL; // Define o ponteiro como NULL por segurança

    return 0;
}
