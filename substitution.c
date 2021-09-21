#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    string a = argv[1];
    bool validate = true;
    bool alphabetError = false;
    bool repeatError = false;

    if (argc == 2)
    {

        if (strlen(a) == 26)
             {
                for (int i = 0, n = strlen(a); i < n; i++)
                    {
                        if(isalpha(a[i]) == 0)
                            {
                                validate = false;
                                alphabetError = true;
                            }

                    for(int j = i + 1; j < n; j++)
                        {
                        if(a[i] == a[j])
                            {
                                validate = false;
                                repeatError = true;
                            }
                        }
                }

                if(alphabetError == true)
                {
                    printf("Key must contain only alphabets.\n");
                    return 1;
                }
                else if(repeatError == true)
                {
                    printf("Key must not have repeated alphabets.\n");
                    return 1;
                }

            }
            else
            {
                printf("Key must contain 26 characters.\n");
                return 1;
            }


        if(validate == true)
        {
            string p;
            do
            {
                p = get_string("plainText: ");
            }
            while (strlen(p) < 1);
            printf("ciphertext: ");

            for (int i = 0, n = strlen(p); i < n; i++)
            {
                if(isalpha(p[i]))
                {
                    if(isupper(p[i]))
                    {
                        int c = p[i] - 65;
                        printf("%c", toupper(a[c]));
                    }

                    else if (islower(p[i]))
                    {
                        int e = p[i] - 97;
                        printf("%c", tolower(a[e]));
                    }
                }
                else
                {
                    printf("%c", p[i]);
                }

            }

        }

   }
   else
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }

printf("\n");
return 0;

}

