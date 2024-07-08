#include <stdio.h>

#define MAX_TAMANHO 50

// Protótipos das funções
void inserirValor(int vetor[], int *qtd, int valor);
void buscarValor(int vetor[], int qtd, int valor);
void exibirVetor(int vetor[], int qtd);

int main() {
    // Declaração de dois vetores para armazenar números pares e ímpares
    int pares[MAX_TAMANHO] = {0}, impares[MAX_TAMANHO] = {0};
    // Contadores para a quantidade de números pares e ímpares inseridos
    int qtdPares = 0, qtdImpares = 0;
    int valor, continuar = 1;
  
    // Loop principal para inserção de valores nos vetores
    while (continuar == 1 && qtdPares < MAX_TAMANHO && qtdImpares < MAX_TAMANHO) {
        printf("Digite um valor para inserir no vetor (ou -1 para sair): ");
        scanf("%d", &valor);

        // Condição de saída do loop
        if (valor == -1){
            break;
        }

        // Verifica se o valor é par ou ímpar e insere no vetor correspondente
        if (valor % 2 == 0) {
            inserirValor(pares, &qtdPares, valor);
        } else {
            inserirValor(impares, &qtdImpares, valor);
        }

        // Pergunta ao usuário se deseja continuar inserindo valores
        printf("Deseja continuar? (1 - Sim, 0 - Não): ");
        scanf("%d", &continuar);    
    }  
    
    // Exibe os vetores de pares e ímpares
    printf("\nVetor de pares: ");
    exibirVetor(pares, qtdPares);
    printf("\nVetor de ímpares: ");
    exibirVetor(impares, qtdImpares);
    
    // Exemplo de busca em cada vetor
    printf("\nDigite um valor para buscar no vetor de pares: ");
    scanf("%d", &valor);
    buscarValor(pares, qtdPares, valor);
    
    printf("\nDigite um valor para buscar no vetor de ímpares: ");
    scanf("%d", &valor);
    buscarValor(impares, qtdImpares, valor);

    return 0;
}
    
// Função para inserir valor no vetor
void inserirValor(int vetor[], int *qtd, int valor) {
    // Verifica se ainda há espaço no vetor
    if (*qtd < MAX_TAMANHO) {
        vetor[*qtd] = valor; // Insere o valor na próxima posição livre
        (*qtd)++; // Incrementa a quantidade de elementos no vetor
    } else {
        printf("Vetor cheio!\n");
    }
}

// Função para buscar um valor no vetor
void buscarValor(int vetor[], int qtd, int valor) {
    int encontrado = 0;
    // Percorre o vetor em busca do valor
    for (int i = 0; i < qtd; i++) {
        if (vetor[i] == valor) {
            printf("Valor encontrado na posição %d\n", i + 1); // Posições são apresentadas ao usuário começando de 1
            encontrado = 1;
            break; // Encerra o loop após encontrar o valor
        }
    }
    if (!encontrado) {
        printf("Valor não encontrado\n");
    }
}

// Função para exibir os valores armazenados no vetor
void exibirVetor(int vetor[], int qtd) {
    // Percorre o vetor e imprime cada valor
    for (int i = 0; i < qtd; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}