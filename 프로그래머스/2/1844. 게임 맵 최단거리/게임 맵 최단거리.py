from collections import deque

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

def bfs (maps, y, x):
    que = deque([])
    que.append([y, x])
    
    while(que):
        curY, curX = que.popleft()
        for i in range(4):
            ny = curY + dy[i]
            nx = curX + dx[i]
            if(ny < 0 or len(maps) <= ny or nx < 0 or len(maps[0]) <= nx): continue
            if(maps[ny][nx] != 1): continue
            maps[ny][nx] = maps[curY][curX] + 1
            que.append([ny,nx])
    return

def solution(maps):
    N = len(maps)
    M = len(maps[0])
    bfs(maps, 0, 0)
    
    answer = maps[N-1][M-1]
    print(maps)
    
    return -1 if answer == 1 else answer