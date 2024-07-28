#include <stdio.h>

// Definindo as constantes
#define MEMORY_SIZE 100    // Tamanho da memória (número total de posições de memória)
#define SENTINEL -99999     // Valor sentinela para terminar a entrada de dados
#define MAX_VALUE 9999      // Valor máximo permitido para a memória
#define MIN_VALUE -9999     // Valor mínimo permitido para a memória

// Registradores
int memoria[MEMORY_SIZE];  // Array que representa a memória do Simpletron
int acumulador = 0;        // Registrador do acumulador (armazena resultados intermediários)
int contadorInstrucao = 0; // Registrador do contador de instruções (indica a posição da instrução a ser executada)
int registroInstrucao = 0; // Registrador que armazena a instrução atual
int codigoOperacao = 0;    // Código da operação extraído da instrução
int operando = 0;          // Operando extraído da instrução

// Função auxiliar para imprimir o estado dos registradores e da memória
void printEstado() {
    printf("REGISTRADORES:\n");
    printf("acumulador         %+05d\n", acumulador);
    printf("contadorInstrucao  %02d\n", contadorInstrucao);
    printf("registroInstrucao  %+05d\n", registroInstrucao);
    printf("codigoOperacao     %02d\n", codigoOperacao);
    printf("operando           %02d\n", operando);

    printf("\nMEMÓRIA:\n");
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (i % 10 == 0) {
            printf("%02d ", i);
        }
        printf("%+05d ", memoria[i]);
        if (i % 10 == 9) {
            printf("\n");
        }
    }
    printf("\n");
}

// Função para carregar o programa na memória
void carregarPrograma() {
    int posicao = 0;
    while (posicao < MEMORY_SIZE) {
        int entrada;
        printf("%02d ? ", posicao);
        scanf("%d", &entrada);

        // Verifica se a entrada é o valor sentinela
        if (entrada == SENTINEL) break;

        // Verifica se a entrada está dentro do intervalo válido
        while (entrada < MIN_VALUE || entrada > MAX_VALUE) {
            printf("Valor inválido. Tente novamente.\n");
            printf("%02d ? ", posicao);
            scanf("%d", &entrada);
        }

        memoria[posicao++] = entrada; // Armazena a instrução na memória e avança para a próxima posição
    }
}

// Função para executar o programa
void executarPrograma() {
    while (1) {
        // Verifica se o contador de instrução está dentro dos limites da memória
        if (contadorInstrucao < 0 || contadorInstrucao >= MEMORY_SIZE) {
            printf("*** Erro: Contador de instrução fora dos limites da memória ***\n");
            printEstado();
            return;
        }

        // Busca e decodifica a instrução
        registroInstrucao = memoria[contadorInstrucao];
        codigoOperacao = registroInstrucao / 100;
        operando = registroInstrucao % 100;

        // Executa a operação baseada no código da operação
        switch (codigoOperacao) {
            case 10: // READ
                printf("? ");
                scanf("%d", &memoria[operando]);
                while (memoria[operando] < MIN_VALUE || memoria[operando] > MAX_VALUE) {
                    printf("Valor inválido. Tente novamente.\n? ");
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
                if (acumulador > MAX_VALUE) {
                    acumulador = MAX_VALUE;
                    printf("*** Erro: Overflow do acumulador ***\n");
                    printEstado();
                    return;
                } else if (acumulador < MIN_VALUE) {
                    acumulador = MIN_VALUE;
                    printf("*** Erro: Underflow do acumulador ***\n");
                    printEstado();
                    return;
                }
                break;

            case 31: // SUBTRACT
                acumulador -= memoria[operando];
                if (acumulador > MAX_VALUE) {
                    acumulador = MAX_VALUE;
                    printf("*** Erro: Overflow do acumulador ***\n");
                    printEstado();
                    return;
                } else if (acumulador < MIN_VALUE) {
                    acumulador = MIN_VALUE;
                    printf("*** Erro: Underflow do acumulador ***\n");
                    printEstado();
                    return;
                }
                break;

            case 32: // DIVIDE
                if (memoria[operando] == 0) {
                    printf("*** Erro: Divisão por zero ***\n");
                    printEstado();
                    return;
                }
                acumulador /= memoria[operando];
                break;

            case 33: // MULTIPLY
                acumulador *= memoria[operando];
                if (acumulador > MAX_VALUE) {
                    acumulador = MAX_VALUE;
                    printf("*** Erro: Overflow do acumulador ***\n");
                    printEstado();
                    return;
                } else if (acumulador < MIN_VALUE) {
                    acumulador = MIN_VALUE;
                    printf("*** Erro: Underflow do acumulador ***\n");
                    printEstado();
                    return;
                }
                break;

            case 40: // BRANCH
                contadorInstrucao = operando - 1; // Ajusta o contador de instrução para o próximo loop
                break;

            case 41: // BRANCHNEG
                if (acumulador < 0)
                    contadorInstrucao = operando - 1; // Ajusta o contador de instrução para o próximo loop
                break;

            case 42: // BRANCHZERO
                if (acumulador == 0)
                    contadorInstrucao = operando - 1; // Ajusta o contador de instrução para o próximo loop
                break;

            case 43: // HALT
                printf("*** Execução concluída ***\n");
                printEstado();
                return;

            default:
                printf("*** Erro: Código de operação inválido ***\n");
                printEstado();
                return;
        }

        // Incrementa o contador de instrução para a próxima iteração
        contadorInstrucao++;
    }
}

int main() {
    printf("*** Bem-vindo ao Simpletron! ***\n");
    printf("*** Digite uma instrução ou dado por vez. ***\n");
    printf("*** Use o número de 00 a 99 para a posição na memória. ***\n");
    printf("*** Para finalizar, digite %d. ***\n", SENTINEL);

    carregarPrograma();
    printf("*** Carregamento completo ***\n");
    printf("*** Iniciando execução ***\n");

    executarPrograma();

    return 0;
}
