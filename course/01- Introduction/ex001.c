#include <stdio.h>// Is the standard input-output header file.

int main(){//The main function.
    int num;//A int variable called "num".

    printf("Enter a number:\n");//Prints the setence.
    scanf("%d", &num);//Scan the number that was typed.
    printf("You typed %d", num);//Prints the number that was typed.

    return 0;// Is a keyword used to indicate the end of the function and return control to the calling function.
}