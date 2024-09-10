#include <stdio.h>

#define TAMPILHA 10  // Define o tamanho da pilha como 10

// Pilha / Stack
int pilha[TAMPILHA] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  // Inicializa a pilha com zeros
int topo = 0;  // Indica o índice atual do topo da pilha

// Função para listar os elementos da pilha
void lista_elementos() {
    printf("\n====================PILHA ATUAL====================\n");
    // Percorre toda a pilha e imprime os elementos
    for (int i = 0; i < TAMPILHA; i++) {
        printf("-");
        printf("|%d|", pilha[i]);
        printf("-");
    }
    printf("\nTopo: %d\n", topo);  // Mostra a posição do topo
    printf("\n\n");
}

// Função para adicionar um elemento na pilha
void push() {
    int val;
    // Verifica se há espaço na pilha
    if (topo < TAMPILHA) {
        printf("Informe o elemento para adicionar na pilha: ");
        scanf("%d", &val);  // Lê o valor a ser inserido
        pilha[topo] = val;  // Adiciona o valor no topo da pilha
        topo = topo + 1;    // Atualiza o topo
        lista_elementos();  // Lista a pilha após a inserção
    } else {
        printf("A pilha está cheia!!!");  // Mensagem de erro se a pilha estiver cheia
    }
}

// Função para remover um elemento da pilha
void pop() {
    // Verifica se a pilha não está vazia
    if (topo > 0) {
        topo = topo - 1;    // Atualiza o topo
        pilha[topo] = 0;    // Remove o valor do topo da pilha (definindo como 0)
        lista_elementos();  // Lista a pilha após a remoção
    } else {
        printf("A pilha está vazia!!!");  // Mensagem de erro se a pilha estiver vazia
    }
}

// Função para limpar a pilha
void clear() {
    // Define todos os elementos da pilha como 0
    for (int i = 0; i < TAMPILHA; i++) {
        pilha[i] = 0;
    }
    topo = 0;  // Reseta o topo
    lista_elementos();  // Lista a pilha após a limpeza
}

int main() {
    int opcao = 0;

    do {
        printf("Informe a opção desejada:\n");
        printf("[1] - Inserir (push): \n");
        printf("[2] - Remover (pop): \n");
        printf("[3] - Listar: \n");
        printf("[4] - Limpar a pilha: \n");
        printf("[-1] - Sair. \n");
        printf("Opção: ");
        scanf("%d", &opcao);  // Lê a opção do usuário

        switch (opcao) {
            case 1:
                push();  // Chama a função push para adicionar um elemento
                break;
            case 2:
                pop();  // Chama a função pop para remover um elemento
                break;
            case 3:
                lista_elementos();  // Chama a função lista_elementos para mostrar a pilha
                break;
            case 4:
                clear();  // Chama a função clear para limpar a pilha
                break;
            case -1:
                printf("Saindo do programa...\n");  // Mensagem de saída
                break;
            default:
                printf("Opção inválida!!!\n");  // Mensagem para opções inválidas
                break;
        }
    } while (opcao != -1);  // Continua executando até que o usuário escolha sair

    return 0;
}
