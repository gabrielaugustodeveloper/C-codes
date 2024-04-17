#include <stdio.h>

int main() {
    float valor_investimento;

    
    printf("Digite o valor do investimento (ou um valor negativo para sair): ");
    scanf("%f", &valor_investimento);

    
    while (valor_investimento > 0) {
        
        printf("Para um investimento de R$ %.2f, você pode fazer as seguintes aplicacoes:\n", valor_investimento);
        
        if (valor_investimento >= 100) {
            printf("- Poupanca: rentabilidade mensal de %.2f%%\n", 0.5);
        }
        if (valor_investimento >= 1000) {
            printf("- Fundo Renda Fixa: rentabilidade mensal de %.2f%%\n", 1.0);
        }
        if (valor_investimento >= 2500) {
            printf("- CDBs: rentabilidade mensal de %.2f%%\n", 1.5);
        }

        
        printf("\nDigite o valor do proximo investimento (ou um valor negativo para sair): ");
        scanf("%f", &valor_investimento);
    }

    printf("Programa encerrado.\n");

    return 0;
}