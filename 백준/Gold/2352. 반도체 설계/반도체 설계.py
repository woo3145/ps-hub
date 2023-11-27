import bisect
import sys

input = sys.stdin.readline

N = int(input())

arr = list(map(lambda x : int(x), input().split()))

lis = [arr[0]]

for i in range(1, N):
    if(lis[-1] < arr[i]):
        lis.append(arr[i])
    else:
        idx = bisect.bisect_left(lis, arr[i])
        lis[idx] = arr[i]

print(len(lis))