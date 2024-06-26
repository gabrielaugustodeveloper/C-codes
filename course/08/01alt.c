#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 5

//Struct
struct st_student {
    char registration[11]; // 11 bytes
    char name[100];
    int age;
    char course[50];
    float grade;
};




int main(){

    struct st_student student[MAX_STUDENTS];

    for (int i = 0; i < MAX_STUDENTS; i++) {
        
    printf("Enter the registration of the student: ");
    fgets(student[i].registration, 11, stdin);
    // Remove newline character if present
    student[i].registration[strcspn(student[i].registration, "\n")] = 0;


    printf("Enter the name of the student: ");
    fgets(student[i].name, 100, stdin);   
       // Remove newline character if present
    student[i].name[strcspn(student[i].name, "\n")] = 0;

    printf("Enter the age of the student: ");
    scanf("%d", &student[i].age);
    getchar();

    printf("Enter the course of the student: ");
    fgets(student[i].course, 50, stdin);
    // Remove newline character if present
    student[i].course[strcspn(student[i].course, "\n")] = 0;

    printf("Enter the grade of the student: ");
    scanf("%f.2", &student[i].grade);
    getchar();
   
    }

    for (int i = 0; i < MAX_STUDENTS; i++) {
    printf("========================Data of the Student %d========================\n", (i+1));
    printf("Registration: %s\n", student[i].registration);
    printf("Name: %s\n", student[i].name);
    printf("Age: %d\n", student[i].age);
    printf("Course: %s\n", student[i].course);
    printf("Grade: %.2f\n", student[i].grade);
    
    }





    return 0;
}