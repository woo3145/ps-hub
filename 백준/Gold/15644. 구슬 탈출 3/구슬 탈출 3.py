import sys
from  collections import deque

# sys.stdin = open("input.txt", "r")

n, m = map(int, sys.stdin.readline().split())
board = [list(sys.stdin.readline().strip()) for _ in range(n)]

init_blue = (0, 0)
init_red = (0, 0)

for i in range(n):
    for j in range(m):
        if board[i][j] == 'B':
            init_blue = (i, j)
        elif board[i][j] == 'R':
            init_red = (i, j)

def right(blue, red):
    isMoved = False
    
    new_blue = blue
    if(new_blue):
        while(board[new_blue[0]][new_blue[1] + 1] != '#'):
            new_blue = (new_blue[0], new_blue[1] + 1)
            isMoved = True
            if board[new_blue[0]][new_blue[1]] == 'O':
                new_blue = (-1, -1)
                break

    new_red = red
    if(new_red):
        while(board[new_red[0]][new_red[1] + 1] != '#'):
            new_red = (new_red[0], new_red[1] + 1)
            isMoved = True
            if board[new_red[0]][new_red[1]] == 'O':
                new_red = (-1, -1)
                break
    
    if new_blue == new_red and new_blue != (-1, -1):
        if blue[1] < red[1]:
            new_blue = (new_blue[0], new_blue[1] - 1)
        else:
            new_red = (new_red[0], new_red[1] - 1)

    return (isMoved, new_blue, new_red)

def left(blue, red):
    isMoved = False
    
    new_blue = blue
    if(new_blue):
        while(board[new_blue[0]][new_blue[1] - 1] != '#'):
            new_blue = (new_blue[0], new_blue[1] - 1)
            isMoved = True
            if board[new_blue[0]][new_blue[1]] == 'O':
                new_blue = (-1, -1)
                break

    new_red = red
    if(new_red):
        while(board[new_red[0]][new_red[1] - 1] != '#'):
            new_red = (new_red[0], new_red[1] - 1)
            isMoved = True
            if board[new_red[0]][new_red[1]] == 'O':
                new_red = (-1, -1)
                break
    
    if new_blue == new_red and new_blue != (-1, -1):
        if blue[1] < red[1]:
            new_red = (new_red[0], new_red[1] + 1)
        else:
            new_blue = (new_blue[0], new_blue[1] + 1)

    return (isMoved, new_blue, new_red)

def up(blue, red):
    isMoved = False
    
    new_blue = blue
    if(new_blue):
        while(board[new_blue[0] - 1][new_blue[1]] != '#'):
            new_blue = (new_blue[0] - 1, new_blue[1])
            isMoved = True
            if board[new_blue[0]][new_blue[1]] == 'O':
                new_blue = (-1, -1)
                break

    new_red = red
    if(new_red):
        while(board[new_red[0] - 1][new_red[1]] != '#'):
            new_red = (new_red[0] - 1, new_red[1])
            isMoved = True
            if board[new_red[0]][new_red[1]] == 'O':
                new_red = (-1, -1)
                break
    
    if new_blue == new_red and new_blue != (-1, -1):
        if blue[0] < red[0]:
            new_red = (new_red[0] + 1, new_red[1])
        else:
            new_blue = (new_blue[0] + 1, new_blue[1])

    return (isMoved, new_blue, new_red)

def down(blue, red):
    isMoved = False
    
    new_blue = blue
    if(new_blue):
        while(board[new_blue[0] + 1][new_blue[1]] != '#'):
            new_blue = (new_blue[0] + 1, new_blue[1])
            isMoved = True
            if board[new_blue[0]][new_blue[1]] == 'O':
                new_blue = (-1, -1)
                break

    new_red = red
    if(new_red):
        while(board[new_red[0] + 1][new_red[1]] != '#'):
            new_red = (new_red[0] + 1, new_red[1])
            isMoved = True
            if board[new_red[0]][new_red[1]] == 'O':
                new_red = (-1, -1)
                break
    
    if new_blue == new_red and new_blue != (-1, -1):
        if blue[0] < red[0]:
            new_blue = (new_blue[0] - 1, new_blue[1])
        else:
            new_red = (new_red[0] - 1, new_red[1])

    return (isMoved, new_blue, new_red)


queue = deque([])

queue.append((init_blue, init_red, '', 0))

isAnswer = False
while queue:
    b, r, st, cnt = queue.popleft()
    if b == (-1, -1):
        continue
    if r == (-1, -1):
        print(len(st))
        print(st)
        isAnswer = True
        break
    
    if cnt < 10: 
        result_1 = left(b, r)
        if result_1[0]:
            queue.append((result_1[1], result_1[2], st + 'L', cnt + 1))
        result_2 = right(b, r)
        if result_2[0]:
            queue.append((result_2[1], result_2[2], st + 'R', cnt + 1))
        result_3 = up(b, r)
        if result_3[0]:
            queue.append((result_3[1], result_3[2], st + 'U', cnt + 1))
        result_4 = down(b, r)
        if result_4[0]:
            queue.append((result_4[1], result_4[2], st + 'D', cnt + 1))

if not isAnswer:
    print(-1)