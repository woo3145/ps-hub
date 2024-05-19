import sys
# sys.stdin = open("input.txt", "r")

n = int(sys.stdin.readline().strip())
k = int(sys.stdin.readline().strip())

board = [[0] * n for _ in range(n)]
answer = (1, 1)

def checkPossible(y, x):
    if y < 0 or n <= y or x < 0 or n <=x:
        return False
    if board[y][x] != 0:
        return False
    return True

def drawBoard(pos, cnt, direction):
    global answer
    # L D R U 순서
    dy = [0, 1, 0, -1]
    dx = [-1, 0, 1, 0]

    ny = pos[0] + dy[direction]
    nx = pos[1] + dx[direction]

    if checkPossible(ny, nx):
        rest = cnt - 1
        if rest == k:
            answer = (ny + 1, nx + 1)
        board[ny][nx] = rest
        return ((ny, nx), rest, direction)
    
    return (pos, cnt, (direction + 1) % 4)

cur = n * n
cy = 0
cx = 0
d = 0
board[cy][cx] = cur

while 1 < cur:
    result = drawBoard((cy, cx), cur, d)
    cy = result[0][0]
    cx = result[0][1]
    cur = result[1]
    d = result[2]

for line in board:
    print(' '.join(map(str, line)))
print(' '.join(map(str, answer)))