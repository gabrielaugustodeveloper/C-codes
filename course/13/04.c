#include <stdio.h>
#include <stdlib.h>

// Definição de uma estrutura para um nó de uma lista encadeada
struct st_no {
    int valor;                // Valor armazenado no nó
    struct st_no *prox;       // Ponteiro para o próximo nó
};

typedef struct st_no no;      // Tipo 'no' para simplificar o uso da estrutura

// Verifica se a lista está vazia
int vazia(no *le){
    if(le->prox == NULL){     // Se o ponteiro 'prox' do nó principal for NULL, a lista está vazia
        return 1;
    }else{
        return 0;
    }
}

// Inicializa a lista encadeada, apontando o ponteiro 'prox' para NULL
void inicia(no *le){
    le->prox = NULL;
}

// Libera a memória ocupada pela lista encadeada
void libera(no *le){
    if(!vazia(le)){           // Se a lista não estiver vazia
        no *proxNo, *atual;
        atual = le->prox;     // Começa pelo primeiro nó
        while(atual != NULL){
            proxNo = atual->prox; // Guarda o próximo nó
            free(atual);          // Libera o nó atual
            atual = proxNo;       // Avança para o próximo nó
        }
    }
}

// Exibe os valores armazenados na lista
void exibe(no *le){
    if(vazia(le)){            // Se a lista estiver vazia
        printf("Lista vazia!\n\n");
        return;
    }

    no *tmp;
    tmp = le->prox;           // Começa pelo primeiro nó

    while(tmp != NULL){
        printf("%d ", tmp->valor); // Imprime o valor do nó
        tmp = tmp->prox;          // Avança para o próximo nó
    }
    printf("\n\n");
}

// Insere um novo nó no início da lista
void insereInicio(no *le){
    no *novo = (no*) malloc(sizeof(no)); // Aloca memória para o novo nó
    if(!novo){
        printf("Sem memória disponível!\n");
        exit(1);
    }
    printf("Informe o valor: ");
    scanf("%d", &novo->valor);          // Lê o valor do novo nó

    no *oldHead = le->prox;             // Armazena o ponteiro para o nó atual na cabeça
    le->prox = novo;                    // O novo nó se torna o primeiro
    novo->prox = oldHead;               // Aponta para o nó anterior da cabeça
}

// Insere um novo nó no fim da lista
void insereFim(no *le){
    no *novo = (no*)malloc(sizeof(no)); // Aloca memória para o novo nó
    if(!novo){
        printf("Sem memória disponível!\n");
        exit(1);
    }
    printf("Informe o valor: ");
    scanf("%d", &novo->valor);          // Lê o valor do novo nó
    novo->prox = NULL;                  // O novo nó não aponta para outro nó

    if(vazia(le)){                      // Se a lista estiver vazia
        le->prox = novo;                // O novo nó se torna o primeiro
    }else{
        no *tmp = le->prox;             // Começa pelo primeiro nó
        
        while(tmp->prox != NULL){       // Avança até o último nó
            tmp = tmp->prox;
        }
        tmp->prox = novo;               // O último nó aponta para o novo nó
    }
}

// Executa a operação correspondente à opção do menu
void opcao(no *le, int op){
    switch(op){
        case 0:                         // Sair
            libera(le);
            break;
        case 1:                         // Exibir lista
            exibe(le);
            break;
        case 2:                         // Adicionar nó no início
            insereInicio(le);
            break;
        case 3:                         // Adicionar nó no fim
            insereFim(le);
            break;
        case 4:                         // Zerar lista
            inicia(le);
            break;
        default:                        // Comando inválido
            printf("Comando inválido\n\n");
    }
}

// Exibe o menu e retorna a opção selecionada
int menu(){
    int opt;

    printf("Escolha a opção:\n");
    printf("0. Sair:\n");
    printf("1. Exibir lista:\n");
    printf("2. Adicionar nó no início:\n");
    printf("3. Adicionar nó no fim:\n");
    printf("4. Zerar lista:\n");
    printf("Opção: ");
    scanf("%d", &opt);

    return opt;                         // Retorna a opção selecionada
}

// Função principal
int main(){
    no *le = (no*) malloc(sizeof(no));  // Cria a lista principal
    
    if(!le){                            // Verifica se a memória foi alocada
        printf("Sem memória disponível!\n");
        exit(1);
    }

    inicia(le);                         // Inicializa a lista
    int opt;

    do{
        opt = menu();                   // Exibe o menu e obtém a opção
        opcao(le, opt);                 // Executa a operação correspondente
    }while(opt);
    free(le);                           // Libera a memória alocada para a lista principal
    return 0;
}