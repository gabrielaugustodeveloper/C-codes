#include <stdio.h>

// Define a new type name for float using typedef
typedef float grade;

int main() {
    // Declare variables of type grade
    grade test1 = 7.0;
    grade test2 = 8.0;
    grade test3 = 9.0;

    // Calculate the average of the three test grades
    grade average = (test1 + test2 + test3) / 3;
    
    // Print the average to two decimal places
    printf("The average is: %.2f\n", average);

    return 0;
}
