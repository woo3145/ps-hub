import sys

def solve():
    n = int(sys.stdin.readline().strip())
    answer = 0
    for a in range(n):
        for b in range(a, n):
            c = n - a - b
            if(c < b): break
            if(a + b <= c): continue
            answer += 1

    print(answer)

if __name__ == "__main__":
    # sys.stdin = open("input.txt", "r")
    solve()
