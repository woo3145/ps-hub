import sys
input = sys.stdin.readline

def lowerBound(list, val):
    left = 0
    right = len(list) - 1

    while(left < right):
        mid = (left + right) // 2

        if(val <= list[mid]):
            right = mid
        else:
            left = mid + 1
    
    return right

N = int(input())
arr = list(map(lambda x : int(x), input().split()))

lis = []

lis.append(arr[0])

for i in range(1, len(arr)):
    if(lis[-1] < arr[i]):
        lis.append(arr[i])
    else:
        idx = lowerBound(lis, arr[i])
        lis[idx] = arr[i]


print(len(lis))