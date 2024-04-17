#include <stdio.h>
#include <string.h>


float peso;
float altura;
char sexo[10];
float pesoideal;
float margem_erro = 0.01;

int main() {
    
    printf("Informe seu peso(em kg):\n");
    scanf("%f", &peso); 
    printf("Informe sua altura(em m):\n");
    scanf("%f", &altura); 
	printf("Informe seu sexo biologico(masculino/feminino):\n");
	scanf("%s", &sexo);
	
	if (strcmp(sexo, "masculino") == 0) { 
       
	   pesoideal = 72.7 * altura - 58;
	   
	   printf("O seu peso ideal e %.1f\n", pesoideal);
       if (peso - pesoideal > margem_erro) {
        printf("Voce esta acima do seu peso ideal!\n");
    }  else if (pesoideal - peso > margem_erro) {
        printf("Voce esta abaixo do seu peso ideal!\n");
    }  else {
        printf("Voce esta no seu peso ideal!\n");
    }

	}
    
	
	else if (strcmp(sexo, "feminino") == 0) {
    	
		pesoideal = 62.1 * altura - 44.7;
		
		printf("O seu peso ideal e %.1f\n", pesoideal);
       if (peso - pesoideal > margem_erro) {
        printf("Voce esta acima do seu peso ideal!\n");
    }  else if (pesoideal - peso > margem_erro) {
        printf("Voce esta abaixo do seu peso ideal!\n");
    }  else {
        printf("Voce esta no seu peso ideal!\n");
    }
   
   
    }
  	
	return 0;
}