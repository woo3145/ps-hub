import sys
from math import lcm

# sys.stdin = open("input.txt", "r")

a, b = map(int, sys.stdin.readline().split())

print(lcm(a, b))