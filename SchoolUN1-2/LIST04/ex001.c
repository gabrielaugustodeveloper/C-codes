#include <stdio.h>

int num;

int main() {
    
  do{
     
    printf("Digite um numero entre 1 e 100:\n");
    scanf("%d", &num);
   
   if (num < 1 || num > 100){
   	printf("Numero fora do intervalo de 1 a 100!\n");
   	
   }
   
    }
    while(num < 1 || num > 100); 
	   
	   printf("Numero valido digitado: %d\n", num);
	
    return 0;
}