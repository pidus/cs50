
#include <cs50.h>
#include <stdio.h>

int get_positive_int(void);

int main(void)
{

    int value = get_positive_int();

    // each row
    for (int i = 0; i < value; i++)
    {
        // each column

        // print space
        for (int j = i; j < value - 1; j++)
        {
            printf(" ");
        }

        for (int k = 0; k < i; k++)
        {
            printf("#");
        }

        printf("#");
        printf("  ");

        // second one:
        for (int l = 0; l < i + 1; l++)
        {
            printf("#");
        }
        printf("\n");
    }

}

// function to get user input:
int get_positive_int(void)
{
    int num;
    do
    {
        num = get_int("Height: ");
    }
    while (num < 1 || num > 8);
    return num;
}

