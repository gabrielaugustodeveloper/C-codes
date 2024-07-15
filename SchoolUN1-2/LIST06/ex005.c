#include <stdio.h>

int main() {
    float totalmes[12]; // Vetor para armazenar o total de vendas de cada mês
    float total2022 = 0; // Variável para armazenar o total de vendas do ano de 2022
    int mesmenor = 0; // Variável para armazenar o índice do mês com o menor faturamento
    int mesmaior = 0; // Variável para armazenar o índice do mês com o maior faturamento
    

    // Solicita ao usuário para digitar o total de vendas de cada mês
    printf("Digite o apurado das vendas de cada mes:\n");
    for (int i = 0; i < 12; i++) {
        printf("Digite o do mes %d: ", i + 1);
        scanf("%f", &totalmes[i]); // Lê o total de vendas do mês i
        total2022 += totalmes[i]; // Soma o total de vendas do mês i ao total do ano
    }
   
    // Exibe o total de vendas de cada mês e identifica o mês com menor e maior faturamento
    for (int i = 0; i < 12; i++) {
        printf("O total do mes %d foi: %.2f\n", i + 1, totalmes[i]);
        // Se o total de vendas do mês i for menor que o do mês atualmente com o menor faturamento, atualiza mesmenor
        if (totalmes[i] < totalmes[mesmenor]) {
            mesmenor = i; // Atualiza o índice do mês com o menor faturamento
        }
        // Se o total de vendas do mês i for maior que o do mês atualmente com o maior faturamento, atualiza mesmaior
        if (totalmes[i] > totalmes[mesmaior]) {
            mesmaior = i; // Atualiza o índice do mês com o maior faturamento
        }
    }
   
    // Exibe o total de vendas do ano de 2022
    printf("O total de 2022 foi: %.2f\n", total2022);
    // Exibe o mês com o menor faturamento, ajustando o índice para corresponder ao número do mês (1 a 12)
    printf("O mes com o menor faturamento foi o %d\n", mesmenor + 1);
    // Exibe o mês com o maior faturamento, ajustando o índice para corresponder ao número do mês (1 a 12)
    printf("O mes com o maior faturamento foi o %d\n", mesmaior + 1);

    return 0; // Finaliza o programa
}