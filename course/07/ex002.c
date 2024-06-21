#include <stdio.h>

int main() {
    
    char file_name[100];    // Variable to store the file name entered by the user
    FILE *file;             // File pointer for file operations
    int line_count = 0;     // Counter to count the number of lines in the file
    char character;         // Variable to store each character read from the file

    // Prompt the user to enter the name of the file
    printf("Enter the name of the file: ");
    scanf("%s", file_name); // Read the file name from the user input

    // Open the file for reading ("r" mode)
    file = fopen(file_name, "r");

    // Check if file opening was successful
    if (file == NULL) {
        perror("Error on opening the file"); // Print error message if file cannot be opened
        return 1;  // Exit the program with an error code
    }

    // Count the number of lines in the file
    while ((character = fgetc(file)) != EOF) {
        if (character == '\n') {   // If a newline character is encountered
            line_count++;          // Increment the line count
        }
    }

    // Close the file after reading is complete
    fclose(file);

    // Print the number of lines in the file
    printf("The file %s has %d lines.\n", file_name, line_count);

    return 0;  // Exit the program successfully
}



