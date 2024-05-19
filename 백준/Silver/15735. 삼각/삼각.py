import sys
# sys.stdin = open("input.txt", "r")

n = int(sys.stdin.readline().strip())

answer = 0

for i in range(1, n + 1):
    answer += i * (i + 1) / 2
for i in range(n - 1, 0, -2):
    answer += i * (i + 1) / 2

print(int(answer))