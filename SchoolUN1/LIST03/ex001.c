#include <stdio.h>

int num1, num2;

int main() {
    
    printf("Informe o primeiro numero:");
    scanf("%d", &num1); 
    printf("Informe o segundo numero:");
    scanf("%d", &num2);

    if(num1 > num2){
        printf("%d e maior que %d", num1, num2);
    }
    else if(num1 < num2){
    	printf("%d e maior que %d", num2, num1);
	}
	else if(num1 = num2){
		printf("%d e igual a %d", num1, num2);
	}
    return 0;
}