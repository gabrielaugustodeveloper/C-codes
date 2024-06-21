#include <stdio.h>

int main() {
    FILE *file;           // Declare a pointer for the file
    char input[100];      // Declare a character array to store user input
    int ch;               // Declare a variable to store characters read from the file

    // Open the file "arq.txt" for writing ("w")
    file = fopen("arq.txt", "w");
    if (file == NULL) {
        // If an error occurs while opening the file, print an error message and return 1
        perror("Error opening file for writing");
        return 1;
    }
    
    // Infinite loop to read user input
    while (1) {
        printf("Write what you want, if you get bored, type 0:\n");
        fgets(input, sizeof(input), stdin); // Read user input and store it in 'input'

        // Check if the user entered '0' followed by a newline to end the loop
        if (input[0] == '0' && input[1] == '\n') {
            break;
        }

        // Write the user input to the file
        fputs(input, file);
    }

    // Close the file after writing
    fclose(file);

    // Open the file "arq.txt" for reading ("r")
    file = fopen("arq.txt", "r");
    if (file == NULL) {
        // If an error occurs while opening the file, print an error message and return 1
        perror("Error opening file for reading");
        return 1;
    }

    // Loop to read the file character by character until the end of the file (EOF)
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch); // Print each character read to the screen
    }
    
    // Close the file after reading
    fclose(file);

    return 0;
}
