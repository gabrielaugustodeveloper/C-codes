#include <stdio.h>

float nota01;
float nota02; 
float notap;
float notaf;



int main() {
    
    printf("Informe sua primeira nota:\n");
    scanf("%f", &nota01); 
    printf("Informe sua segunda nota:\n");
    scanf("%f", &nota02); 
	
	notap = nota01 + nota02;
	notaf = notap / 2; 
	
	if(notaf >= 7){
       
	    printf("O aluno teve a media %.1f e esta aprovado!", notaf);
    }
    else if(notaf >= 3){
       
        printf("O aluno teve a media %.1f e esta de recuperacao!", notaf);
    }
    else if(notaf < 3){
       
        printf("O aluno teve a media %.1f e esta reprovado!", notaf);
    }
  	
	return 0;
}