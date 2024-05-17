import sys

# sys.stdin = open("input.txt", "r")
MAX_N = 300

n = int(sys.stdin.readline().strip())
lines = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
q = int(sys.stdin.readline().strip())
queries = [list(map(int, sys.stdin.readline().split())) for _ in range(q)]

# make graph
graph = [[sys.maxsize] * (MAX_N + 1) for _ in range(MAX_N + 1)]

for t in range(n):
    graph[t][t] = 0

for aIdx, a in enumerate(lines):
    for bIdx, b in enumerate(lines):
        if aIdx != bIdx and not (a[1] < b[0] or b[1] < a[0]):
            graph[aIdx][bIdx] = 1

# floyd
for t in range(n):
    for u in range(n):
        for v in range(n):
            graph[u][v] = min(graph[u][v], graph[u][t] + graph[t][v])

# result
for q in queries:
    result = graph[q[0] - 1][q[1] - 1]
    if result == sys.maxsize: print(-1)
    else: print(result)
