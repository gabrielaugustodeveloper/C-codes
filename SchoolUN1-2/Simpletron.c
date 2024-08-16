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
void printDump() {
    printf("REGISTRADORES:\n");
    printf("acumulador \t\t %+05d\n", acumulador);          // Imprime o valor do acumulador
    printf("contadorInstrucao \t %02d\n", contadorInstrucao); // Imprime o valor do contador de instruções
    printf("registroInstrucao \t %+05d\n", registroInstrucao); // Imprime o valor do registrador de instrução
    printf("codigoOperacao \t\t %02d\n", codigoOperacao);    // Imprime o código da operação
    printf("operando \t\t %02d\n", operando);                // Imprime o operando

    printf("\nMEMÓRIA:\n");

    // Imprime os números das colunas (índices de 0 a 9)
    printf("    ");
    for (int i = 0; i < 10; i++) {
        printf("  %2d  ", i); // Espaçamento extra para melhorar o alinhamento das colunas
    }
    printf("\n");

    // Imprime os valores da memória
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (i % 10 == 0) {
            // Imprime o número da linha e um espaço extra para alinhamento
            printf("%02d ", i);
        }
        printf("%+05d ", memoria[i]); // Imprime o valor da memória com formatação
        if (i % 10 == 9) {
            printf("\n"); // Pular linha após cada 10 colunas para melhorar a leitura
        }
    }
    printf("\n");
}

int main() {
    // Mensagem inicial para o usuário
    printf("*** Bem vindo ao Simpletron! ***\n");
    printf("*** Por favor, digite uma instrução (ou palavra de dados) de seu programa por vez. ***\n");
    printf("*** Para cada posição da memória (indicada por um número de 00 a 99), digite a palavra para aquela posição. ***\n");
    printf("*** Digite o valor sentinela -99999 para encerrar a digitação de seu programa. ***\n");

    // Fase de carregamento do programa
    int posicao = 0; // Inicializa a posição da memória
    while (posicao < MEMORY_SIZE) {
        int instrucao;
        printf("%02d ? ", posicao); // Solicita a instrução para a posição atual
        scanf("%d", &instrucao);

        if (instrucao == SENTINEL) break; // Encerra a entrada se o valor sentinela for digitado

        // Verificando se a instrução está dentro do intervalo válido
        while (instrucao < MIN_VALUE || instrucao > MAX_VALUE) {
            printf("Instrucao invalida. Por favor, digite novamente.\n");
            printf("%02d ? ", posicao); // Solicita a instrução novamente se estiver fora do intervalo
            scanf("%d", &instrucao);
        }

        memoria[posicao++] = instrucao; // Armazena a instrução na memória e avança para a próxima posição
    }

    printf("*** Carregamento do programa concluído ***\n");
    printf("*** Início da execução do programa ***\n");

    // Fase de execução do programa
    while (1) {
        // Busca a próxima instrução da memória e a decodifica
        registroInstrucao = memoria[contadorInstrucao];
        codigoOperacao = registroInstrucao / 100; // Extrai o código da operação
        operando = registroInstrucao % 100;       // Extrai o operando

        // Incrementa o contador de instruções para a próxima instrução
        contadorInstrucao++;

        // Executa a operação baseada no código da operação
        switch (codigoOperacao) {
            case 10: // READ
                printf("? ");
                scanf("%d", &memoria[operando]); // Lê um valor para a posição de memória especificada
                while (memoria[operando] < MIN_VALUE || memoria[operando] > MAX_VALUE) {
                    printf("Valor inválido. Por favor, digite novamente.\n? ");
                    scanf("%d", &memoria[operando]); // Solicita um valor válido
                }
                break;

            case 11: // WRITE
                printf("%+05d\n", memoria[operando]); // Imprime o valor da posição de memória especificada
                break;

            case 20: // LOAD
                acumulador = memoria[operando]; // Carrega o valor da memória para o acumulador
                break;

            case 21: // STORE
                memoria[operando] = acumulador; // Armazena o valor do acumulador na memória
                break;

            case 30: // ADD
                acumulador += memoria[operando]; // Adiciona o valor da memória ao acumulador
                if (acumulador < MIN_VALUE || acumulador > MAX_VALUE) {
                    printf("*** Erro fatal: Overflow do acumulador ***\n");
                    printDump(); // Imprime o estado atual do Simpletron
                    return -1; // Encerra o programa com erro
                }
                break;

            case 31: // SUBTRACT
                acumulador -= memoria[operando]; // Subtrai o valor da memória do acumulador
                if (acumulador < MIN_VALUE || acumulador > MAX_VALUE) {
                    printf("*** Erro fatal: Overflow do acumulador ***\n");
                    printDump(); // Imprime o estado atual do Simpletron
                    return -1; // Encerra o programa com erro
                }
                break;

            case 32: // DIVIDE
                if (memoria[operando] == 0) {
                    printf("*** Erro fatal: Tentativa de divisão por zero ***\n");
                    printDump(); // Imprime o estado atual do Simpletron
                    return -1; // Encerra o programa com erro
                }
                acumulador /= memoria[operando]; // Divide o acumulador pelo valor da memória
                break;

            case 33: // MULTIPLY
                acumulador *= memoria[operando]; // Multiplica o acumulador pelo valor da memória
                if (acumulador < MIN_VALUE || acumulador > MAX_VALUE) {
                    printf("*** Erro fatal: Overflow do acumulador ***\n");
                    printDump(); // Imprime o estado atual do Simpletron
                    return -1; // Encerra o programa com erro
                }
                break;

            case 40: // BRANCH
                contadorInstrucao = operando; // Faz um salto incondicional para a posição especificada
                break;

            case 41: // BRANCHNEG
                if (acumulador < 0)
                    contadorInstrucao = operando; // Faz um salto para a posição especificada se o acumulador for negativo
                break;

            case 42: // BRANCHZERO
                if (acumulador == 0)
                    contadorInstrucao = operando; // Faz um salto para a posição especificada se o acumulador for zero
                break;

            case 43: // HALT
                printf("*** Execução do Simpletron concluída ***\n");
                printDump(); // Imprime o estado final do Simpletron
                return 0; // Encerra o programa com sucesso

            default:
                printf("*** Erro fatal: Código de operação inválido ***\n");
                printDump(); // Imprime o estado atual do Simpletron
                return -1; // Encerra o programa com erro
        }
    }
}

