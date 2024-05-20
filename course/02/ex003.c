#include <stdio.h>

int main() {
    // Declare variables to store bets, total bet, prize, percentages, prizes, and total prizes.
    float bet01, bet02, bet03, totalbet = 0;
    float prize = 0;
    float percentage01, percentage02, percentage03, totalpercentage = 0;
    float prize01 = 0, prize02 = 0, prize03 = 0, totalprizes = 0;

    // Prompt user to input bets and prize, and read inputs.
    printf("Enter the first bet:\n");
    scanf("%f", &bet01);
    printf("Enter the second bet:\n");
    scanf("%f", &bet02);
    printf("Enter the third bet:\n");
    scanf("%f", &bet03); 
    printf("Enter the prize:\n");
    scanf("%f", &prize); 

    // Calculate total bet.
    totalbet = bet01 + bet02 + bet03;
   
    // Display total bet.
    printf("The total of bet is %.2f\n", totalbet);
   
    // Calculate percentages.
    percentage01 = bet01 / totalbet;
    percentage02 = bet02 / totalbet;
    percentage03 = bet03 / totalbet; 
    totalpercentage = percentage01 + percentage02 + percentage03;

    // Display total percentage.
    printf("The total of percentage is %.2f\n", totalpercentage);

    // Calculate prizes.
    prize01 = prize * percentage01;
    prize02 = prize * percentage02;
    prize03 = prize * percentage03; 
    totalprizes = prize01 + prize02 + prize03;
   
    // Display total prizes and individual prizes with their respective percentages.
    printf("The total of prizes is %.2f\n", totalprizes);
    printf("The first prize is %.2f and the percentage is %.2f\n", prize01, percentage01);
    printf("The second prize is %.2f and the percentage is %.2f\n", prize02, percentage02); 
    printf("The third prize is %.2f and the percentage is %.2f\n", prize03, percentage03);
    
    return 0;
}
