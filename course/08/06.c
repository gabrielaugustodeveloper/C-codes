#include <stdio.h>

// Union definition to store multiple integers
union numbers {
    int num1, num2, num3, num4, num5; // All members share the same memory location, total size 20 bytes
} n; 

int main() {
    int sum = 0; // Variable to store the sum of the numbers, 4 bytes

    // Assign values to the union members and add them to the sum
    n.num1 = 1;
    sum += n.num1; // This is equivalent to sum = sum + n.num1
    printf("The value of num1 is: %d\n", n.num1);

    n.num2 = 2;
    sum += n.num2; // Overwrites the previous value in the union
    printf("The value of num2 is: %d\n", n.num2);

    n.num3 = 3;
    sum += n.num3; // Overwrites the previous value in the union
    printf("The value of num3 is: %d\n", n.num3);

    n.num4 = 4;
    sum += n.num4; // Overwrites the previous value in the union
    printf("The value of num4 is: %d\n", n.num4);

    n.num5 = 5;
    sum += n.num5; // Overwrites the previous value in the union
    printf("The value of num5 is: %d\n", n.num5);

    // Print the current values of all union members (all share the same memory location)
    printf("The value of num1 is: %d\n", n.num1);
    printf("The value of num2 is: %d\n", n.num2);
    printf("The value of num3 is: %d\n", n.num3);
    printf("The value of num4 is: %d\n", n.num4);
    printf("The value of num5 is: %d\n", n.num5);

    // Print the size of the union
    printf("n is occupying %ld bytes in memory\n", sizeof(n));

    // Print the sum of the numbers
    printf("The sum of the numbers is: %d\n", sum);

    // Print the total memory occupied
    printf("Total memory occupied %ld bytes\n", sizeof(n) + sizeof(sum));

    return 0;
}
