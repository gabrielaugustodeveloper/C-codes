#include <stdio.h>

#define NUM_QUESTOES 10 // Define o número total de questões na prova
#define NUM_ALUNOS 20 // Define o número total de alunos na turma

int main(){
    char gabarito[NUM_QUESTOES], respostas[NUM_QUESTOES]; // Vetores para armazenar o gabarito e as respostas dos alunos
    int i, j, nota, aprovados = 0; // Variáveis de controle e contagem

    // Leitura do gabarito das questões
    printf("Digite o gabarito das questões:\n");
    for(i = 0; i < NUM_QUESTOES; i++){ // Loop para ler o gabarito de cada questão
        printf("Resposta da questão %d: ", i + 1);
        scanf(" %c", &gabarito[i]); // Armazena a resposta correta no vetor gabarito
    }

    // Processamento das respostas dos alunos
    for(i = 0; i < NUM_ALUNOS; i++){ // Loop externo para cada aluno
        printf("\nRespostas do aluno %d:\n", i + 1);
        nota = 0; // Inicializa a nota do aluno atual
        for(j = 0; j < NUM_QUESTOES; j++){ // Loop interno para cada resposta do aluno
            printf("Resposta da questão %d: ", j + 1);
            scanf(" %c", &respostas[j]); // Lê a resposta do aluno
            if(respostas[j] == gabarito[j]){ // Compara a resposta do aluno com o gabarito
                nota++; // Incrementa a nota se a resposta estiver correta
            }
        }
        printf("Nota do aluno %d: %d\n", i + 1, nota); // Exibe a nota do aluno
        if(nota >= 7){ // Verifica se o aluno está aprovado (nota >= 7)
            aprovados++; // Incrementa o contador de aprovados
        }
    }

    // Exibição dos resultados finais
    printf("\nNúmero de alunos aprovados: %d\n", aprovados); // Exibe o total de alunos aprovados
    // Calcula e exibe a percentagem de aprovação na turma
    printf("Percentagem de aprovação: %.2f%%\n", (aprovados / (float)NUM_ALUNOS) * 100);

  return 0; // Finaliza o programa
}