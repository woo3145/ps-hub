def find (arr, x):
    if(arr[x] == x): return x
    arr[x] = find(arr, arr[x])
    return arr[x]

def union (arr, a, b):
    aRoot = find(arr, a)
    bRoot = find(arr, b)
    
    if(aRoot == bRoot): return
    arr[bRoot] = aRoot
    

def solution(n, computers):
    answer = 0
    root = [i for i in range(n)]
    
    for x in range(n):
        for y in range(x + 1, n):
            if(computers[x][y]): union(root, x, y)
    
    for i in range(n):
        if(i == root[i]):
            answer += 1
    return answer