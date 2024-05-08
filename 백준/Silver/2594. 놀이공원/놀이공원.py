import sys

def solve():
    n = int(sys.stdin.readline().strip())
    timeline = [False] * (60 * 24 + 1)
    for _ in range(n):
        a, b = map(int, sys.stdin.readline().split())
        _a = (a // 100) * 60 + (a % 100)
        _b = (b // 100) * 60 + (b % 100)

        for i in range(_a - 10, _b + 10):
            timeline[i] = True

    answer = 0
    time = 0
    for i in range(60 * 10, 60 * 22):
        if not timeline[i]:
            time += 1
            answer = max(answer, time)
        else:
            time = 0
    
    print(answer)
    
if __name__ == "__main__":
    # sys.stdin = open("input.txt", "r")
    solve()
