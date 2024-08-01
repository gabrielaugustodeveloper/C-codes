#include <stdio.h>
#include <string.h>

// Define the Person struct
struct Person {
    char name[50];
    int age;
    char address[100];
};

int main() {
    struct Person p;  // Declare a variable of type Person

    // Read the person's name
    printf("Enter name: ");
    fgets(p.name, sizeof(p.name), stdin);

    // Remove the newline character that fgets captures
    p.name[strcspn(p.name, "\n")] = '\0';

    // Read the person's age
    printf("Enter age: ");
    scanf("%d", &p.age);

    // Consume the leftover newline character after scanf
    getchar();

    // Read the person's address
    printf("Enter address: ");
    fgets(p.address, sizeof(p.address), stdin);

    // Remove the newline character that fgets captures
    p.address[strcspn(p.address, "\n")] = '\0';

    // Display the person's information
    printf("\nPerson's Information:\n");
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Address: %s\n", p.address);

    return 0;
}
