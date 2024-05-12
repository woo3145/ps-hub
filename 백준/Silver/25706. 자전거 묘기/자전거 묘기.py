import sys

# sys.stdin = open("input.txt", "r")

n = int(sys.stdin.readline().strip())
arr = list(map(int, sys.stdin.readline().split(" ")))

dp = [0] * n
dp[-1] = 1

for i in range(n - 2, -1, -1):
    if n <= arr[i] + i + 1:
        dp[i] = 1
        continue
    dp[i] = dp[arr[i] + i + 1] + 1 

print(" ".join(map(str, dp)))