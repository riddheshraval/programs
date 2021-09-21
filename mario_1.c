#include <stdio.h>
#include <cs50.h>

int get_height(void);

int main(void)
{
    int height = get_height();
    // left align stairs
        // for (int i = 0; i < height; i++)
        // //1 iteration will give one new line
        // {
        //     for (int j = 0; j <= i; j++)
        //     //an iteration will give "#" and later on the same line
        //     {
        //         printf("#");
        //     }
        //     printf("\n");
        // }

    // right align stairs
        for (int i = 0; i < height; i++)
        //1 iteration will give one new line
        {
            for (int j = height - 1; j > i; j--)
        //an iteration will give height - 1 spaces
             {
                 printf(" ");
             }

            for(int z = 0; z <= i; z++){
            // an iteration will give "#" = the parent loop's i
                printf("#");
            }
             printf("\n");
         }

}

// function that checks if user input is not correct
int get_height(void)
{
    int n;
    do
    {
        n = get_int("Enter the height for the stairs: ");
    }
    while (n < 1 || n > 8);
    return n;
}