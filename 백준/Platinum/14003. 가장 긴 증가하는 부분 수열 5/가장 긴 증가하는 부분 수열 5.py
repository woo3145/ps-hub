import sys

input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

def lowerBound (list, value):
    left = 0
    right = len(list) - 1

    while left < right:
        mid = (left + right) // 2

        if(value <= list[mid]):
            right = mid
        else:
            left = mid + 1
    
    return right


lis = []
lis.append(arr[0])
record = []
record.append(0)
for i in range(1, len(arr)):
    if(lis[-1] < arr[i]):
        lis.append(arr[i])
        record.append(len(lis) - 1)
    else:
        idx = lowerBound(lis, arr[i])
        lis[idx] = arr[i] 
        record.append(idx)

cur = len(lis) - 1
curIdx = len(arr) - 1
answer = []
while(0 <= curIdx):
    if(record[curIdx] == cur):
        answer.append(arr[curIdx])
        cur -= 1
    
    curIdx -= 1
answer.reverse()
print(len(lis))
print(*answer)
