#include <stdio.h>

int main(){
    int num01, num02, num03;//Declares three numbers variables.

    printf("Enter the first number:\n");
    scanf("%d", &num01);//Scan the first number. 
    printf("Enter the second number:\n");
    scanf("%d", &num02);//Scan the second number. 
    printf("Enter the third number:\n");
    scanf("%d", &num03);//Scan the third number. 

    int result = num01 + num02 + num03;//Create a new variable and do math.
    printf("%d plus %d plus %d is %d", num01, num02, num03, result);//Shows the result.

    return 0;
}