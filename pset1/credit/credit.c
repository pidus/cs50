
#include <cs50.h>
#include <math.h>
#include <stdio.h>

long get_input(void);

int main(void)
{
    long card = get_input();

    // get individual digits from right to left
    long l1 = card % 10;
    long l2 = (card / 10) % 10;
    long l3 = (card / 100) % 10;
    long l4 = (card / 1000) % 10;
    long l5 = (card / 10000) % 10;
    long l6 = (card / 100000) % 10;
    long l7 = (card / 1000000) % 10;
    long l8 = (card / 10000000) % 10;
    long l9 = (card / 100000000) % 10;
    long l10 = (card / 1000000000) % 10;
    long l11 = (card / 10000000000) % 10;
    long l12 = (card / 100000000000) % 10;
    long l13 = (card / 1000000000000) % 10;
    long l14 = (card / 10000000000000) % 10;
    long l15 = (card / 100000000000000) % 10;
    long l16 = (card / 1000000000000000) % 10;
    // test
    // printf("%li\n%li\n%li\n%li\n%li\n%li\n%li\n%li\n%li\n%li\n%li\n%li\n%li\n%li\n%li\n%li\n", l1, l2, l3, l4, l5, l6, l7, l8, l9, l10, l11, l12, l13, l14, l15, l16);

    // Luhn’s Algorithm
    long add = ((l2 * 2) / 10 + (l2 * 2) % 10) +
               ((l4 * 2) / 10 + (l4 * 2) % 10) +
               ((l6 * 2) / 10 + (l6 * 2) % 10) +
               ((l8 * 2) / 10 + (l8 * 2) % 10) +
               ((l10 * 2) / 10 + (l10 * 2) % 10) +
               ((l12 * 2) / 10 + (l12 * 2) % 10) +
               ((l14 * 2) / 10 + (l14 * 2) % 10) +
               ((l16 * 2) / 10 + (l16 * 2) % 10);
    // test
    // printf("%li\n", add);

    int add2 = (int)(add + l1 + l3 + l5 + l7 + l9 + l11 + l13 + l15);
    // test
    // printf("%i\n", add2);

    int rem = add2 % 10;
    // test
    // printf("%i\n", rem);

    // check for american express
    if (l16 == 0 && l15 == 3 && (l14 == 4 || l14 == 7) && rem == 0)
    {
        printf("AMEX\n");
    }

    // check for master card
    else if (l16 == 5 && (l15 == 1 || l15 == 2 || l15 == 3 || l15 == 4 || l15 == 5) && rem == 0)
    {
        printf("MASTERCARD\n");
    }

    // check for visa
    else if ((l16 == 4 ||
             (l16 == 0 && l15 == 4) ||
             (l16 == 0 && l15 == 0 && l14 == 4) ||
             (l16 == 0 && l15 == 0 && l14 == 0 && l13 == 4)) && rem == 0)
    {
        printf("VISA\n");
    }

    // nothing
    else
    {
        printf("INVALID\n");
    }
}

// function to get user input:
long get_input(void)
{
    long num;
    do
    {
        num = get_long("Number: ");
    }
    while (num < 0 || num > 9999999999999999);
    return num;
}

