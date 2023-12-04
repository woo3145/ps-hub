import sys
input = sys.stdin.readline

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

def _input():
    N, M = map(int, input().split())
    board = []
    for _ in range(N):
        board.append(list(map(int, input().split())))
    return N, M, board

def dfs(y, x, board, visited):
    stack = []
    stack.append([y, x])

    cnt = 0
    while(stack):
        curY, curX = stack.pop()
        if(visited[curY][curX]): continue
        cnt += 1
        visited[curY][curX] = True

        for i in range(4):
            ny = curY + dy[i]
            nx = curX + dx[i]
            if(ny < 0 or len(board) <= ny or nx < 0 or len(board[0]) <= nx): continue
            if(board[ny][nx] == 0 or visited[ny][nx]): continue
            stack.append([ny, nx])
    
    return cnt


def solve():
    N, M, board = _input()
    visited = [[False for _ in range(M)] for _ in range(N)]

    answerCnt = 0
    answerSize = 0
    for i in range(N):
        for j in range(M):
            if(visited[i][j] or board[i][j] == 0): continue
            answerCnt += 1
            answerSize = max(answerSize, dfs(i,j,board,visited))

    print(answerCnt)
    print(answerSize)

solve()