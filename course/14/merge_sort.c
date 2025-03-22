#include <stdio.h>

void merge(int vetor[], int inicio1, int fim1, int inicio2, int fim2){
    //vetor temporário para o merge
    int temp[50];
    //variaveis auxiliares
    int i, j, k;
    //inicio do primeiro grupo
    i = inicio1;
    //inicio do segundo grupo
    j = inicio2;
    //inicio do vetor temporário
    k = 0;

    //Enquanto houver elementos nos dois grupos
    while(i <= fim1 && j <= fim2){
        //Se o elemento do primeiro grupo for menor
        if(vetor[i] < vetor[j]){
            //Coloca o elemento no vetor temporário
            temp[k++] = vetor[i++];
        }else{
            //Coloca o elemento no vetor temporário
            temp[k++] = vetor[j++];
        }
    }

    //Copia os elementos restantes do primeiro grupo
    while(i <= fim1){
        temp[k++] = vetor[i++];
    }

    //Copia os elementos restantes do segundo grupo
    while(j <= fim2){
        temp[k++] = vetor[j++];
    }
    
    //Transfere os elementos do vetor temporário para o vetor original
    for(i = inicio1, j = 0; i <= fim2; i++, j++){
        vetor[i] = temp[j];
    }
}   

void merge_sort(int vetor[], int inicio, int fim){
    //Critério de parada da recursividade
    if(inicio < fim){
        //Calcula o meio do vetor
        int meio = (inicio + fim) / 2;
        //Chama a função recursivamente para os dois subgrupos
        merge_sort(vetor, inicio, meio);
        merge_sort(vetor, meio + 1, fim);
        //Faz o merge dos subgrupos
        merge(vetor, inicio, meio, meio + 1, fim);
    }
}

int main() {
    //vetor de teste
    int vetor[6] = {8, 3, 1, 42, 12, 5};

    //Aplicando a ordenação
    merge_sort(vetor, 0, 6 - 1);

    //Apresentando o vetor ordenado
    for(int i = 0; i < 6; i++){
        printf("%d\n", vetor[i]);
    }

}
