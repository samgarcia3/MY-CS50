#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
// command line arguments parameters
{
    //check command line argument only consists of 26 strings
    if (argc != 2)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    //Check command line arguments contains only decimal digits
    for (int n = 0; n < strlen(argv[1]); n++)
    {
        if (isdigit(argv[1][n]))
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else
        {
            printf("Success!\n");
        }
    }
}