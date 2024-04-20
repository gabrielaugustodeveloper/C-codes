#include <stdio.h>

int main(){
    int num;//A int variable called "num".
    int square;//A int variable to use for square root.
    printf("Enter a number:\n");
    scanf("%d", &num);
    square = num * num;//Makes the square root logic.
    printf("The square of %d is %d", num, square);//And shows the result of the square root.

    return 0;
}