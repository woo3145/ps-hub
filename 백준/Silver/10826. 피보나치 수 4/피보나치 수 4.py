import sys

MAX_SIZE = 10001

def fibo(num):
    dp = [0] * MAX_SIZE
    dp[0] = 0
    dp[1] = 1
    for i in range(2, MAX_SIZE):
        dp[i] = dp[i-1] + dp[i-2]
    return dp[num]

def solve():
    N = int(sys.stdin.readline().split()[0]) 
    print(fibo(N))

if __name__ == "__main__":
    # sys.stdin = open("input.txt", "r")
    solve()