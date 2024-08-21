#include <stdio.h>
#include <stdlib.h>

int main() {

    int *p;
     
    p = (int *) malloc(3 * sizeof(int)); //Não remove o lixo de memória
    //p = (int *) calloc(3, sizeof(int)); //Remove o lixo de memória
    
    if(p){

        printf("A variável 'p' ocupa %ld bytes de memória.\n", 3 * sizeof(int));
        printf("Valor de p[0]: %d\n", p[0]);
        printf("Valor de p[1]: %d\n", p[1]);
        printf("Valor de p[2]: %d\n", p[2]);
    }else{
        printf("Memória insuficiente\n");
        return 1;
    }


    //Liberar memória alocada
    free(p);
    p = NULL; // Medida de segurança

    return 0;
}