#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])

{   // Command line arguments parameters
    // Check command line argument only consists of 2 strings
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Check command line arguments contains only decimal digits
    for (int n = 0; n < strlen(argv[1]); n++)
    {
        if (isalpha(argv[1][n]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    //convert string into an integer
    int key = atoi(argv[1]);

    // Get user input for "plaintext"
    string text = get_string("plaintext: ");
    // Print ciphertext as a stand alone
    printf("ciphertext: ");
    //print each char following "ciphertext: " until /0
    if (text != 0)
    {
        // Iterate over each character to determine variable type
        for (int i = 0, n = strlen(text); i < n;  i++)
        {
            // If char is uppercase & alpha proceed to use argv[1] key to shift char thorugh ASCII & print
            if (isalpha(text[i]) && isupper(text[i]))
            {
                printf("%c", (text[i] - 'A' + key) % 26 + 'A');
            }
            // Else if char is lowercase & alpha proceed to use argv[1] key to shift char thorugh ASCII & print    
            else if (isalpha(text[i]) && islower(text[i]))
            {
                printf("%c", (text[i] - 'a' + key) % 26 + 'a');
            }
            else
            {
                printf("%c", text[i]);
            }
        }
        printf("\n");
        return 0;
    }
}