import sys
from collections import deque
input = sys.stdin.readline

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

def _input():
    N, M = map(int, input().split())
    board = []
    for _ in range(M):
        board.append(list(map(int, input().split())))
    return N, M, board

def bfs(board):
    que = deque([])
    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] == 1:
                que.append([i, j])

    while(que):
        curY, curX = que.popleft()

        for i in range(4):
            ny = curY + dy[i]
            nx = curX + dx[i]
            if ny < 0 or len(board) <= ny or nx < 0 or len(board[0]) <= nx: continue
            if board[ny][nx] != 0: continue

            que.append([ny, nx])
            board[ny][nx] = board[curY][curX] + 1


def solve():
    N, M, board = _input()
    
    bfs(board)
    answer = 0
    for i in range(M):
        for j in range(N):
            if(board[i][j] == 0):
                return -1
            answer = max(answer, board[i][j] - 1)

    return answer

print(solve())