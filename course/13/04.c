#include <stdio.h>
#include <stdlib.h>

//Lista Encadeada
struct st_no {
    int valor;
    struct st_no *prox;
};

typedef struct st_no no;


int vazia(no *le){
    if(le->prox == NULL){
        return 1;
    }else{
        return 0;
    }
} 

void inicia(no *le){
    le->prox = NULL;
}
