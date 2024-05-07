import sys

MAX_N = 10 ** 6
up_down_nums = [False] * (MAX_N + 1)
up_down_sum = [0] * (MAX_N + 1)

def check_up_down_num(num):
    if(num < 100): return False
    str_num = str(num)
    is_up = False
    is_up_down_num = True
    prev = int(str_num[0])
    flag = False # True면 감소 시작
    for c in str_num[1:]:
        cur = int(c)
        
        if(prev < cur):
            if flag: return False
            is_up = True
        elif cur < prev:
            if not is_up: return False
            flag = True
        else: return False
            
        prev = cur

    if(flag == False): is_up_down_num = False

    return is_up_down_num

def preprocess():
    # 모든 범위 증감소 구함
    for num in range(100, MAX_N + 1):
        up_down_nums[num] = check_up_down_num(num)

    # 누적합
    for num in range(1, MAX_N + 1):
        up_down_sum[num] = up_down_sum[num-1] + int(up_down_nums[num])
    
def solve():
    t = int(sys.stdin.readline().strip())
    answer = []
    for _ in range(t):
        a, b = list(map(int, sys.stdin.readline().split()))
        count = up_down_sum[b] - up_down_sum[a - 1]
        answer.append(str(count))

    print('\n'.join(answer))

if __name__ == "__main__":
    # sys.stdin = open("input.txt", "r")
    preprocess()
    solve()