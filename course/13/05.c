#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura para um nó da árvore binária
struct st_arvore {
    int valor;              // Valor armazenado no nó
    struct st_arvore *esq;  // Ponteiro para a sub-árvore esquerda
    struct st_arvore *dir;  // Ponteiro para a sub-árvore direita
};

typedef struct st_arvore arvore; // Define um tipo 'arvore' para facilitar o uso da estrutura

// Função que cria uma nova árvore, inicializando-a como vazia (NULL)
arvore* criaArvore(){
    return NULL;
}

// Verifica se a árvore está vazia (ou seja, aponta para NULL)
int arvoreVazia(arvore* t){
    return t == NULL;
}

// Exibe a árvore em um formato que destaca a estrutura hierárquica
void exibeArvore(arvore* t){
    printf("<"); // Início de um nó
    if(!arvoreVazia(t)){ // Se o nó não estiver vazio
        printf("%d ", t->valor); // Imprime o valor do nó
        exibeArvore(t->esq);     // Recursivamente exibe a sub-árvore esquerda
        exibeArvore(t->dir);     // Recursivamente exibe a sub-árvore direita
    }
    printf(">"); // Fim de um nó
}

// Insere um novo valor na árvore de forma recursiva
void insereDadoArvore(arvore** t, int num){
    if(*t == NULL){ // Se o nó atual estiver vazio, insere o novo valor aqui
        *t = (arvore*) malloc(sizeof(arvore)); // Aloca memória para o novo nó
        (*t)->esq = NULL; // Inicializa o ponteiro esquerdo como NULL
        (*t)->dir = NULL; // Inicializa o ponteiro direito como NULL
        (*t)->valor = num; // Armazena o valor no nó
    }else{
        if(num < (*t)->valor){ // Se o valor for menor que o valor do nó atual
            insereDadoArvore(&(*t)->esq, num); // Insere na sub-árvore esquerda
        }else{ // Se o valor for maior ou igual ao valor do nó atual
            insereDadoArvore(&(*t)->dir, num); // Insere na sub-árvore direita
        }
    }
}

// Verifica se um valor está presente na árvore
int estaNaArvore(arvore* t, int num){
    if(arvoreVazia(t)){ // Se a árvore ou sub-árvore for vazia, o valor não está presente
        return 0;
    }
    // Retorna verdadeiro se o valor estiver no nó atual ou em qualquer sub-árvore
    return t->valor == num || estaNaArvore(t->esq, num) || estaNaArvore(t->dir, num);
}

// Função principal
int main(){
    arvore* t = criaArvore(); // Cria uma nova árvore

    // Insere valores na árvore
    insereDadoArvore(&t, 10);
    insereDadoArvore(&t, 5);
    insereDadoArvore(&t, 15);
    insereDadoArvore(&t, 2);

    // Exibe a estrutura da árvore
    exibeArvore(t);

    // Verifica se a árvore está vazia
    if(arvoreVazia(t)){
        printf("\nÁrvore vazia!\n");
    }else{
        printf("\nÁrvore NÃO vazia!\n");
    }

    // Verifica se valores específicos estão na árvore
    if(estaNaArvore(t, 5)){
        printf("Está na árvore!(5)\n");
    }else{
        printf("NÃO está na árvore!(5)\n");
    }
    
    if(estaNaArvore(t, 7)){
        printf("Está na árvore!(7)\n");
    }else{
        printf("NÃO está na árvore!(7)\n");
    }
    
    free(t); // Libera a memória alocada para a árvore principal

    return 0; // Encerra o programa
}
