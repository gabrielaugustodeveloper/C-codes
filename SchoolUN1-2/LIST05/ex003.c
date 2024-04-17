#include <stdio.h>

int verificaLetra(char c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        return 1; 
    } else {
        return 0; 
    }
}

int main() {
    char caractere;

    printf("Digite um caractere: ");
    scanf(" %c", &caractere);

    if (verificaLetra(caractere)) {
        printf("%c e uma letra.\n", caractere);
    } else {
        printf("%c nao e uma letra.\n", caractere);
    }

    return 0;
}