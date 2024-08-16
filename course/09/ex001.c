#include <stdio.h>

// Recursive function to sum the numbers from 1 to n
int recursive(int n, int total) {

    // Base case: when n is 0
    if (n == 0) {
        printf("Total: %d\n", total);
        return total;
    }

    // Accumulate the value of n in total and make the recursive call
    total = total + n;
    
    // Recursively call the function with n-1
    return recursive(n - 1, total);
}

int main() {
    int n;
    
    printf("Enter a number: ");
    scanf("%d", &n);
    
    // Call the recursive function with n and total initialized to 0
    recursive(n, 0);

    return 0;
}
