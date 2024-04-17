#include <stdio.h>

int num;
int result;

int main() {
    
    printf("Informe um numero:");
    scanf("%d", &num); 
    result = num % 2;
    
	
	if(result == 0){
        printf("%d e par", num);
    }
    else if(result == 1){
    	printf("%d e impar", num);
	} 

    return 0;
}