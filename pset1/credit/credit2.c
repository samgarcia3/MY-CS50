#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{ 
    // Ask for input
    long long cardnumber;
    do
    {
        cardnumber = get_long_long("Number: ");
    }
    while (cardnumber <= 0);
    
    int count = 0;
    long long i = cardnumber;
    
    // First check: Legnth of CC number
    while (i > 0)
    {
        i = i / 10;
        count++;
    }
    
    long long j = cardnumber;
    int sum1 = 0; 
    int remainder1;
    int remainder0;
    
    // Second check: 
    while (j != 0)
    {
        remainder1 = 2 * ((j % 100) / 10);
        remainder0 = remainder1 % 10 + round(remainder1 / 10);
        sum1 = sum1 + remainder0;
        j = j / 100; 
    }
    
    long long k = cardnumber;
    int sum2 = 0; 
    int remainder2;
    long divisor = 10;
    
    // Add the sum to the sum of the digits that weren’t multiplied by 2.
    while (k != 0)
    {
        remainder2 = k % 10;
        sum2 = sum2 + remainder2;
        k = k / 100;
    }
    
    // Divide CC# to get first digit or first two digits
    for (int x = 0; x < count - 2; x++)
    {
        divisor = divisor * 10;
    }
    
    int checksum = sum1 + sum2;
    int f1 = cardnumber / divisor;
    int f2 = cardnumber / (divisor / 10);
    
    // If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
    if (checksum % 10 == 0)
    {
        if ((f2 == 34 || f2 == 37) && count == 15)
        {
            printf("AMEX\n");
        }
        else if (f1 == 4 && (count = 13 || count == 16))
        {
            printf("VISA\n");
        }
        else if ((50 < f2 && f2 < 56) && count == 16)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}