#include <stdio.h>

float real_para_dolar(float real) {
    return real * 0.3;
}

void dolar_para_real(float dolar) {
    float valor_em_real = dolar * 3.25;
    printf("%.2f dolares correspondem a %.2f reais.\n", dolar, valor_em_real);
}

int main() {
    char opcao;
    float valor;

    do {
        printf("Escolha a conversao desejada:\n");
        printf("1. Real para Dolar\n");
        printf("2. Dolar para Real\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                printf("Digite o valor em reais: ");
                scanf("%f", &valor);
                printf("%.2f reais correspondem a %.2f dolares.\n", valor, real_para_dolar(valor));
                break;
            case '2':
                printf("Digite o valor em dolares: ");
                scanf("%f", &valor);
                dolar_para_real(valor);
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