#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macro and global variable definition
#define ALPHABET_SIZE 26

// Structure definition
typedef struct
{
    char *encrypted_text;
    char *original_text;
}TextData;

// Function to encrypt the argument
TextData encrypt_text(char *text, char *original, int key) 
{
    // Local variable definition
    TextData data;

    // Loop to change the letters of the argument
    for (int i = 0; text[i] != '\0'; ++i) 
    {
        // New variable to check a condition with cleaner code
        int shifted_value = text[i] + key;

        // Checks if the value was modified before (decrypted)
        if (text[i] != original[i]) 
        {
            // If the character is in the range of lowercase alphabet
            if (text[i] >= 'a' && text[i] <= 'z') 
            {
                // If the result doesn't exceed the alphabet
                if (shifted_value >= 'a' && shifted_value <= 'z') 
                {
                    // Encrypts the text letter by letter
                    text[i] = (text[i] + key - 'a') % ALPHABET_SIZE + 'a';
                }
                // If the result exceeds the alphabet
                else 
                {
                    // Don't modify the character and save it
                    original[i] = text[i];
                }
            }
            // If the character is in the range of uppercase alphabet
            else if (text[i] >= 'A' && text[i] <= 'Z') 
            {
                // If the result doesn't exceed the alphabet
                if (shifted_value >= 'A' && shifted_value <= 'Z') 
                {
                    text[i] = (text[i] + key - 'A') % ALPHABET_SIZE + 'A';
                }
                // If the result exceeds the alphabet
                else 
                {
                    // Don't modify the character and save it
                    original[i] = text[i];
                }
            }
            // For extra assurance, if the character doesn't meet any conditions
            else 
            {
                // Print the problem and exit the program
                printf("Invalid argument\n");
                exit(1);
            }
        }
    }
    // Struct elements initialization
    data.encrypted_text = text;
    data.original_text = original;

    // If there's no problem, return the encrypted value
    return data;
}

// Function for decrypting the encrypted argument
TextData decrypt_text(char *text, char *original, int key) 
{
    // Basically the encryption with inverted key
    return encrypt_text(text, original, -key);
}

// Main function with argument count and vector as input
int main(int argc, char *argv[]) 
{
    // Check if the user typed the correct number of arguments in the terminal
    if (argc != 3) 
    {
        // If it didn't happen, inform the user and exit the program
        printf("Incorrect number of arguments\n");
        return 1;
    }

    // Local variables definition
    TextData text_data;
    text_data.original_text = text_data.encrypted_text = NULL;
    char *encrypted_text = NULL;
    char *decrypted_text = NULL;

    // Transform the argv into numbers
    int key = atoi(argv[2]);

    // Allocate memory
    text_data.encrypted_text = (char *)malloc((strlen(argv[1]) + 1) * sizeof(char));
    text_data.original_text = (char *)malloc((strlen(argv[1]) + 1) * sizeof(char));

    // If memory allocation problems occurred
    if (text_data.original_text == NULL) 
    {
        // Inform the error and return it
        printf("Memory allocation failed\n");
        return 1;
    }

    // Function encrypt_text is called and its value is printed
    text_data = encrypt_text(argv[1], text_data.original_text, key);
    encrypted_text = text_data.encrypted_text;
    printf("encrypted text: %s\n", encrypted_text);

    // Function decrypt_text is called and its value is printed
    text_data = decrypt_text(text_data.encrypted_text, text_data.original_text, key);
    decrypted_text = text_data.encrypted_text;
    printf("decrypted text: %s\n", decrypted_text);

    // Free the allocated memory
    free(text_data.encrypted_text);
    free(text_data.original_text);

    return 0;
}