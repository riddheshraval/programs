#include <stdio.h>
#include <cs50.h>
#include <math.h>


int main(void)
{
    int checksum;
    int result = 0;
    long card_number;


    do
    {
        card_number = get_long("Enter your card number: ");
    }
    while (card_number < 0);

    long digit = card_number;
    while(digit >= 10)
    {
        digit = digit / 10;
    }
    long first_digit = digit;

    digit = card_number;
    while(digit >= 100)
    {
        digit = digit / 10;
    }

    int second_digit = digit % 10;

    int length = 0;
    long find_length = card_number;
    while (find_length != 0) {
        find_length /= 10;
        ++length;
    }

    int odd_alternate_numbers = 0;    //checked
    int even_alternate_numbers = 0; //checked

    long oddcc = card_number;
    while(oddcc != 0){
        int last_digit = oddcc % 10;
        odd_alternate_numbers = odd_alternate_numbers + last_digit;
        oddcc = oddcc / 100;
    }

    long evencc = card_number / 10;
    while(evencc != 0){
        int sum = 0;
        int last_digit = evencc % 10;
        int timestwo = last_digit *2;
        if(timestwo/10 < 1)
        {
            even_alternate_numbers = even_alternate_numbers + timestwo;
        }else if (timestwo/10 >= 1)
        {
            sum = sum + (timestwo % 10) + (timestwo / 10);
            even_alternate_numbers += sum;
        }
        evencc = evencc / 100;
    }



    checksum = odd_alternate_numbers + even_alternate_numbers;
    checksum = checksum % 10;
    if(checksum == 0){

        if (length == 15 && first_digit == 3 && (second_digit == 4 || second_digit == 7))
        {
            result = 1;
        }
        else if (length == 16 && first_digit == 5 && (second_digit ==1 || second_digit == 2 || second_digit == 3 || second_digit == 4 || second_digit == 5)){
            result = 2;
        }
        else if (first_digit == 4 && (length == 13 || length == 16)){
            result = 3;
        }
    }
    if (result == 1)
    {
        printf("AMEX\n");
    }
    else if (result == 2)
    {
        printf("MASTERCARD\n");
    }
    else if (result == 3)
    {
        printf("VISA\n");
    }
    else if (result == 0)
    {
        printf("INVALID\n");
    }
}