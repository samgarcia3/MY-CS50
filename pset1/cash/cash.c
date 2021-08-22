#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
int c = 0;
int changecents;
float n;
    // Prompt user for "Change owed:"
    do
    {
        n = get_float("Change Owed:");
    }
    while (n < 0);

    // Convert dollars into cents.
    n = n * 100;
    n = round (n);
    while (n > 0)
    // Use logical operators to divide variable n and incrament total times n is divided.
    if (n >= 25)
    {
        n = n - 25;
        c++;
    }
    else if (n < 25 && n >= 10)
    {
        n = n - 10;
        c++;
    }
    else if (n < 10 && n >= 5)
    {
        n = n - 5;
        c++;
    }
    else
    {
        n = n - 1;
        c++;
    }
    printf("Coins: %i\n", c);
}