#include <stdio.h>

const int MEMORY_SIZE = 100;
const int SENTINEL = -99999;
const int MAX_VAL = 9999;
const int MIN_VAL = -9999;

int memoria[MEMORY_SIZE];
int acumulador = 0;           // Inicializado como +0000
int contadorInstrucao = 0;    // Inicializado como 00
int registroInstrucao = 0;    // Inicializado como +0000
int codigoOperacao = 0;       // Inicializado como 00
int operando = 0;             // Inicializado como 00

void exibirEstado() {
    printf("REGISTRADORES:\n");
    printf("acumulador        %+05d\n", acumulador);
    printf("contadorInstrucao %02d\n", contadorInstrucao);
    printf("registroInstrucao %+05d\n", registroInstrucao);
    printf("codigoOperacao    %02d\n", codigoOperacao);
    printf("operando          %02d\n", operando);
    
    printf("\nMEMÓRIA:\n");
    printf("    ");
    for (int i = 0; i < 10; i++) {
        printf("  %2d  ", i);
    }
    printf("\n");

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

int main() {
    printf("*** Bem-vindo ao Simpletron! ***\n");
    printf("*** Digite uma instrução ou dado por vez. ***\n");
    printf("*** Use o número de 00 a 99 para a posição na memória. ***\n");
    printf("*** Para finalizar, digite %d. ***\n", SENTINEL);

    int pos = 0;
    while (pos < MEMORY_SIZE) {
        int entrada;
        printf("%02d ? ", pos);
        scanf("%d", &entrada);
        
        if (entrada == SENTINEL) {
            break;
        }

        while (entrada < MIN_VAL || entrada > MAX_VAL) {
            printf("Valor inválido. Tente novamente.\n");
            printf("%02d ? ", pos);
            scanf("%d", &entrada);
        }
        
        memoria[pos++] = entrada;
    }

    printf("*** Carregamento completo ***\n");
    printf("*** Iniciando execução ***\n");

    while (1) {
        // Carrega a instrução atual e separa código de operação e operando
        registroInstrucao = memoria[contadorInstrucao];
        codigoOperacao = registroInstrucao / 100;
        operando = registroInstrucao % 100;

        contadorInstrucao++;
        
        // Executa a operação com base no código
        switch (codigoOperacao) {
            case 10: // READ
                printf("? ");
                scanf("%d", &memoria[operando]);
                while (memoria[operando] < MIN_VAL || memoria[operando] > MAX_VAL) {
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
                if (acumulador < MIN_VAL || acumulador > MAX_VAL) {
                    printf("*** Erro: Overflow do acumulador ***\n");
                    exibirEstado();
                    return -1;
                }
                break;

            case 31: // SUBTRACT
                acumulador -= memoria[operando];
                if (acumulador < MIN_VAL || acumulador > MAX_VAL) {
                    printf("*** Erro: Overflow do acumulador ***\n");
                    exibirEstado();
                    return -1;
                }
                break;

            case 32: // DIVIDE
                if (memoria[operando] == 0) {
                    printf("*** Erro: Divisão por zero ***\n");
                    exibirEstado();
                    return -1;
                }
                acumulador /= memoria[operando];
                break;

            case 33: // MULTIPLY
                acumulador *= memoria[operando];
                if (acumulador < MIN_VAL || acumulador > MAX_VAL) {
                    printf("*** Erro: Overflow do acumulador ***\n");
                    exibirEstado();
                    return -1;
                }
                break;

            case 40: // BRANCH
                contadorInstrucao = operando;
                break;

            case 41: // BRANCHNEG
                if (acumulador < 0) {
                    contadorInstrucao = operando;
                }
                break;

            case 42: // BRANCHZERO
                if (acumulador == 0) {
                    contadorInstrucao = operando;
                }
                break;

            case 43: // HALT
                printf("*** Execução concluída ***\n");
                exibirEstado();
                return 0;

            default:
                printf("*** Erro: Código de operação inválido ***\n");
                exibirEstado();
                return -1;
        }
    }
}
