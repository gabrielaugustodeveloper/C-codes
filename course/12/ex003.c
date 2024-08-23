#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho;           // Variável para armazenar o tamanho da string que será informada pelo usuário
    char *ponteiro;        // Ponteiro para armazenar o endereço da memória alocada dinamicamente para a string

    // Solicita ao usuário que informe o tamanho da string
    printf("Informe o tamanho da string a ser informada: ");
    scanf("%d", &tamanho);
    getchar(); // Limpa o buffer de entrada para evitar problemas na leitura da string

    // Aloca dinamicamente memória para a string, considerando o tamanho informado pelo usuário
    // O '+1' é para garantir espaço para o caractere nulo '\0', que indica o final da string
    ponteiro = (char *) malloc(sizeof(char) * tamanho + 1);

    // Verifica se a alocação de memória foi bem-sucedida
    if (ponteiro == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1; // Sai do programa se a alocação falhar
    }

    // Solicita ao usuário que informe a string
    printf("Informe a string: ");
    fgets(ponteiro, tamanho + 1, stdin); // Lê a string com no máximo 'tamanho' caracteres, incluindo o '\0'

    // Loop para percorrer a string até o tamanho especificado
    for (int i = 0; i <= tamanho; i++) {
        // Verifica se o caractere atual não é uma vogal (tanto maiúscula quanto minúscula)
        if (*(ponteiro + i) != 'a' && *(ponteiro + i) != 'A' &&
            *(ponteiro + i) != 'e' && *(ponteiro + i) != 'E' &&
            *(ponteiro + i) != 'i' && *(ponteiro + i) != 'I' &&
            *(ponteiro + i) != 'o' && *(ponteiro + i) != 'O' &&
            *(ponteiro + i) != 'u' && *(ponteiro + i) != 'U') {
            // Se não for uma vogal, imprime o caractere na tela
            printf("%c", *(ponteiro + i));
        }
    }

    // Libera a memória alocada para a string
    free(ponteiro);
    ponteiro = NULL; // Define o ponteiro como NULL por segurança

    return 0;
}
