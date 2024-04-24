#include <stdio.h>

int main() {
    int arrayA[10];
    int arrayB[10];


    printf("Digite os valores do array:\n");
    for (int i = 0; i < 10; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &arrayA[i]);
        
        if (arrayA[i] % 2 == 0){
     
        arrayB[i] = arrayA[i] / 2;

        }
       else {
        
        arrayB[i] = arrayA[i] * 3;

       }
    }

    for (int i = 0; i < 10; i++) {
            printf("Elemento %d do arrayA:\n", i + 1);
            printf("%d\n", arrayA[i]);
     
    }
    for (int i = 0; i < 10; i++) {
            printf("Elemento %d do arrayB:\n", i + 1);
            printf("%d\n", arrayB[i]);
    }

    return 0;
}
