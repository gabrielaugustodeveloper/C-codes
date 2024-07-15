#include <stdio.h>

int main() {
    float nota01[20]; // Declara um vetor para armazenar a primeira nota de 20 alunos
    float nota02[20]; // Declara um vetor para armazenar a segunda nota de 20 alunos
    float media[20];  // Declara um vetor para armazenar a média das notas de 20 alunos
    

    // Solicita ao usuário para digitar as notas dos alunos
    printf("Digite as notas dos alunos:\n");
    for (int i = 0; i < 20; i++) { // Loop para ler as notas de cada um dos 20 alunos
        printf("Digite a primeira nota %d: ", i + 1); // Solicita a primeira nota
        scanf("%f", &nota01[i]); // Lê e armazena a primeira nota no vetor nota01
        printf("Digite a segunda nota %d: ", i + 1); // Solicita a segunda nota
        scanf("%f", &nota02[i]); // Lê e armazena a segunda nota no vetor nota02
        // Calcula a média ponderada das notas, considerando peso 2 para a primeira nota e peso 3 para a segunda nota
        media[i] = ((nota01[i] * 2) + (nota02[i] * 3)) / 5;
    }

    // Exibe a média de cada aluno
    for (int i = 0; i < 20; i++) { // Loop para percorrer o vetor de médias
        printf("A media do aluno %d foi: %.2f\n", i + 1, media[i]); // Mostra a média do aluno i+1
    }

    return 0; // Finaliza o programa
}