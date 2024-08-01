#include <stdio.h>
#include <string.h>

// Define the Student struct to store student information
struct Student {
    char name[50];      // Student's name
    int registration;   // Student's registration number
    char course[30];    // Student's course
};

int main() {
    struct Student students[5];  // Declare an array to store 5 Student structs

    // Read the information of 5 students from the user
    for (int i = 0; i < 5; i++) {
        printf("Enter information for student %d:\n", i + 1);

        // Read the student's name
        printf("Name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';  // Remove the trailing newline

        // Read the student's registration number
        printf("Registration: ");
        scanf("%d", &students[i].registration);
        getchar();  // Consume the newline character left by scanf

        // Read the student's course
        printf("Course: ");
        fgets(students[i].course, sizeof(students[i].course), stdin);
        students[i].course[strcspn(students[i].course, "\n")] = '\0';  // Remove the trailing newline
    }

    // Print the information of all students
    printf("\nStudent Information:\n");
    for (int i = 0; i < 5; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Registration: %d\n", students[i].registration);
        printf("Course: %s\n\n", students[i].course);
    }

    return 0;
}
