from collections import deque
import math
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]
def bfs(board, y, x, ty, tx):
    visited = [[False for _ in range(102)] for _ in range(102)]
    que = deque([])
    que.append([y, x, 0])
    result = 0
    while(que):
        curY, curX, cost = que.popleft()
        if(ty == curY and tx == curX):
            result = cost
            break
        for i in range(4):
            ny = curY + dy[i]
            nx = curX + dx[i]
            if(ny < 0 or 101 <= ny or nx < 0 or 101 <= nx): continue
            if(board[ny][nx] == 1 and not visited[ny][nx]):
                que.append([ny, nx, cost + 1])
                visited[ny][nx] = True
    return result
def solution(rectangle, characterX, characterY, itemX, itemY):
    board = [[-1 for _ in range(102)] for _ in range(102)]
    # 사각형 하나씩 돌면서 다 2로 찍기
    for rect in rectangle:
        x1, y1, x2, y2 = rect
        for y in range(y1 * 2, y2 * 2 + 1):
            for x in range(x1 * 2, x2 * 2 + 1):
                if x1 * 2 < x < x2 * 2 and y1 * 2 < y < y2 * 2:
                    # 내부
                    board[y][x] = 0
                elif board[y][x] != 0:
                    # 테두리
                    board[y][x] = 1
                    
    answer = bfs(board, characterY*2, characterX*2, itemY * 2, itemX * 2)
    return math.floor(answer / 2)