import bisect

x = int(input())
arr = list(map(int, input().split()))

dp = [arr[0]]

record = []
record.append(0)

for i in range(1, x):
    if arr[i] > dp[-1] :
        dp.append(arr[i])
        record.append(len(dp) - 1)
    else:
        idx = bisect.bisect_left(dp, arr[i])
        dp[idx] = arr[i]
        record.append(idx)

curIdx = len(arr) - 1
cur = len(dp) - 1

answer = []

while 0 <= curIdx:
    if(cur == record[curIdx]):
        cur -= 1
        answer.append(arr[curIdx])
    
    curIdx -= 1
    

answer.reverse()

print(len(dp))
print(*answer)