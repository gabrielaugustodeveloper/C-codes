#include <stdio.h>

int timeSer;
float salario;
float grat;


int main() {
    
    printf("Informe seu tempo de servico:\n");
    scanf("%d", &timeSer); 
    printf("Informe seu salario:\n");
    scanf("%f", &salario); 
	
		
	if(timeSer >= 10){
       
	   grat = salario * 0.2;
	   
	   
	    printf("Voce sera gratificado com %.2f", grat);
    }
    else if(timeSer <= 9){
    
	    grat = salario * 0.1;
		
		printf("Voce sera gratificado com %.2f", grat);
	} 

    return 0;
}