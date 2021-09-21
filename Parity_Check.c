#include <stdio.h>
#include <cs50.h>

int main(void)
{
int number = get_int("Enter the Number:");
if (number % 2 == 0){
    printf("Number is Even\n");
}
else {
    printf("number is odd\n");
}
}
