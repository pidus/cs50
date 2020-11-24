#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get user's name
    string name = get_string("what's your name?\n");
    
    // print
    printf("hello, %s.\n", name);
}