
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{lengtlengt
// check
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        exit(1);
    }

    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            exit(1);
        }
    }

// get key
    int key = atoi(argv[1]);
    printf("key: %i\n", key);

// get text
    string text = get_string("plaintext: ");
    int len = strlen(text);

// encipher
    string conv_text = text;

    for (int i = 0; i < len; i++)
    {
        // keep non alphabets intact
        if (!isalpha(text[i]))
        {
            conv_text[i] = text[i];
        }

        // if uppercase
        else if (isupper(text[i]))
        {
            int ascii = ((int) text[i] + key - 65) % 26;
            ascii += 65;
            // printf("%i\n", ascii);
            conv_text[i] = (char) ascii;
            // printf("%c\n", conv_text[i]);
        }

        // if lowercase
        else if (islower(text[i]))
        {
            int ascii = ((int) text[i] + key - 97) % 26;
            ascii += 97;
            // printf("%i\n", ascii);
            conv_text[i] = (char) ascii;
            // printf("%c\n", conv_text[i]);
        }

    }

// print
    printf("ciphertext: %s\n", conv_text);
}

