#include <stdio.h>

int horext;
int horfalt;
int horfaltb;
int horfaltc;
int total;

int main() {
    
    printf("Informe o numero de horas extras trabalhadas:\n");
    scanf("%d", &horext); 
    printf("Informe o numero de horas faltadas:\n");
    scanf("%d", &horfalt); 
	
	horfaltb = horfalt / 3;
	horfaltc = horfaltb * 2;
	total = horext - horfaltc; //O calculo para encontrar o total de horas extra considerando as horas faltadas
	
	if(total > 40){
        printf("O funcionario recebera R$200,00 de gratificacao de Natal!\n");
    }
    else if(total > 30){
        printf("O funcionario recebera R$175,00 de gratificacao de Natal!\n");
    }
    else if(total > 20){
        printf("O funcionario recebera R$150,00 de gratificacao de Natal!\n");
    }
    else if(total > 10){
        printf("O funcionario recebera R$125,00 de gratificacao de Natal!\n");
    }
  	else{
        printf("O funcionario recebera R$100,00 de gratificacao de Natal!\n");
    }
  	
	return 0;
}