#include <stdio.h>

int main() {
    int var1, var2;
    
    // Read the values of the variables from the keyboard
    printf("Enter the value of the first variable: ");
    scanf("%d", &var1);
    printf("Enter the value of the second variable: ");
    scanf("%d", &var2);

    // Compare the addresses and display which address is larger
    if (&var1 > &var2) {
        printf("The address of the first variable (var1) is larger and its value is: %d\n", var1);
    } else {
        printf("The address of the second variable (var2) is larger and its value is: %d\n", var2);
    }

    return 0;
}
//Remember that, you are comparing the size of the address and not the variable