from cs50 import get_float

def main():
    while True:
        n = get_float("Change Owed: ")
        if n > 0:
            break
        return n
        
    total = round(n * 100)
    counter = 0
    
    while total >= 25:
        counter += 1
        total -= 25
    while total >= 10:
        counter += 1
        total -= 10
    while total >= 5:
        counter += 1
        total -= 5
    while total >= 1:
        counter += 1
        total -= 1
        
    print(counter)
    counter += 1
    

main()