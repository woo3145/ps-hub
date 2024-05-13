import sys

# sys.stdin = open("input.txt", "r")

t = int(sys.stdin.readline().strip())

dp = [0] * 100
dp[1] = 1
dp[2] = 2
dp[3] = 4
for i in range(100):
    dp[i] = dp[i - 1] + dp[i - 2] + 1

def getHeight(num):
    for i in range(100):
        if num < dp[i]:
            return i
    return -1

answer = []
for _ in range(t):
    n = int(sys.stdin.readline().strip())
    answer.append(str(getHeight(n)))

print("\n".join(answer))