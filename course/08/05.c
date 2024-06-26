#include <stdio.h>
#include <string.h>
//The Union, separates and uses only the space of the largest variable

union person {
    char name[100]; //1 char = 1 byte -> 1 *100 = 100 bytes
    int age; //4 bytes
}

int main() {
    
    union person feet;
    strcpy(feet.name, "Leo");
    printf("Data of %s\n", feet.name);

    f


    return 0;
}