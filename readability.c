#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

// global declaration
int words = 1;
int letters = 0;
int sentences = 0;

//function pre declaration
void textStats(string s);
int coleman(int l, int w, int s);

int main (void) {
// declaration in the scope
int grade;
string text;

//get the string input
    do
    {
        text = get_string("Text: ");
    }
    while (strlen(text) < 1);

// executing functions
    textStats(text);
    grade = coleman(letters, words, sentences);

// final print out
    if (grade <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade < 16)
    {
        printf("Grade %i\n", grade);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

//takes the string and change the text stats counting
void textStats(string s)
{
     for (int i = 0, n = strlen(s); i < n; i++)
    {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            letters++;
        }
    }
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == ' ' && s[i+1] != ' ')
            words++;
    }
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == '.' || s[i] == '?' || s[i] == '!')
            sentences++;
    }
}

//colemans formula
int coleman(int l, int w, int s)
{
    float i = (float) l/w * 100;
    float j = (float) s/w * 100;
    float g = 0.0588 * i - 0.296 * j - 15.8;
    return round(g);
}


