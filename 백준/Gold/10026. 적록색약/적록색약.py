import sys
input = sys.stdin.readline

N = int(input())
board = []
for _ in range(N):
    board.append(list(map(str, input().strip())))

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]
def dfs (y, x, colors, visited):
    stack = []

    stack.append([y, x])

    while(stack):
        curY, curX = stack.pop()
        if(visited[curY][curX]): continue
        visited[curY][curX] = True

        for i in range(4):
            ny = curY + dy[i]
            nx = curX + dx[i]

            if ny < 0 or N <= ny or nx <0 or N <= nx:continue
            if visited[ny][nx]: continue
            if board[ny][nx] not in colors: continue
            stack.append([ny, nx])

visited = [[False for _ in range(N)] for _ in range(N)]
nomal = 0
for i in range(N):
    for j in range(N):
        colors = [board[i][j]]
        if(visited[i][j]): continue
        nomal += 1
        dfs(i, j, colors, visited)

visited = [[False for _ in range(N)] for _ in range(N)]
blind = 0
for i in range(N):
    for j in range(N):
        colors = ["G", "R"] if board[i][j] == "R" or board[i][j] == "G" else ["B"]
        if(visited[i][j]): continue
        blind += 1
        dfs(i, j, colors, visited)

print(nomal, blind)