#include <stdio.h>

// Definindo as constantes
#define MEMORY_SIZE 100
#define SENTINEL -99999
#define MAX_VALUE 9999
#define MIN_VALUE -9999

// Registradores
int memoria[MEMORY_SIZE];
int acumulador = 0;
int contadorInstrucao = 0;
int registroInstrucao = 0;
int codigoOperacao = 0;
int operando = 0;

// Funções auxiliares
void printDump() {
    printf("REGISTRADORES:\n");
    printf("acumulador \t\t %+05d\n", acumulador);
    printf("contadorInstrucao \t %02d\n", contadorInstrucao);
    printf("registroInstrucao \t %+05d\n", registroInstrucao);
    printf("codigoOperacao \t\t %02d\n", codigoOperacao);
    printf("operando \t\t %02d\n", operando);
    
    printf("\nMEMÓRIA:\n");
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (i % 10 == 0) printf("\n%02d ", i);
        printf("%+05d ", memoria[i]);
    }
    printf("\n");
}

int main() {
    // Mensagem inicial
    printf("*** Bem vindo ao Simpletron! ***\n");
    printf("*** Por favor, digite uma instrução (ou palavra de dados) de seu programa por vez. ***\n");
    printf("*** Para cada posição da memória (indicada por um número de 00 a 99), digite a palavra para aquela posição. ***\n");
    printf("*** Digite o valor sentinela -99999 para encerrar a digitação de seu programa. ***\n");

    // Fase de carregamento do programa
    int posicao = 0;
    while (posicao < MEMORY_SIZE) {
        int instrucao;
        printf("%02d ? ", posicao);
        scanf("%d", &instrucao);
        
        if (instrucao == SENTINEL) break;
        
        // Verificando se a instrução está no intervalo válido
        while (instrucao < MIN_VALUE || instrucao > MAX_VALUE) {
            printf("Instrucao invalida. Por favor, digite novamente.\n");
            printf("%02d ? ", posicao);
            scanf("%d", &instrucao);
        }
        
        memoria[posicao++] = instrucao;
    }

    printf("*** Carregamento do programa concluído ***\n");
    printf("*** Início da execução do programa ***\n");

    // Fase de execução do programa
    while (1) {
        // Buscando a próxima instrução
        registroInstrucao = memoria[contadorInstrucao];
        codigoOperacao = registroInstrucao / 100;
        operando = registroInstrucao % 100;

        // Incrementando o contador de instruções
        contadorInstrucao++;
        
        switch (codigoOperacao) {
            case 10: // READ
                printf("? ");
                scanf("%d", &memoria[operando]);
                while (memoria[operando] < MIN_VALUE || memoria[operando] > MAX_VALUE) {
                    printf("Valor inválido. Por favor, digite novamente.\n? ");
                    scanf("%d", &memoria[operando]);
                }
                break;

            case 11: // WRITE
                printf("%+05d\n", memoria[operando]);
                break;

            case 20: // LOAD
                acumulador = memoria[operando];
                break;

            case 21: // STORE
                memoria[operando] = acumulador;
                break;

            case 30: // ADD
                acumulador += memoria[operando];
                if (acumulador < MIN_VALUE || acumulador > MAX_VALUE) {
                    printf("*** Erro fatal: Overflow do acumulador ***\n");
                    printDump();
                    return -1;
                }
                break;

            case 31: // SUBTRACT
                acumulador -= memoria[operando];
                if (acumulador < MIN_VALUE || acumulador > MAX_VALUE) {
                    printf("*** Erro fatal: Overflow do acumulador ***\n");
                    printDump();
                    return -1;
                }
                break;

            case 32: // DIVIDE
                if (memoria[operando] == 0) {
                    printf("*** Erro fatal: Tentativa de divisão por zero ***\n");
                    printDump();
                    return -1;
                }
                acumulador /= memoria[operando];
                break;

            case 33: // MULTIPLY
                acumulador *= memoria[operando];
                if (acumulador < MIN_VALUE || acumulador > MAX_VALUE) {
                    printf("*** Erro fatal: Overflow do acumulador ***\n");
                    printDump();
                    return -1;
                }
                break;

            case 40: // BRANCH
                contadorInstrucao = operando;
                break;

            case 41: // BRANCHNEG
                if (acumulador < 0)
                    contadorInstrucao = operando;
                break;

            case 42: // BRANCHZERO
                if (acumulador == 0)
                    contadorInstrucao = operando;
                break;

            case 43: // HALT
                printf("*** Execução do Simpletron concluída ***\n");
                printDump();
                return 0;

            default:
                printf("*** Erro fatal: Código de operação inválido ***\n");
                printDump();
                return -1;
        }
    }
}
