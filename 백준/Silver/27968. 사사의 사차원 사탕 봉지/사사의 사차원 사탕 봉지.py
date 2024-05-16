import sys
from bisect import bisect_left

# sys.stdin = open("input.txt", "r")

n, m = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))

for i in range(1, m):
    arr[i] += arr[i - 1]

answer = []
for i in range(n):
    k = int(sys.stdin.readline().strip())
    x = bisect_left(arr, k)
    if x == m:
        answer.append('Go away!')
    else:
        answer.append(str(x + 1))

print('\n'.join(answer))