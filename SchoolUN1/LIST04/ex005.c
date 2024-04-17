#include <stdio.h>

int main() {
    int numero, i, j;

    printf("Digite o numero de ramos da sua arvore: ");
    scanf("%d", &numero);

    for (i = 1; i <= numero; ++i) {
         
		 for (j = 1; j <= i; ++j){
		 
		 printf("*");
		 
		 }
		
		printf("\n");
		
    }

    return 0;
}