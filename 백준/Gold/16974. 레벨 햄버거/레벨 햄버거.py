import sys

# sys.stdin = open("input.txt", "r")

n, x = map(int, sys.stdin.readline().split())

bugger = [0] * 51
pat = [0] * 51

bugger[0] = 1
pat[0] = 1

for i in range(1, 51):
    bugger[i] = bugger[i - 1] * 2 + 3
    pat[i] = pat[i - 1] * 2 + 1

def recur(level, rest):
    if(rest == 1):
        return 0
    
    if rest < 1 + bugger[level - 1]:
        return recur(level - 1, rest - 1)
    
    if rest == 1 + bugger[level - 1]:
        return pat[level - 1]
    
    if rest == 2 + bugger[level - 1]:
        return pat[level - 1] + 1
    
    if rest < 2 + bugger[level - 1] * 2:
        return pat[level - 1] + 1 + recur(level - 1, rest - bugger[level - 1] - 2)
    
    return pat[level]

print(recur(n, x))
