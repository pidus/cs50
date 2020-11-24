
#include <cs50.h>
#include <math.h>
#include <stdio.h>

float get_input(void);

int main(void)
{
    // ask from user
    float dollars = get_input();

    // list coins
    int quarter = 25, dime = 10, nickel = 5, penny = 1;

    // convert dollar value to cents
    int cents = round(dollars * 100);
    
    // divide by bigger coin, then divide remaindr by smaller coin 
    int q = cents / quarter;
    int qr = cents % quarter;

    int d = qr / dime;
    int dr = qr % dime;

    int n = dr / nickel;
    int nr = dr % nickel;

    int p = nr / penny;
    int pr = nr % penny;

    int total = q + d + n + p;
    printf("%i\n", total);
}

// function to get user input:
float get_input(void)
{
    float num;
    do
    {
        num = get_float("Change owed: ");
    }
    while (num <= 0);
    return num;
}

