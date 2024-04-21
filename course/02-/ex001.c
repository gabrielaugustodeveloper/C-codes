#include <stdio.h>

int main(){
    int num01, num02, num03;
    
    int square01, square02, square03;//Int variable to use for square root.

    int total;//The sum of squares.
    
    printf("Enter the first number:\n");
    scanf("%d", &num01);
    square01 = num01 * num01;//Makes the square root logic.
    
    printf("Enter the second number:\n");
    scanf("%d", &num02);
    square02 = num02 * num02;//Makes the square root logic.

    printf("Enter the third number:\n");
    scanf("%d", &num03);
    square03 = num03 * num03;//Makes the square root logic.
    
    total = square01 + square02 + square03;//Makes the square math.

    printf("The square of %d plus the square of %d plus the square of %d is %d!", num01, num02, num03, total);//Prints the result.

    return 0;
}