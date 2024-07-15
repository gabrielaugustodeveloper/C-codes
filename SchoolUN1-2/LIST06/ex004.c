#include <stdio.h>

int main() {
    float nota01[20]; // Vetor para armazenar a primeira nota de 20 alunos
    float nota02[20]; // Vetor para armazenar a segunda nota de 20 alunos
    float media[20]; // Vetor para armazenar a média das notas de cada aluno
    float mediaTurma = 0; // Variável para calcular a média da turma
    int abaixoDaMedia = 0; // Contador para alunos com média abaixo da média da turma
    

    // Solicita ao usuário para digitar as notas dos alunos
    printf("Digite as notas dos alunos:\n");
    for (int i = 0; i < 20; i++) {
        printf("Digite a primeira nota %d: ", i + 1);
        scanf("%f", &nota01[i]); // Lê a primeira nota do aluno i
        printf("Digite a segunda nota %d: ", i + 1);
        scanf("%f", &nota02[i]); // Lê a segunda nota do aluno i
        // Calcula a média ponderada das notas do aluno i
        media[i] = ((nota01[i] * 2) + (nota02[i] * 3)) / 5;
        // Soma a média do aluno i à média total da turma
        mediaTurma += media[i];
    }
        
    // Calcula a média da turma dividindo a soma total das médias dos alunos por 20
    mediaTurma /= 20;
   
    // Exibe a média de cada aluno e verifica se está abaixo da média da turma
    for (int i = 0; i < 20; i++) {
        printf("A media do aluno %d foi: %.2f\n", i + 1, media[i]);
        // Se a média do aluno for menor que a média da turma, incrementa o contador abaixoDaMedia
        if (media[i] < mediaTurma) {
            abaixoDaMedia++;
        }
    }
   
    // Exibe a média da turma
    printf("A media da turma foi: %.2f\n", mediaTurma);
    // Exibe o número de alunos com média abaixo da média da turma
    printf("Numero de alunos com media abaixo da media da turma: %d\n", abaixoDaMedia);

    return 0; // Finaliza o programa
}