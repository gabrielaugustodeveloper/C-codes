#include <stdio.h>

int main() {
    // Declare variables to store count, current number, biggest number, and smallest number.
    int count; 
    int num;
    int big;
    int small;

    // Initialize count to 1.
    count = 1;

    // Prompt user to enter the first number and read input.
    printf("Enter the number %d: ", count);
    scanf("%d", &num);

    // Initialize biggest and smallest numbers with the first number entered.
    big = num;
    small = num;

    // Loop to input 9 more numbers and find the biggest and smallest numbers.
    while (count < 10) {
        count++; // Increment count for the next number.

        // Prompt user to enter the next number and read input.
        printf("Enter the number %d: ", count);
        scanf("%d", &num);

        // Check if the current number is bigger than the biggest number found so far.
        // If yes, update the biggest number.
        if (num > big) {
            big = num;
        }
        
        // Check if the current number is smaller than the smallest number found so far.
        // If yes, update the smallest number.
        if (num < small) {
            small = num;
        }
    }

    // Print the biggest and smallest numbers.
    printf("The biggest number is: %d\n", big);
    printf("The smallest number is: %d\n", small);

    return 0;
}
