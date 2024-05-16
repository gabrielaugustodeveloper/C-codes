#include <stdio.h>

// Function to print lines with exclamation marks
void print_exclamations(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("!");
        }
        printf("\n");
    }
}

int main() {
    int num;

    // Prompt the user for a numeric value
    printf("Enter a number: ");
    scanf("%d", &num);

    // Call the function to print the exclamation marks pattern
    print_exclamations(num);

    return 0;
}
