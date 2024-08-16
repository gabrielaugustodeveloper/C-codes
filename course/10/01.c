#include <stdio.h>

// Check if PI is not already defined; if not, define it with the value of π
#ifndef PI
#define PI 3.14159265359
#endif

int main() {

    // Declare and initialize an integer variable 'value' with 5
    int value = 5;

    // Update the value of 'value' to 467
    value = 467;

    // Print the current value of 'value'
    printf("The value is %d\n", value);

    // Print the value of 2 times PI using the defined constant PI
    printf("The value of 2 PI is %f\n", (2 * PI));

    return 0; // Return 0 to indicate successful execution
}
