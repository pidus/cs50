
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    string input = get_string("Enter passage: ");
    int letters = 0, words = 1, sentences = 0;
    int len = strlen(input);

    // count letters
    for (int i = 0; i < len; i++)
    {
        if isalpha(input[i])
        {
            letters++;
        }
    }

    // count words
    for (int i = 0; i < len; i++)
    {
        if isspace(input[i])
        {
            words++;
        }
    }

    // count sentences
    for (int i = 0; i < len; i++)
    {
        if (input[i] == '.' || input[i] == '?' || input[i] == '!')
        {
            sentences++;
        }
    }

    // The Coleman-Liau index

    float index = 0.0588 * (letters * 100 / (float) words) - (0.296 * (sentences * 100 / (float) words)) - 15.8;
    int grade = (int) round(index);

    // print result
    // printf("%i Letters(s)\n%i Words(s)\n%i Sentences(s)\n", letters, words, sentences);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}