from cs50 import get_int

def main():
    i = get_positive_int()
    height(i)

# Prompt user for positive int
def get_positive_int():
    while True:
        n = get_int("Height: ")
        if n > 0 and n <= 8:
            break
    return n

def height(n):
    d = n - 1
    for i in range(n):
        for d in range(n - i - 1):
            print(" ", end="")
        for j in range(i + 1):
            print("#", end="")
        print()

main()
