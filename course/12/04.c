#include <stdio.h>
#include <stdlib.h> // Inclui a biblioteca para uso de malloc e free

int main(){
    // Declaração de um ponteiro para inteiro 'p' e variáveis para o número de linhas e colunas
    int *p, linhas = 3, colunas = 3;

    // Alocação dinâmica de memória para uma matriz 2D de 3x3 elementos (9 inteiros)
    // A quantidade de memória alocada é igual a 'linhas * colunas * sizeof(int)'
    p = (int *) malloc(linhas * colunas * sizeof(int));

    // Preenchimento da matriz usando notação de ponteiro:
    // Acessa e atribui valores a cada elemento da matriz
    // Cada elemento é calculado como 3 * i + j
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            p[i * colunas + j] = 3 * i + j;
        }
    }

    // Exibe os valores da matriz:
    // Percorre cada elemento da matriz e imprime seu valor
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%d\n", p[i * colunas + j]);
        }
    }

    // Libera a memória alocada dinamicamente para a matriz
    free(p);
    p = NULL; // Define o ponteiro como NULL para evitar acesso a memória desalocada

    return 0;
}
