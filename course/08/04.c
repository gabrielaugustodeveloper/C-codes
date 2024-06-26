#include <stdio.h>

int main() {
    
    int number = 44;
    float grade = 9.5;
    char letter = 'G';
    double anotherGrade = 9.6;

    // Print the value and size of the integer variable
    printf("The variable 'number' has the value %d and occupies %ld bytes in memory\n", number, sizeof(number));
    printf("The variable 'grade' has the value %.2f and occupies %ld bytes in memory\n", grade, sizeof(grade));
    printf("The variable 'letter' has the value %c and occupies %ld bytes in memory\n", letter, sizeof(letter));
    printf("The variable 'anotherGrade' has the value %.2f and occupies %ld bytes in memory\n", anotherGrade, sizeof(anotherGrade));

    return 0;
}