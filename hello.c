#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int name = get_int("number: ");
    name = name / 10;
    name = name % 10;
    printf("%i\n", name);
}