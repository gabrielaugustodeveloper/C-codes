#include <stdio.h>

int main() {
    // Declaration and initialization of array A with 6 elements.
    int A[6] = {1, 0, 5, -2, -5, 7};
    
    // Calculation of the sum of specific elements in array A.
    int sum = A[0] + A[1] + A[5];
    
    // Printing the sum and the elements used in the calculation
    printf("The sum of %d, %d, and %d is %d\n", A[0], A[1], A[5], sum);
    
    // Modifying the value of the fifth element of array A.
    A[4] = 100;
    
    // Printing the elements of array A.
    for(int i = 0; i < 6; i++) {
        printf("%d\n", A[i]);
    }

    return 0;
}
