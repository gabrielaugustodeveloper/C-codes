#include <stdio.h>

int main() {
    float nota01[20];
    float nota02[20];
    float media[20];
    

    printf("Digite as notas dos alunos:\n");
    for (int i = 0; i < 20; i++) {
        printf("Digite a primeira nota %d: ", i + 1);
        scanf("%f", &nota01[i]);
        printf("Digite a segunda nota %d: ", i + 1);
        scanf("%f", &nota02[i]);
        media[i] = ((nota01[i] * 2) + (nota02[i] * 3)) / 5;
    }

    for (int i = 0; i < 20; i++) {
        printf("A media do aluno %d foi: %.2f\n", i + 1, media[i]);
    }

    return 0;
}
