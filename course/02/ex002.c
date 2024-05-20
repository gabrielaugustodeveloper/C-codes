#include <stdio.h>

int main(){
    int grade01, grade02, grade03, grade04;//Declares four grades variables.
    float total;

    printf("Enter the first grade:\n");
    scanf("%d", &grade01);//Scan the first grade. 
    printf("Enter the second grade:\n");
    scanf("%d", &grade02);//Scan the second grade. 
    printf("Enter the third grade:\n");
    scanf("%d", &grade03);//Scan the third grade.
    printf("Enter the fourth grade:\n");
    scanf("%d", &grade04);//Scan the fourth grade. 

    total = grade01 + grade02 + grade03 + grade04;//Add it all up.
    total = total / 4;//Make the arithmetic mean.

    printf("The average grade is %.2f", total);//Shows the average grade.

    return 0;
}