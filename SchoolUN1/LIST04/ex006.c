#include <stdio.h>

int main() {
    int numero, i, j;
    char letra = 'A';

    printf("Digite o numero de ramos da sua arvore: ");
    scanf("%d", &numero);

    for (i = 1; i <= numero; ++i) {
         
		 for (j = 1; j <= i; ++j){
		 
		 printf("%c", letra);
		 
		 }
		
		printf("\n");
		letra++;
		
    }

    return 0;
}