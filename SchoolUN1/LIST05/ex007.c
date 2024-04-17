#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUMERO_LANCAMENTO 100
int lancarMoeda();

int main (){
	
	int caras = 0, coroas = 0, cont;
	
	srand(time(NULL));
	
	for(cont = 0; cont < NUMERO_LANCAMENTO; cont++){
	
	if(lancarMoeda() == 0){
		printf("[%d]Coroa\n", cont+1);
		coroas++;
	}
	else {
		printf("[%d]Cara\n", cont+1);
		caras++;
	} }}

    int lancarMoeda(){
    	
        return rand()%2;
	
	}