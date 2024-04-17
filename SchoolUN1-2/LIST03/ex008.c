#include <stdio.h>

int main() {
    int numero_conta;
    float saldo_devedor, total_fatura, total_creditos, limite_credito, novo_saldo;


    printf("Digite o numero da conta: ");
    scanf("%d", &numero_conta);

    printf("Digite o saldo devedor no inicio do mes: ");
    scanf("%f", &saldo_devedor);

    printf("Digite o total da fatura referente apenas aos itens cobrados no mes: ");
    scanf("%f", &total_fatura);

    printf("Digite o total de creditos aplicados a conta do cliente no mes: ");
    scanf("%f", &total_creditos);

    printf("Digite o limite de credito permitido: ");
    scanf("%f", &limite_credito);

  
    novo_saldo = saldo_devedor + total_fatura - total_creditos;


    if (novo_saldo > limite_credito) {
        printf("\nLimite de Credito Excedido!\n");
        printf("Numero da conta: %d\n", numero_conta);
        printf("Limite de credito: %.2f\n", limite_credito);
    }

    return 0;
}