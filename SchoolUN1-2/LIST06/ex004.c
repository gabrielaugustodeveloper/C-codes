#include <stdio.h>

int main() {
    float nota01[20];
    float nota02[20];
    float media[20];
    float mediaTurma = 0;
    int abaixoDaMedia = 0;
    

    printf("Digite as notas dos alunos:\n");
    for (int i = 0; i < 20; i++) {
        printf("Digite a primeira nota %d: ", i + 1);
        scanf("%f", &nota01[i]);
        printf("Digite a segunda nota %d: ", i + 1);
        scanf("%f", &nota02[i]);
        media[i] = ((nota01[i] * 2) + (nota02[i] * 3)) / 5;
        mediaTurma = mediaTurma + media[i];
    }
        
        mediaTurma = mediaTurma / 20;
   
    for (int i = 0; i < 20; i++) {
        printf("A media do aluno %d foi: %.2f\n", i + 1, media[i]);
         if (media[i] < mediaTurma) {
            abaixoDaMedia++;
        }
    }
   
    printf("A media da turma foi: %.2f\n", mediaTurma);
    printf("Numero de alunos com media abaixo da media da turma: %d\n", abaixoDaMedia);

    

    return 0;
}
