#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gerarNumero();

int main() {
    char opcao;
    
    do {
        printf("Escolha a opcao desejada:\n");
        printf("1. Responder uma pergunta\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf(" %c", &opcao);
        
        switch (opcao) {
            case '1': {
                int operand1, operand2, resultado, acertou = 0;

                srand(time(NULL));

                operand1 = gerarNumero();
                operand2 = gerarNumero();

                printf("Quanto e %d vezes %d? ", operand1, operand2);
                scanf("%d", &resultado);

                do {
                    if (resultado == operand1 * operand2) {
                        printf("Muito Bem!\n");
                        acertou = 1;
                    } else {
                        printf("Errrrrrrrouu! Tente de novo! :(\n");
                        printf("Quanto e %d vezes %d? ", operand1, operand2);
                        scanf("%d", &resultado);
                    }
                } while (acertou == 0);

                break;
            }
            case '0':
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
        }
    } while (opcao != '0');

    return 0;
}

int gerarNumero() {
    return rand() % 10;
}