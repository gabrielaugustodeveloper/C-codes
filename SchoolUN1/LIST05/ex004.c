#include <stdio.h>
#include <stdlib.h>

int anobis(int numA) {
    if ((numA % 400 == 0) || ((numA % 4 == 0) && (numA % 100 != 0))){
        return 1; 
    } else {
        return 0; 
    }
}

int main() {
    char opcao;
    int ano;
    
    do {
    	
    	printf("Escolha a opcao desejada:\n");
        printf("1. Digitar ano\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf(" %c", &opcao);
        switch (opcao){
		 
		case '1':
		printf("Escreva o ano para verificar se e bissexto:\n");
        scanf("%d", &ano);
         if (anobis(ano)) {
        printf("%d e um ano bissexto.\n", ano);
    } else {
        printf("%d nao e um ano bissexto.\n", ano);
    }
        break;
        }
    } while (opcao != '0');

    return 0;
}