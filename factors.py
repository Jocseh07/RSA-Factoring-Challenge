#!/usr/bin/python3
import sys


def main():
    if len(sys.argv) != 2:
        return
    f = open(sys.argv[1], "r")
    f = f.readlines()
    for num in f:
        num = int(num)
        factors(num)
    
def factors(num):
    for a in range(2, int(num / 2) + 1):
        if (num % a == 0):
            print("{}={}*{}".format(int(num), int(num / a), int(a)))
            return



if __name__ == "__main__":
    main()

