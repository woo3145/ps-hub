import sys
# sys.stdin = open("input.txt", "r")

n, m = map(int, sys.stdin.readline().split())

max_jump = int((2 * n) ** 0.5)

dp = [[sys.maxsize] * (max_jump + 2) for _ in range(n + 1)]

block = set()
for i in range(m):
    k = int(sys.stdin.readline().strip())
    block.add(k)

dp[1][0] = 0
for i in range(2, n + 1):
    if i in block:
        continue

    for j in range(1, int((2 * i) ** 0.5) + 1):
        dp[i][j] = min(dp[i - j][j - 1], dp[i - j][j], dp[i - j][j + 1]) + 1

answer = min(dp[n])
print(-1 if answer == sys.maxsize else answer)