import sys
sys.setrecursionlimit(10 ** 8)
# sys.stdin = open("input.txt", "r")

n, m, r = map(int, sys.stdin.readline().split())

graph = [[] for _ in range(n + 1)]

for i in range(m):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

st = []
answer = [-1] * (n + 1)

def dfs(n, d):
    answer[n] = d
    for next in sorted(graph[n], reverse=True):
        if answer[next] == -1: 
            dfs(next, d + 1)

dfs(r, 0)

print('\n'.join(map(str, answer[1:])))