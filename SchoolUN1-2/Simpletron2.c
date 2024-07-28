#include <stdio.h>

// Constantes
const int MEMORY_SIZE = 100;   // Tamanho da memória
const int SENTINEL = -99999;    // Valor para terminar a entrada de dados
const int MAX_VALUE = 9999;     // Valor máximo permitido
const int MIN_VALUE = -9999;    // Valor mínimo permitido

// Registradores
int memoria[100];   // Memória do Simpletron
int acumulador = 0; // Acumulador
int contadorInstrucao = 0; // Contador de instruções
int registroInstrucao = 0; // Instrução atual
int codigoOperacao = 0;    // Código da operação
int operando = 0;          // Operando da instrução

// Função para imprimir o estado dos registradores e da memória
void printDump() {
    printf("REGISTRADORES:\n");
    printf("acumulador \t\t %+05d\n", acumulador);
    printf("contadorInstrucao \t %02d\n", contadorInstrucao);
    printf("registroInstrucao \t %+05d\n", registroInstrucao);
    printf("codigoOperacao \t\t %02d\n", codigoOperacao);
    printf("operando \t\t %02d\n", operando);
    
    printf("\nMEMORIA:\n");

    // Imprime números das colunas
    printf("    ");
    for (int i = 0; i < 10; i++) {
        printf("  %2d  ", i);
    }
    printf("\n");

    // Imprime valores da memoria
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (i % 10 == 0) {
            printf("%02d ", i); // Numero da linha
        }
        printf("%+05d ", memoria[i]); // Valor da memoria
        if (i % 10 == 9) {
            printf("\n"); // Nova linha a cada 10 valores
        }
    }
    printf("\n");
}

int main() {
    // Mensagens iniciais
    printf("*** Bem vindo ao Simpletron! ***\n");
    printf("*** Por favor, digite uma instrucao (ou palavra de dados) de seu programa por vez. ***\n");
    printf("*** Para cada posicao da memoria (indicada por um numero de 00 a 99), digite a palavra para aquela posicao. ***\n");
    printf("*** Digite o valor sentinela -99999 para encerrar a digitacao de seu programa. ***\n");

    // Carregamento do programa
    int posicao = 0; // Posicao na memoria
    while (posicao < MEMORY_SIZE) {
        int instrucao;
        printf("%02d ? ", posicao);
        scanf("%d", &instrucao);
        
        if (instrucao == SENTINEL) break; // Encerra a entrada

        // Verifica a validade da instrucao
        while (instrucao < MIN_VALUE || instrucao > MAX_VALUE) {
            printf("Instrucao invalida. Digite novamente.\n");
            printf("%02d ? ", posicao);
            scanf("%d", &instrucao);
        }
        
        memoria[posicao++] = instrucao; // Armazena a instrução
    }

    printf("*** Carregamento concluido ***\n");
    printf("*** Inicio da execucao ***\n");

    // Execucao do programa
    while (1) {
        // Decodifica e executa a instrucao
        registroInstrucao = memoria[contadorInstrucao];
        codigoOperacao = registroInstrucao / 100;
        operando = registroInstrucao % 100;

        contadorInstrucao++; // Avança o contador
        
        switch (codigoOperacao) {
            case 10: // READ
                printf("? ");
                scanf("%d", &memoria[operando]);
                while (memoria[operando] < MIN_VALUE || memoria[operando] > MAX_VALUE) {
                    printf("Valor invalido. Digite novamente.\n? ");
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
                    printDump(); // Imprime estado atual
                    return -1;
                }
                break;

            case 31: // SUBTRACT
                acumulador -= memoria[operando];
                if (acumulador < MIN_VALUE || acumulador > MAX_VALUE) {
                    printf("*** Erro fatal: Overflow do acumulador ***\n");
                    printDump(); // Imprime estado atual
                    return -1;
                }
                break;

            case 32: // DIVIDE
                if (memoria[operando] == 0) {
                    printf("*** Erro fatal: Divisao por zero ***\n");
                    printDump(); // Imprime estado atual
                    return -1;
                }
                acumulador /= memoria[operando];
                break;

            case 33: // MULTIPLY
                acumulador *= memoria[operando];
                if (acumulador < MIN_VALUE || acumulador > MAX_VALUE) {
                    printf("*** Erro fatal: Overflow do acumulador ***\n");
                    printDump(); // Imprime estado atual
                    return -1;
                }
                break;

            case 40: // BRANCH
                contadorInstrucao = operando;
                break;

            case 41: // BRANCHNEG
                if (acumulador < 0) contadorInstrucao = operando;
                break;

            case 42: // BRANCHZERO
                if (acumulador == 0) contadorInstrucao = operando;
                break;

            case 43: // HALT
                printf("*** Execucao concluida ***\n");
                printDump(); // Imprime estado final
                return 0;

            default:
                printf("*** Erro fatal: Codigo invalido ***\n");
                printDump(); // Imprime estado atual
                return -1;
        }
    }
}
