#include <stdio.h>

int main() {
    int array[10];
    int count = 0;

    // Reading input array from the user
    printf("Enter 10 integer values:\n");
    for (int i = 0; i < 10; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    // Counting non-zero values in the array
    for (int i = 0; i < 10; i++) {
        if (array[i] != 0) {
            count++;
        }
    }

    // Displaying the count of non-zero values
    printf("The array contains %d non-zero values.\n", count);

    return 0;
}
