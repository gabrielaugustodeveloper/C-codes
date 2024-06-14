#include <stdio.h>

int main() {
    int array[5];
    int *pointer = array;

    // Initialize the array with input values
    for(int i = 0; i < 5; i++) {
        printf("Enter the value for element %d: ", i + 1);
        scanf("%d", pointer + i);
    }

    // Print the double of each value in the array
    printf("Double of each value entered:\n");
    for(int i = 0; i < 5; i++) {
        printf("%d\n", 2 * (*(pointer + i)));
    }

    return 0;
}



/*      pointer + i
This part uses pointer arithmetic to calculate the address of the i-th element in the array. 
If pointer points to the beginning of the array, pointer + i moves the pointer to the i-th position in the array.

        *(pointer + i)
The dereference operator * is used here to access the value stored at the address pointer + i. 
This effectively gives us the value of the i-th element in the array.

        2 * (*(pointer + i))
This multiplies the value of the i-th element by 2.
The parentheses around *(pointer + i) ensure that the dereferencing happens before the multiplication.














*/