import sys

# sys.stdin = open("input.txt", "r")

N = int(sys.stdin.readline().strip())
arr = []
for i in range(N):
    arr.append(sys.stdin.readline().strip())

answer = []

l = 0
r = len(arr) - 1

count = 0
while l <= r:
    if arr[l] < arr[r]:
        answer.append(arr[l])
        l += 1
    elif arr[l] > arr[r]:
        answer.append(arr[r])
        r -= 1
    else:
        tl = l
        tr = r
        while tl <= tr and arr[tl] == arr[tr]:
            tl += 1
            tr -= 1
        if arr[tl] < arr[tr]:
            answer.append(arr[l])
            l += 1
        else:
            answer.append(arr[r])
            r -= 1
    
    count += 1
    if count % 80 == 0:
        answer.append('\n')
            
print(''.join(answer).strip())
