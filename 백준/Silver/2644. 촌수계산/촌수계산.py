import sys
from collections import deque

input = sys.stdin.readline

N = int(input())
A, B= map(lambda x : int(x), input().split())
T = int(input())

graph = [[] for _ in range(N + 1)]

for _ in range(T):
    x, y = map(lambda x : int(x), input().split())
    graph[x].append(y)
    graph[y].append(x)

visited = [False for _ in range(N + 1)]

answer = [-1]
def bfs (y, goal, answer):
    que = deque([])

    que.append([y, 0])

    while(que):
        cur, cost = que.popleft()
        if(goal == cur):
            answer[0] = cost
            break
        if(visited[cur]): continue
        visited[cur] = True

        for next in graph[cur]:
            if(visited[next]): continue
            que.append([next, cost + 1])

bfs(A, B, answer)

print(answer[0])