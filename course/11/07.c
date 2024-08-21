#include <stdio.h>
#include <time.h>

int main() {
    // Declaração de variáveis para armazenar os tempos de início, fim e total em clocks
    long int inicio_t, fim_t, total_t;

    // Armazena o tempo atual em clocks no início da operação
    inicio_t = clock();
    printf("Realizar um loop grande, inicio_t = %ld\n", inicio_t);
    
    // Executa um loop grande, mas sem realizar nenhuma operação
    for (int i = 0; i < 1000000; i++) {
        // não faz nada
    }
    
    // Armazena o tempo em clocks após o término do loop
    fim_t = clock();
    printf("Fim do loop grande, fim_t = %ld\n", fim_t);

    // Calcula o tempo total usado pela CPU em segundos, convertendo de clocks
    total_t = (double)((double)fim_t - (double)inicio_t) / (double)CLOCKS_PER_SEC;

    // Exibe a quantidade de clocks por segundo na máquina atual
    printf("Clocks por segundo: %ld\n", CLOCKS_PER_SEC);
    
    // Exibe o tempo total usado pela CPU para executar o loop
    printf("Tempo total usado pela CPU: %lf\n", (double)total_t);
    
    // Indica o fim do programa
    printf("Fim do programa\n");

    return 0;
}
