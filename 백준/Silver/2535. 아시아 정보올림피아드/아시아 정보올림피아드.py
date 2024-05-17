import sys
import heapq

# sys.stdin = open("input.txt", "r")

n = int(sys.stdin.readline().strip())

pq = []

for i in range(n):
    a, b, c = map(int, sys.stdin.readline().split())
    heapq.heappush(pq, (-c, a, b))

temp = [0] * (n + 1)
cnt = 0
while pq and cnt < 3:
    c, a, b = heapq.heappop(pq)

    temp[a - 1] += 1
    if 3 <= temp[a - 1]: continue
    cnt += 1
    print(a, b)
    if(cnt == 3): break
