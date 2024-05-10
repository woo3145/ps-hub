import sys

def solve():
    h, w = map(int, sys.stdin.readline().split())
    lst = list(map(int, sys.stdin.readline().split()))
    answer = 0
    for i in range(1, w - 1):
        left_max = max(lst[:i])
        right_max = max(lst[i:])
        
        possible_h = min(left_max, right_max)
        if(lst[i] < possible_h):
            answer += possible_h - lst[i]
    
    print(answer)

if __name__ == "__main__":
    # sys.stdin = open("input.txt", "r")
    solve()
