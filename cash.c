#include <stdio.h>
#include <cs50.h>
#include <math.h>

float get_input(void);

int main(void)
{
    int coins = 0;
    int quarters = 25;
    int dimes = 10;
    int nickels = 5;
    int pennies = 1;
    int cents = round(get_input() * 100);

    while (cents != 0)
    {
        //it will check if each coin is less than equal to cents then subtract it from the cents and  then increament the coin output  
        if(cents >= quarters){
            cents = cents - quarters;
            coins ++;
        }
        else if(cents >=  dimes){
            cents = cents - dimes;
            coins ++;
        }
        else if(cents >= nickels){
            cents = cents - nickels;
            coins++;
        }
        else if(cents >= pennies){
            cents = cents - pennies;
            coins++;
        }
    }
    printf("%i\n", coins);

}

// function that checks if user input is not correct
float get_input(void)
{
    float n;
    do
    {
        n = get_float("Change owned: ");
    }
    while (n <= 0);
    return n;
}