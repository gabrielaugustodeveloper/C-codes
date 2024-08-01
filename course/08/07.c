#include <stdio.h>

// Enum
enum days_of_week {
    monday, // 0
    tuesday, // 1
    wednesday, // 2
    thursday, // 3
    friday, // 4
    saturday, // 5
    sunday // 6
};

int main() {
    enum days_of_week d1, d2; 

    int numbers[5];

    numbers[0] = 1;
    numbers[1] = 3;
    numbers[2] = 5;
    numbers[3] = 7;
    numbers[4] = 9;

    d1 = thursday;  

    d2 = 3;  

    if (d1 == d2) {
        printf("The days are equal\n");  
    } else {
        printf("The days are not equal\n");
    }

    printf("Numbers 0 = %d\n", numbers[0]);
    printf("Numbers 1 = %d\n", numbers[1]);
    printf("Numbers 2 = %d\n", numbers[2]);
    printf("Numbers 3 = %d\n", numbers[3]);
    printf("Numbers 4 = %d\n", numbers[4]);
    printf("Numbers 7 = %d\n", numbers[7]); //just to trying to access an invalid position

    return 0;
}






/*i gotta blow


my mind is out of __control_entrypoint



im feeling __local_stdio_printf_options

~Erick Maik*/
