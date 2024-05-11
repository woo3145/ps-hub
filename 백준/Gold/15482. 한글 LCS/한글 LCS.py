def getLCS(aStr, bStr):
    aLen = len(aStr)
    bLen = len(bStr)
    dp = [[0] * (bLen + 1) for _ in range(aLen + 1)]
    
    for i in range(aLen):
        for j in range(bLen):
            if aStr[i] == bStr[j]:
                dp[i+1][j+1] = dp[i][j] + 1
            else:
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1])
    
    return dp[aLen][bLen]


def solve():
    a = input()
    b = input()

    print(getLCS(a, b))

if __name__ == "__main__":
    # sys.stdin = open("input.txt", "r")
    solve()
