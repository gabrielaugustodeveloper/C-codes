#include <stdio.h>

const int MEMORY_SIZE = 100;
const int SENTINEL = -99999;
const int MAX_VAL = 9999;
const int MIN_VAL = -9999;

int memoria[100];
int acumulador = 0;
int contador = 0;
int instrucaoAtual = 0;
int operacao = 0;
int endMemoria = 0;

void mostrarEstado() {
    printf("REGISTRADORES:\n");
    printf("acumulador        %+05d\n", acumulador);
    printf("contador          %02d\n", contador);
    printf("instrucaoAtual    %+05d\n", instrucaoAtual);
    printf("operacao          %02d\n", operacao);
    printf("endMemoria        %02d\n", endMemoria);
    
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
        instrucaoAtual = memoria[contador];
        operacao = instrucaoAtual / 100;
        endMemoria = instrucaoAtual % 100;

        contador++;
        
        switch (operacao) {
            case 10: // READ
                printf("? ");
                scanf("%d", &memoria[endMemoria]);
                while (memoria[endMemoria] < MIN_VAL || memoria[endMemoria] > MAX_VAL) {
                    printf("Valor inválido. Tente novamente.\n? ");
                    scanf("%d", &memoria[endMemoria]);
                }
                break;

            case 11: // WRITE
                printf("%+05d\n", memoria[endMemoria]);
                break;

            case 20: // LOAD
                acumulador = memoria[endMemoria];
                break;

            case 21: // STORE
                memoria[endMemoria] = acumulador;
                break;

            case 30: // ADD
                acumulador += memoria[endMemoria];
                if (acumulador < MIN_VAL || acumulador > MAX_VAL) {
                    printf("*** Erro: Overflow do acumulador ***\n");
                    mostrarEstado();
                    return -1;
                }
                break;

            case 31: // SUBTRACT
                acumulador -= memoria[endMemoria];
                if (acumulador < MIN_VAL || acumulador > MAX_VAL) {
                    printf("*** Erro: Overflow do acumulador ***\n");
                    mostrarEstado();
                    return -1;
                }
                break;

            case 32: // DIVIDE
                if (memoria[endMemoria] == 0) {
                    printf("*** Erro: Divisão por zero ***\n");
                    mostrarEstado();
                    return -1;
                }
                acumulador /= memoria[endMemoria];
                break;

            case 33: // MULTIPLY
                acumulador *= memoria[endMemoria];
                if (acumulador < MIN_VAL || acumulador > MAX_VAL) {
                    printf("*** Erro: Overflow do acumulador ***\n");
                    mostrarEstado();
                    return -1;
                }
                break;

            case 40: // BRANCH
                contador = endMemoria;
                break;

            case 41: // BRANCHNEG
                if (acumulador < 0) {
                    contador = endMemoria;
                }
                break;

            case 42: // BRANCHZERO
                if (acumulador == 0) {
                    contador = endMemoria;
                }
                break;

            case 43: // HALT
                printf("*** Execução concluída ***\n");
                mostrarEstado();
                return 0;

            default:
                printf("*** Erro: Código de operação inválido ***\n");
                mostrarEstado();
                return -1;
        }
    }
}
