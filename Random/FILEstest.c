#include <stdio.h>

int main() {
    FILE *file;
    char ch;

    // Abrir um arquivo para escrita
    file = fopen("example.txt", "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    // Escrever dados no arquivo
    fputs("Hello, World!!!\n", file);
    fclose(file);

    // Abrir o mesmo arquivo para leitura
    file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    // Ler e imprimir os dados do arquivo
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
    return 0;
}
