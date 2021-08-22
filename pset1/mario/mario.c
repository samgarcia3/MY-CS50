#include <cs50.h>
#include <stdio.h>

int get_positive_int(void);

int main(void)
{
    int i = get_positive_int();
}

// Prompt user for positive integer
int get_positive_int(void)
{
    int n;
    do
    {
        n = get_int("%s", "Height: ");
    }
    while (n < 1 || n > 8);
    // Creates # of rows
    for (int i = 0; i < n; i++)
    {
        // Print spaces (n - 1 - i) times
        for (int d = n - 1; d > i; d--)
        {
            printf(" ");
        }
        // Print '#' (i + 1) times
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    return n;
}

