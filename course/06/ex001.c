#include <stdio.h>

int main() {
    // Variable declarations.
    int i = 10;
    float f = 20.5;
    char c = 'G';
    
    // Pointer declarations.
    // Initializing pointers to NULL to avoid them pointing to random memory locations.
    int *pi = NULL;
    float *pf = NULL;
    char *pc = NULL;
    
    // Associate the variables with the pointers using the & operator.
    pi = &i;
    pf = &f;
    pc = &c;
    
    // Print the values of the variables before modification.
    printf("Before modification:\n");
    printf("i = %d\n", i);
    printf("f = %.2f\n", f);
    printf("c = %c\n", c);
    
    // Modify the values of the variables using the pointers.
    *pi = 15;
    *pf = 30.5;
    *pc = 'A';
    
    // Print the values of the variables after modification.
    printf("After modification:\n");
    printf("i = %d\n", i);
    printf("f = %.2f\n", f);
    printf("c = %c\n", c);
    
    return 0;
}
