import sys

# sys.stdin = open("input.txt", "r")

stars = []
coor = set([])

n = int(sys.stdin.readline().strip())
for i in range(n):
    x, y = map(int, sys.stdin.readline().split())
    stars.append((x, y))
m = int(sys.stdin.readline().strip())
for i in range(m):
    x, y = map(int, sys.stdin.readline().split())
    coor.add((x, y))

cx, cy = stars[0]

for cur in coor:
    x, y = cur

    mx = x - cx
    my = y - cy
    flag = True
    
    for star in stars:
        tx = star[0] + mx
        ty = star[1] + my
        if (tx, ty) not in coor:
            flag = False
            break
    if flag:
        print(mx, my)
        break


