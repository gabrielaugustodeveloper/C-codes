#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 3

// Struct to store information of a contact
struct st_contact {
    char name[100]; 
    int dateOfBirth;
    char telephone[20];
    char email[100];
};

// Struct to store a schedule of contacts
struct st_schedule {
    struct st_contact contacts[MAX_CONTACTS];
};

int main() {
    struct st_schedule schedule;

    for (int i = 0; i < MAX_CONTACTS; i++) {
        printf("Enter the name: ");
        fgets(schedule.contacts[i].name, 100, stdin);
        // Remove newline character if present
        schedule.contacts[i].name[strcspn(schedule.contacts[i].name, "\n")] = 0;

        printf("Enter the date of birth (YYYYMMDD): ");
        scanf("%d", &schedule.contacts[i].dateOfBirth);
        getchar(); // Clear the newline character from the input buffer

        printf("Enter the telephone: ");
        fgets(schedule.contacts[i].telephone, 20, stdin);
        // Remove newline character if present
        schedule.contacts[i].telephone[strcspn(schedule.contacts[i].telephone, "\n")] = 0;

        printf("Enter the email: ");
        fgets(schedule.contacts[i].email, 100, stdin);
        // Remove newline character if present
        schedule.contacts[i].email[strcspn(schedule.contacts[i].email, "\n")] = 0;

        printf("\n");
    }

    printf("======================== Contact Book ========================\n");
    for (int i = 0; i < MAX_CONTACTS; i++) {
        printf("======================== Contact %d ========================\n", (i+1));
        printf("Name: %s\n", schedule.contacts[i].name);
        printf("Date of Birth: %d\n", schedule.contacts[i].dateOfBirth);
        printf("Telephone: %s\n", schedule.contacts[i].telephone);
        printf("Email: %s\n", schedule.contacts[i].email);
    }

    return 0;
}