#include <stdio.h>

void sequencia(int a, int b, int c) {
    int i;
    int termo_atual, termo_anterior1, termo_anterior2, termo_anterior3;

    termo_anterior3 = a;
    termo_anterior2 = b;
    termo_anterior1 = c;

    printf("Os primeiros 3 termos sao: %d, %d, %d\n", termo_anterior3, termo_anterior2, termo_anterior1);

    for (i = 4; i <= 20; i++) {
        termo_atual = termo_anterior3 + termo_anterior2 + termo_anterior1;
        printf("Termo %d: %d\n", i, termo_atual);

        termo_anterior3 = termo_anterior2;
        termo_anterior2 = termo_anterior1;
        termo_anterior1 = termo_atual;
    }
}

int main() {
    int a, b, c;

    printf("Digite os tres primeiros termos da sequencia (separados por espaco): ");
    scanf("%d %d %d", &a, &b, &c);

    sequencia(a, b, c);

    return 0;
}