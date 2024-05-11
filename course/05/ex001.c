#include <stdio.h>

// Function to find the largest value in an array of integers
int find_largest(int array[], int size) {
    // Assume the first element is the largest
    int largest = array[0];
    
    // Iterate through the array to find the largest value
    for (int i = 1; i < size; i++) {
        if (array[i] > largest) {
            largest = array[i];
        }
    }
    
    return largest;
}

int main() {
    int size;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int array[size];
    
    printf("Enter %d integer values:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    
    // Call the function to find the largest value
    int largest = find_largest(array, size);
    
    printf("The largest value is: %d\n", largest);
    
    return 0;
}
