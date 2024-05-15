import sys

# sys.stdin = open("input.txt", "r")

d = []
w = []
n = int(sys.stdin.readline().strip())
for i in range(6):
    x, y = map(int, sys.stdin.readline().split())
    d.append(x)
    w.append(y)

big = []
small = []
for i in range(6):
    if d.count(d[i]) == 1:
        big.append(w[i])
        temp = (i + 3) % 6
        small.append(w[temp])

print((big[0] * big[1] - small[0] * small[1]) * n)