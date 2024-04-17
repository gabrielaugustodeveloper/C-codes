#include <stdio.h>
#include <string.h> // para strcmp()
#include <math.h> // para funções matemáticas mais avançadas
#include <locale.h>// para conseguir imprimir caracteres especiais

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    char operador;
    double num1;
    double num2;
    double result;
    char feel[10]; // Já que "feel" é uma string, eu tenho que adicionar o número de carateres máximo 
    char language[10];
    
	
    printf("Hello, what language do you speak? (portuguese/english)\n"); //parte que botei para escolher o idioma da calculadora 
    scanf("%19s", language); //"%19s" especifica que scanf() deve ler uma string de caracteres (um array de caracteres) fornecida pelo usu?rio e indica que o maximo de caracteres que podem ser lidos ? 19 

 
    if (strcmp(language, "english") == 0 || strcmp(language, "portuguese") == 0) { // botei strcmp para comparar a string armazenada na variavel language com a string literal "english" 
        if (strcmp(language, "english") == 0) { //se escolher ingles
            
			
    
	printf("Hi! How are you? (fine/bad)\n"); // botei como uma forma de testar o idioma selecionado
    scanf("%s", feel);

    if (strcmp(feel, "fine") == 0) { //strcmp()` é uma função em C que compara duas strings
        printf("Cool!\n");
    }
    else if (strcmp(feel, "bad") == 0) {
    	printf("Bruh\n");
	}
	
	printf("What operator do you want to use?(+, -, *, /, ^, r (square root of first number)\n");
	scanf(" %c", &operador);
	
	printf("Enter the first number:");
	scanf("%lf", &num1);
	
	printf("Enter the second number:");
	scanf("%lf", &num2);

	switch(operador) {         //switch para examinar o operador
		case '+':
			result = num1 + num2;// botei 3 casas decimais em +, -, * e /        e 2 casas em ^ e r
			printf("\nresult %.3lf + %.3lf = %.3lf ", num1, num2, result);
			break;
		
		case '-':
			result = num1 - num2;
			printf("\nresult %.3lf - %.3lf = %.3lf ", num1, num2, result);
			break;
		
		case '*':
			result = num1 * num2;
			printf("\nresult %.3lf * %.3lf = %.3lf ", num1, num2, result);
			break;
		
		case '/':
			result = num1 / num2;
			printf("\nresult %.3lf / %.3lf = %.3lf ", num1, num2, result);
			break;
		
		case '^':
			result = pow(num1, num2);
            printf("\nresult %.2lf ^ %.2lf = %.2lf\n", num1, num2, result);
            break; 
        
        case 'r':
        	if (num1 >= 0){
        		
        		result = sqrt(num1);
        		printf("the square root of  %.2lf is = %.2lf\n", num1, result);
            } else {
                printf("It is not possible to calculate the square root of a negative numeber.\n");
            }
            break;
			
		//"break" seria um jeito de parar no caso selcionado e nao passar para o proximo
		
		
		
		default:
			printf("Good try, but %c is not valid for this!", operador); // aparece isso se a pessoa escrever algo diferente do que lhe foi pedido
			

	}
       
	   
	   
	   
	   
	   
	   
	   
	   
	    } else if (strcmp(language, "portuguese") == 0) { //e o mesmo codigo so que em portugues agora
           	
	printf("Olá, como está você? (bem/mal)\n");
    scanf("%s", feel);

    if (strcmp(feel, "bem") == 0) { 
        printf("Legal!\n");
    }
    else if (strcmp(feel, "mal") == 0) {
    	printf("Bruh\n");
	}
	
	printf("Qual operador você deseja usar?(+, -, *, /, ^, r (raiz quadrada do primeiro numero)\n");
	scanf(" %c", &operador);
	
	printf("Digite o primeiro número:");
	scanf("%lf", &num1);
	
	printf("Digite o segundo número:");
	scanf("%lf", &num2);

	switch(operador) {         //switch para examinar o operador
		case '+':
			result = num1 + num2;
			printf("\nresult %.3lf + %.3lf = %.3lf ", num1, num2, result);
			break;
		
		case '-':
			result = num1 - num2;
			printf("\nresult %.3lf - %.3lf = %.3lf ", num1, num2, result);
			break;
		
		case '*':
			result = num1 * num2;
			printf("\nresult %.3lf * %.3lf = %.3lf ", num1, num2, result);
			break;
		
		case '/':
			result = num1 / num2;
			printf("\nresult %.3lf / %.3lf = %.3lf ", num1, num2, result);
			break;
		
		case '^':
			result = pow(num1, num2);
            printf("\nresult %.2lf ^ %.2lf = %.2lf\n", num1, num2, result);
            break;
        
        case 'r':
        	if (num1 >= 0){
        		
        		result = sqrt(num1);
        		printf("a raiz quadrada de %.2lf é = %.2lf\n", num1, result);
            } else {
                printf("Não é possível calcular a raiz quadrada de um número negativo.\n");
            }
            break;
			
		
		
		
		
		default:
			printf("Boa tentativa, mas %c nao e valido para isso!", operador);
			

	}
	 
	 
	 
	 
	 
	    }
    } else {
        printf("Invalid language.\n");// e isso se a pessoa escolher outro idioma que nao seja ingles e nem portugues
        return 0;
    }

	
	

	
	
	
	return 0;
    //Obrigado Gabriel! >;)
}


