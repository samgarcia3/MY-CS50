from cs50 import get_int
from math import floor


# Prompt user for positive int
def main():
    while True:
        card_number = get_int("Card Number: ")
        if card_number > 0:
            break
        return card_number
        
    # Check the legnth of CC number
    i = int(card_number * 1)
    counter = 0
    
    while i > 0:
        counter += 1
        i //= 10

    sum = 0
    num_digits = len(card_number)
    oddeven = num_digits & 1
    
    for count in range(0, num_digits):
        digit = int(card_number[count])
        
        if not ((count & 1) ^ oddeven):
            digit = digit * 2
        if digit > 9:
            digit=digit - 9
            
        sum = sum + digit
        
    return ( (sum % 10) == 0)
    
    
    
main()
