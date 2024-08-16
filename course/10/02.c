#include <stdio.h>

// Define the constant PI if it hasn't been defined already
#ifndef PI
#define PI 3.14159265359
#endif

int main() {

    // Declare and initialize an integer variable 'value' with 5
    int value = 5;

    // Reassign 'value' to 467, overwriting the previous value
    value = 467;

    // Print the current value of 'value'
    printf("The value is %d\n", value);

    // Print the value of 2 * PI, using the predefined constant PI
    printf("The value of 2 PI is %f\n", (2 * PI));

    // Check if PI is defined (it should be, due to the #ifndef directive)
    // If PI is defined, print its value
    #ifdef PI
    printf("The value of PI is %f\n", PI);
    #endif

    return 0;
}
