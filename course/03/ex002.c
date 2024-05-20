#include <stdio.h>

int num = 0;

int main() {

  //Do first, check after.  
  do{ 
     
    printf("%d\n", num);
    num = num +100;

    } while(num <=100000);    
   
    return 0;
}