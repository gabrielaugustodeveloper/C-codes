#include <stdio.h>

int idade;

int main() {
    
    printf("Informe sua idade:");
    scanf("%d", &idade); 

    if(idade >= 18){
        printf("Essa pessoa tem %d e e maior de idade! >:)", idade);
    }
    else if(idade <= 17){
    	printf("Essa pessoa tem %d e nao e maior de idade! >:(", idade);
	} 
    return 0;
}