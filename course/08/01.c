#include <stdio.h>
#include <string.h>
//Struct

struct st_student {
    char registration[11]; // 11 bytes
    char name[100];
    int age;
    char course[50];
    float grade;
};




int main(){
    struct st_student student01;

    printf("Enter the registration of the student: ");
    fgets(student01.registration, 11, stdin);
    // Remove newline character if present
    student01.registration[strcspn(student01.registration, "\n")] = 0;


    printf("Enter the name of the student: ");
    fgets(student01.name, 100, stdin);   
       // Remove newline character if present
    student01.name[strcspn(student01.name, "\n")] = 0;

    printf("Enter the age of the student: ");
    scanf("%d", &student01.age);
    getchar();

    printf("Enter the course of the student: ");
    fgets(student01.course, 50, stdin);
    // Remove newline character if present
    student01.course[strcspn(student01.course, "\n")] = 0;

    printf("Enter the grade of the student: ");
    scanf("%f.2", &student01.grade);
    getchar();

    printf("========================Data of the Student========================\n");
    printf("Registration: %s\n", student01.registration);
    printf("Name: %s\n", student01.name);
    printf("Age: %d\n", student01.age);
    printf("Course: %s\n", student01.course);
    printf("Grade: %.2f\n", student01.grade);






    return 0;
}