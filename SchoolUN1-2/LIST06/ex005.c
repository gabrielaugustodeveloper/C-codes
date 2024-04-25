#include <stdio.h>

int main() {
    float totalmes[12];
    float total2022 = 0;
    int mesmenor = 0;
    int mesmaior = 0;
    

    printf("Digite o apurado das vendas de cada mes:\n");
    for (int i = 0; i < 12; i++) {
        printf("Digite o do mes %d: ", i + 1);
        scanf("%f", &totalmes[i]);
        total2022 = total2022 + totalmes[i];
    }
   
    for (int i = 0; i < 12; i++) {
        printf("O total do mes %d foi: %.2f\n", i + 1, totalmes[i]);
         if (totalmes[i] < totalmes[mesmenor]) {
            mesmenor = i + 1;
        }
         if (totalmes[i] > totalmes[mesmaior]) {
            mesmaior = i + 1;
        }
    
    }
   
    printf("O total de 2022 foi: %.2f\n", total2022);
    printf("O mes com o menor faturamento foi o %d\n", mesmenor);
    printf("O mes com o maior faturamento foi o %d\n", mesmaior);
    

    return 0;
}
