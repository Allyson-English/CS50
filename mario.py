from cs50 import get_int


def main():

    num = height()

    mario(num)

def height():
    while True:
        n = get_int("Height: ")

        if 9 > n >= 1:
            return n


def mario(n):

    for down in range(1,n+1):
        blank = n - down
        b = " "*blank
        space = "  "
        d = "#"*down
        print(b, end='')
        print(d, end='')
        print(space,end='')
        print(d)



main()
