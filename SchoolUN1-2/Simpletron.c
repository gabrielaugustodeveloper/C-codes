#include <stdio.h>

// Definindo as constantes
#define MEMORY_SIZE 100    // Tamanho da mem�ria (n�mero total de posi��es de mem�ria)
#define SENTINEL -99999     // Valor sentinela para terminar a entrada de dados
#define MAX_VALUE 9999      // Valor m�ximo permitido para a mem�ria
#define MIN_VALUE -9999     // Valor m�nimo permitido para a mem�ria

// Registradores
int memoria[MEMORY_SIZE];  // Array que representa a mem�ria do Simpletron
int acumulador = 0;        // Registrador do acumulador (armazena resultados intermedi�rios)
int contadorInstrucao = 0; // Registrador do contador de instru��es (indica a posi��o da instru��o a ser executada)
int registroInstrucao = 0; // Registrador que armazena a instru��o atual
int codigoOperacao = 0;    // C�digo da opera��o extra�do da instru��o
int operando = 0;          // Operando extra�do da instru��o

// Fun��o auxiliar para imprimir o estado dos registradores e da mem�ria
void printDump() {
    printf("REGISTRADORES:\n");
    printf("acumulador \t\t %+05d\n", acumulador);          // Imprime o valor do acumulador
    printf("contadorInstrucao \t %02d\n", contadorInstrucao); // Imprime o valor do contador de instru��es
    printf("registroInstrucao \t %+05d\n", registroInstrucao); // Imprime o valor do registrador de instru��o
    printf("codigoOperacao \t\t %02d\n", codigoOperacao);    // Imprime o c�digo da opera��o
    printf("operando \t\t %02d\n", operando);                // Imprime o operando

    printf("\nMEM�RIA:\n");

    // Imprime os n�meros das colunas (�ndices de 0 a 9)
    printf("    ");
    for (int i = 0; i < 10; i++) {
        printf("  %2d  ", i); // Espa�amento extra para melhorar o alinhamento das colunas
    }
    printf("\n");

    // Imprime os valores da mem�ria
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (i % 10 == 0) {
            // Imprime o n�mero da linha e um espa�o extra para alinhamento
            printf("%02d ", i);
        }
        printf("%+05d ", memoria[i]); // Imprime o valor da mem�ria com formata��o
        if (i % 10 == 9) {
            printf("\n"); // Pular linha ap�s cada 10 colunas para melhorar a leitura
        }
    }
    printf("\n");
}

int main() {
    // Mensagem inicial para o usu�rio
    printf("*** Bem vindo ao Simpletron! ***\n");
    printf("*** Por favor, digite uma instru��o (ou palavra de dados) de seu programa por vez. ***\n");
    printf("*** Para cada posi��o da mem�ria (indicada por um n�mero de 00 a 99), digite a palavra para aquela posi��o. ***\n");
    printf("*** Digite o valor sentinela -99999 para encerrar a digita��o de seu programa. ***\n");

    // Fase de carregamento do programa
    int posicao = 0; // Inicializa a posi��o da mem�ria
    while (posicao < MEMORY_SIZE) {
        int instrucao;
        printf("%02d ? ", posicao); // Solicita a instru��o para a posi��o atual
        scanf("%d", &instrucao);

        if (instrucao == SENTINEL) break; // Encerra a entrada se o valor sentinela for digitado

        // Verificando se a instru��o est� dentro do intervalo v�lido
        while (instrucao < MIN_VALUE || instrucao > MAX_VALUE) {
            printf("Instrucao invalida. Por favor, digite novamente.\n");
            printf("%02d ? ", posicao); // Solicita a instru��o novamente se estiver fora do intervalo
            scanf("%d", &instrucao);
        }

        memoria[posicao++] = instrucao; // Armazena a instru��o na mem�ria e avan�a para a pr�xima posi��o
    }

    printf("*** Carregamento do programa conclu�do ***\n");
    printf("*** In�cio da execu��o do programa ***\n");

    // Fase de execu��o do programa
    while (1) {
        // Busca a pr�xima instru��o da mem�ria e a decodifica
        registroInstrucao = memoria[contadorInstrucao];
        codigoOperacao = registroInstrucao / 100; // Extrai o c�digo da opera��o
        operando = registroInstrucao % 100;       // Extrai o operando

        // Incrementa o contador de instru��es para a pr�xima instru��o
        contadorInstrucao++;

        // Executa a opera��o baseada no c�digo da opera��o
        switch (codigoOperacao) {
            case 10: // READ
                printf("? ");
                scanf("%d", &memoria[operando]); // L� um valor para a posi��o de mem�ria especificada
                while (memoria[operando] < MIN_VALUE || memoria[operando] > MAX_VALUE) {
                    printf("Valor inv�lido. Por favor, digite novamente.\n? ");
                    scanf("%d", &memoria[operando]); // Solicita um valor v�lido
                }
                break;

            case 11: // WRITE
                printf("%+05d\n", memoria[operando]); // Imprime o valor da posi��o de mem�ria especificada
                break;

            case 20: // LOAD
                acumulador = memoria[operando]; // Carrega o valor da mem�ria para o acumulador
                break;

            case 21: // STORE
                memoria[operando] = acumulador; // Armazena o valor do acumulador na mem�ria
                break;

            case 30: // ADD
                acumulador += memoria[operando]; // Adiciona o valor da mem�ria ao acumulador
                if (acumulador < MIN_VALUE || acumulador > MAX_VALUE) {
                    printf("*** Erro fatal: Overflow do acumulador ***\n");
                    printDump(); // Imprime o estado atual do Simpletron
                    return -1; // Encerra o programa com erro
                }
                break;

            case 31: // SUBTRACT
                acumulador -= memoria[operando]; // Subtrai o valor da mem�ria do acumulador
                if (acumulador < MIN_VALUE || acumulador > MAX_VALUE) {
                    printf("*** Erro fatal: Overflow do acumulador ***\n");
                    printDump(); // Imprime o estado atual do Simpletron
                    return -1; // Encerra o programa com erro
                }
                break;

            case 32: // DIVIDE
                if (memoria[operando] == 0) {
                    printf("*** Erro fatal: Tentativa de divis�o por zero ***\n");
                    printDump(); // Imprime o estado atual do Simpletron
                    return -1; // Encerra o programa com erro
                }
                acumulador /= memoria[operando]; // Divide o acumulador pelo valor da mem�ria
                break;

            case 33: // MULTIPLY
                acumulador *= memoria[operando]; // Multiplica o acumulador pelo valor da mem�ria
                if (acumulador < MIN_VALUE || acumulador > MAX_VALUE) {
                    printf("*** Erro fatal: Overflow do acumulador ***\n");
                    printDump(); // Imprime o estado atual do Simpletron
                    return -1; // Encerra o programa com erro
                }
                break;

            case 40: // BRANCH
                contadorInstrucao = operando; // Faz um salto incondicional para a posi��o especificada
                break;

            case 41: // BRANCHNEG
                if (acumulador < 0)
                    contadorInstrucao = operando; // Faz um salto para a posi��o especificada se o acumulador for negativo
                break;

            case 42: // BRANCHZERO
                if (acumulador == 0)
                    contadorInstrucao = operando; // Faz um salto para a posi��o especificada se o acumulador for zero
                break;

            case 43: // HALT
                printf("*** Execu��o do Simpletron conclu�da ***\n");
                printDump(); // Imprime o estado final do Simpletron
                return 0; // Encerra o programa com sucesso

            default:
                printf("*** Erro fatal: C�digo de opera��o inv�lido ***\n");
                printDump(); // Imprime o estado atual do Simpletron
                return -1; // Encerra o programa com erro
        }
    }
}

