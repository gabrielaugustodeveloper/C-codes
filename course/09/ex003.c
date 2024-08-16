#include <stdio.h>

// Recursive function to convert a decimal number to binary
int binary(int n) {
    // Base case: when n is 0, return 0 (the binary of 0 is 0)
    if (n == 0) {
        return 0;
    } else {
        // Recursively compute the binary representation:
        // - n % 2 gives the current binary digit (0 or 1)
        // - binary(n / 2) recursively computes the binary digits of the quotient
        // - Multiplying by 10 shifts the binary digits to the left, aligning them correctly
        return (n % 2 + 10 * binary(n / 2));
    }
}

int main() {
    int n;

    // Prompt the user to enter a decimal number
    printf("Enter a number: ");
    scanf("%d", &n);

    // Call the binary function and print the resulting binary number
    printf("Binary: %d\n", binary(n));

    return 0;
}
