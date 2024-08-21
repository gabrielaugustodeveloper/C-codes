#include <stdio.h>
#include <stdlib.h>

int main() {

    int qtd, *p;

    printf("Informe a quantidade de elementos para o vetor: ");
    scanf("%d", &qtd);

    p = (int *) malloc(qtd * sizeof(int)); // Suposição: 3 * 4 = 12 bytes

    for (int i = 0; i < qtd; i++) {
        printf("Informe o valor para a posição %d do vetor: ", i);
        scanf("%d", &p[i]);
    }

    for (int i = 0; i < qtd; i++) {
        printf("No vetor 'numeros[%d]' está o valor %d \n", i, p[i]);
    }

    printf("A variavel 'p' ocupa %ld bytes de memória.\n", qtd * sizeof(int));

    printf("Informe a quantidade de elementos para o vetor: ");
    scanf("%d", &qtd);

    p = (int *) realloc(p, qtd * sizeof(int)); // Suposição: 5 * 4 = 20 bytes //Realloc aloca mais memória para o vetor p 

    printf("A variavel 'p' ocupa %ld bytes de memória.\n", qtd * sizeof(int));

    //Liberar memória alocada
    free(p);
    p = NULL; // Medida de segurança

    return 0;
}