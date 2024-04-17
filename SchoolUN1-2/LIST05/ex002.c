#include <stdio.h>
#include <stdlib.h>

int potencia(int x, int n) {
    if (n == 0)
    return 1;
    
    else
       return x * potencia(x, n - 1);
}

int fatorial(int numF) {
    int fat = 1;
    for (int i = numF; i > 1; i--){
    	fat = fat * i;
	}
    return fat;
}

int main() {
    char opcao;
    float valor;
    int n, x;
    
    do {
        printf("Escolha a conversao desejada:\n");
        printf("1. Fatorial\n");
        printf("2. Potenciacao\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                printf("Digite o numero: ");
                scanf("%d", &n);
                printf("O fatorial e %d\n", fatorial(n));
                break;
            case '2':
                printf("Digite o valor para x e para n: ");
                scanf("%d%d", &x, &n);
                printf("Resultado de %d elevado a %d: %d\n", x, n, potencia(x, n));
                break;
            case '0':
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
        }
    } while (opcao != '0');

    return 0;
}