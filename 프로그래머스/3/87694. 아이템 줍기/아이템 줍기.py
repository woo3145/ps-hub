from collections import deque
import math
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]
_dy= [-1, -1, -1, 0, 0, 0, 1, 1, 1]
_dx= [-1, 0, 1, -1,0, 1, -1, 0, 1]
def bfs(board, y, x, ty, tx):
    visited = [[False for _ in range(102)] for _ in range(102)]
    que = deque([])
    que.append([y, x, 0])
    result = 9999
    while(que):
        curY, curX, cost = que.popleft()
        if(ty == curY and tx == curX):
            result = cost
            break
        if(visited[curY][curX]): continue
        visited[curY][curX] = True
        for i in range(4):
            ny = curY + dy[i]
            nx = curX + dx[i]
            if(ny < 0 or 101 <= ny or nx < 0 or 101 <= nx): continue
            if(board[ny][nx] != 1 or visited[ny][nx]): continue
            que.append([ny, nx, cost + 1])
    return result

def solution(rectangle, characterX, characterY, itemX, itemY):
    board = [[0 for _ in range(102)] for _ in range(102)]
    # 사각형 하나씩 돌면서 다 2로 찍기
    for rect in rectangle:
        x1, y1, x2, y2 = rect
        for y in range(y1 * 2, y2 * 2 + 1):
            for x in range(x1 * 2, x2 * 2 + 1):
                board[y][x] = 2
    # 보드 다 돌면서 주위 8칸에 0이있으면 가장자리라 1로 찍기
    for y in range(102):
        for x in range(102):
            for i in range(9):
                ny = y + _dy[i]
                nx = x + _dx[i]
                if(ny < 0 or 102 <= ny or nx < 0 or 102 <= nx): continue
                if(board[ny][nx] == 0 and board[y][x] == 2):
                    board[y][x] = 1
                    break
    answer = bfs(board, characterY*2, characterX*2, itemY * 2, itemX * 2)
    return math.floor(answer / 2)