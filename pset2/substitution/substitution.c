
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
// check
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        exit(1);
    }
// is the key 26 char
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        exit(1);
    }

    else
    {
        int len = strlen(argv[1]);
        for (int n = 0; n < len; n++)
        {
            if (!isalpha(argv[1][n]))
            {
                printf("Key must only contain alphabetic characters.\n");
                exit(1);
            }
        }
        // check for dulplicates
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; j++)
            {
                if (i == j)
                {
                    continue;
                }
                else if (argv[1][i] == argv[1][j])
                {
                    printf("Key should not contain repeated characters.\n");
                    exit(1);
                }
            }

        }

    }

// get key
    string key = argv[1];

// get text
    string text = get_string("plaintext: ");

// encipher
    string conv_text = text;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // keep non alphabets intact
        if (!isalpha(text[i]))
        {
            conv_text[i] = text[i];
        }

        // if uppercase
        else if (isupper(text[i]))
        {
            int index = (int) text[i] - 65;
            conv_text[i] = toupper(key[index]);

        }

        // if lowercase
        else if (islower(text[i]))
        {
            int index = (int) text[i] - 97;
            conv_text[i] = tolower(key[index]);

        }

    }

// print
    printf("ciphertext: %s\n", conv_text);
}

