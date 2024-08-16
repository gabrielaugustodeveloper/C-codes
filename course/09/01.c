#include <stdio.h>

//endless recursion

int counter = 1;

int main() {

    printf("Something...%d\n", counter);

    counter = counter + 1;

    main();


    return 0;
}