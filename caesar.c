#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main (int argc, string argv[])
{
    string a = argv[1];
    bool validate = true;

        if(argc == 2){

            for (int i = 0, n = strlen(a); i < n; i++)
            {
                if(isdigit(a[i]) == 0)
                {
                validate = false;
                }
            }

            if(validate == true)
            {

                int k = atoi(a);
                string plaintext;

                do
                {
                    plaintext = get_string("plainText: ");
                }
                while (strlen(plaintext) < 1);
                printf("ciphertext: ");

                for (int i = 0, n = strlen(plaintext); i < n; i++)
                {
                    if(isalpha(plaintext[i]))
                    {
                        if(isupper(plaintext[i]))
                        {
                            printf("%c", (((plaintext[i] - 65) + k) % 26) + 65);
                        }

                        else if (islower(plaintext[i]))
                        {
                           printf("%c", (((plaintext[i] - 97) + k) % 26) + 97);
                        }
                    }
                    else
                    {
                        printf("%c", plaintext[i]);
                    }

                }
            }
            else
            {
            printf("Error!\n");
            return 1;
            }
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    printf("\n");
    return 0;
}

