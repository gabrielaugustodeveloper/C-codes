#include <stdio.h>
#include <ctype.h>

// Function that converts a character to uppercase.
char to_upper(char c) {
    return toupper(c);//The toupper(c) function from the ctype.h library converts c to uppercase if it is a lowercase letter. Otherwise, it returns c unchanged.
}

int main() {
    char input_char;
    
    // Prompt the user for a character.
    printf("Enter a character: ");
    scanf("%c", &input_char);
    
    // Call the function and display the result.
    char upper_char = to_upper(input_char);
    printf("The uppercase character is: %c\n", upper_char);
    
    return 0;
}
