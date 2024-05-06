import sys

def sqrt(n):
    l=0
    r=n
    while(l <= r):
        mid = (l + r) // 2
        if(mid ** 2 < n):
            l = mid + 1
        else:
            r = mid - 1
    return l

def solve():
    n = int(sys.stdin.readline().strip())
    print(sqrt(n))

if __name__ == "__main__":
    #sys.stdin = open("input.txt", "r")
    solve()