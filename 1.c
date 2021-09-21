#include <stdio.h>
#include <cs50.h>

long get_input(void);
long first_digit(void);
long second_digit(void);
long length(void);
long checksum(void);

int main(void)
{
    long card_number = get_input();
    long first_digit = first_digit();
    long second_digit = second_digit();
    long length = length();
    long checksum = checksum();
    int result = 0;

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

long get_input(void){
    long n = get_input();
    do
    {
        n = get_long("Enter your card number: ");
    }
    while (n < 0);
    return n;

}

long first_digit(void){
    long n = get_input();
    while(n >= 10)
    {
        n /= 10;
    }
    return n;
}

long second_digit(void){
    long n = get_input();
    while(n >= 100)
    {
        n /= 10;
    }
    int m = n % 10;
    return m;
}

long length(void){
    long n = get_input();
    int m = 0;
    while (n != 0) {
        n /= 10;
        ++m;
    }
    return m;
}

long checksum(void){
    int odd_alternate_numbers = 0;
    int even_alternate_numbers = 0;
    long oddcc = get_input();
    int check;

    while(oddcc != 0){
        int last_digit = oddcc % 10;
        odd_alternate_numbers = odd_alternate_numbers + last_digit;
        oddcc = oddcc / 100;
    }

    long evencc = get_input();
    evencc /= 10;
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



    check = odd_alternate_numbers + even_alternate_numbers;
    check = check % 10;
    return check;
}

