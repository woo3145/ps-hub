import sys

# sys.stdin = open("input.txt", "r")

def calcMax(arr):
    dp = [0] * len(arr)
    dp[0] = arr[0]

    if 1 < len(dp):
        dp[1] = max(arr[0], arr[1])
    
    for i in range(2, len(arr)):
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i])
    
    return dp[-1]


while True:
    a, b = map(int, sys.stdin.readline().split(" "))
    if a == 0 and b == 0: break

    temp = []
    for i in range(a):
        line = list(map(int, sys.stdin.readline().split(" ")))
        temp.append(calcMax(line))
    print(calcMax(temp))
