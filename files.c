#include <stdio.h>

int main()
{
    FILE *pontf;
    const char *fileText[255] = {0};


    pontf = fopen("gabrielArquivos2013", "w"); 

    if(pontf == NULL)
    {
        printf("error");
        return 1;
    }

    fprintf(pontf, "hello, Gabriel\n");
}