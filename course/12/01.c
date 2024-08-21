#include <stdio.h>
#include <stdlib.h>

int main() {

    // Declaração de variáveis:
    // 'qtd' armazena a quantidade de elementos que o usuário deseja para o vetor
    // 'p' é um ponteiro para o início do vetor alocado dinamicamente
    int qtd, *p;

    // Solicita ao usuário a quantidade de elementos que ele deseja no vetor
    printf("Informe a quantidade de elementos para o vetor: ");
    scanf("%d", &qtd);

    // Aloca dinamicamente memória suficiente para armazenar 'qtd' inteiros
    // A função 'malloc' retorna um ponteiro para o bloco de memória alocado
    p = (int *) malloc(qtd * sizeof(int)); // Supondo 'qtd' seja 3, aloca 3 * 4 = 12 bytes

    // Verifica se a alocação foi bem-sucedida
    if (p == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1; // Sai do programa com código de erro
    }
    
    if (p){
    // Laço para preencher o vetor:
    // Percorre cada posição do vetor e solicita ao usuário um valor para armazenar naquela posição
    for (int i = 0; i < qtd; i++) {
        printf("Informe o valor para a posição %d do vetor: ", i);
        scanf("%d", &p[i]);
    }

    // Laço para exibir os valores armazenados no vetor:
    // Percorre cada posição do vetor e imprime o valor correspondente
    for (int i = 0; i < qtd; i++) {
        printf("No vetor 'numeros[%d]' está o valor %d \n", i, p[i]);
    }

    // Exibe o total de memória ocupada pelo vetor em bytes
    printf("A variavel 'p' ocupa %ld bytes de memória.\n", qtd * sizeof(int));
    }else{ // Verifica se tem espaço na memória
        printf("Memória insuficiente\n");
        return 1; // Sai do programa com código de erro
    }

    // Libera a memória alocada dinamicamente para evitar vazamentos de memória
    free(p);
    p = NULL; // Define o ponteiro como NULL como uma medida de segurança

    return 0; // Indica que o programa terminou com sucesso
}
