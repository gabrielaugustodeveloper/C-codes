#include <stdio.h>

int main() {
    int num_carros_vendidos;
    float valor_total_vendas, salario_total;

    // Solicita ao usuário o número de carros vendidos
    printf("Digite o número de carros vendidos no mês: ");
    scanf("%d", &num_carros_vendidos);

    // Solicita ao usuário o valor total das vendas
    printf("Digite o valor total das vendas no mês: R$");
    scanf("%f", &valor_total_vendas);

    // Calcula o salário total do vendedor
    salario_total = 800 + (100 * num_carros_vendidos) + (0.05 * valor_total_vendas);

    // Imprime o salário total do vendedor
    printf("O salário total do vendedor neste mês é: R$%.2f\n", salario_total);

    return 0;
}