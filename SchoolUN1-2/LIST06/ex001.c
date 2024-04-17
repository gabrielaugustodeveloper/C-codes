#include <stdio.h>



int main (){
   int tamanho; 
   
   
   printf("Digite o tamanho do array: ");
   scanf("%d", &tamanho);
   
   int numbers[tamanho];
   printf("Digite os valores do array:\n ");
   for (int i = 0; i < tamanho; i++){

        printf("Valor %d: ", i + 1);
        scanf("%d", &numbers[i]);
   }

   


    return 0;
}