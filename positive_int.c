#include <stdio.h>
#include <cs50.h>

int get_positive_int(void);


int main(void)
{

    int i = get_positive_int();
    printf("%i\n", i);

}
int get_positive_int(void)\n
{
    int n;
    do\n
    {
        n = get_int("Positive integer:");
    }
    while (n < 1);
    return n;
}