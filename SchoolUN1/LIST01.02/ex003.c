#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main() {
    float raio, circunferencia, area;

 
    printf("Digite o raio do circulo: ");
    scanf("%f", &raio);


    circunferencia = 2 * PI * raio;


    area = PI * pow(raio, 2); //a funcao pow() e fornecida pela biblioteca padrao de C math.h, ela e usada para calcular uma potencia de um numero. Neste caso, pow(raio, 2) esta calculando o quadrado do raio.

 
    printf("Circunferencia do circulo: %.2f\n", circunferencia);
    printf("Area do circulo: %.2f\n", area);

    return 0;
}