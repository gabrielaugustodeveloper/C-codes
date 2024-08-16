#include <stdio.h>

// Recursive function to calculate the factorial of n
int recursive(int n, int total) {

    // Base case: when n is 1
    if (n == 1) {
        printf("Total: %d\n", total);
        return total;
    }

    // Multiply total by n and make the recursive call
    total = total * n;
    
    // Recursively call the function with n-1
    return recursive(n - 1, total);
}

int main() {
    int n;
    
    printf("Enter a number: ");
    scanf("%d", &n);
    
    // Call the recursive function with n and total initialized to 1
    recursive(n, 1);

    return 0;
}
