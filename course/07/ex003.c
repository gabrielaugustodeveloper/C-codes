#include <stdio.h>

int main() {
    char file_name[100];    // Variable to store the file name
    char character;         // Variable to store the character to be counted
    FILE *file;             // File pointer
    int count = 0;          // Counter for occurrences of the character

    // Prompt user to enter the name of the text file
    printf("Enter the name of the text file: ");
    scanf("%s", file_name);

    // Open the file for reading
    file = fopen(file_name, "r");

    // Check if there was an error opening the file
    if (file == NULL) {
        perror("Error opening the file");
        return 1;
    }

    // Prompt user to enter the character to be counted
    printf("Enter the character to count: ");
    scanf(" %c", &character);  // Space before %c to consume the \n pending from previous scanf

    // Iterate through the file until the end
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == character) {
            count++;  // Increment the counter if the character is found
        }
    }

    // Close the file after reading
    fclose(file);

    // Display the result to the user
    printf("The character '%c' appears %d times in the file.\n", character, count);

    return 0;
}
