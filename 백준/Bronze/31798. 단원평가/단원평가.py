import sys
import math

def calc(a, b, c):
    if a == 0:
        return c * c - b
    elif b == 0:
        return c * c - a
    else:
        return math.sqrt(a + b)

def solve():
    a, b, c = list(map(int, sys.stdin.readline().split()))
    print(int(calc(a, b, c)))

if __name__ == "__main__":
    # sys.stdin = open("input.txt", "r")
    solve()