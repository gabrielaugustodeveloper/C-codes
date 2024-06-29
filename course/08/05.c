#include <stdio.h>
#include <string.h>

// The Union, separates and uses only the space of the largest variable
union person {
    char name[100]; // 1 char = 1 byte -> 1 * 100 = 100 bytes
    int age;        // 4 bytes
};

int main() {
    
    union person feet; // Declare a variable of type union person

    // Assign a value to the name member of the union
    strcpy(feet.name, "Leo");
    printf("Data of %s\n", feet.name); // Print the name

    // Assign a value to the age member of the union
    feet.age = 23;
    printf("He has %d years\n", feet.age); // Print the age

    // Print the size of the union variable
    printf("The size of the 'feet' variable: %d bytes\n", sizeof(feet));

    return 0;
}
