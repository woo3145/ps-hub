from math import pow, sqrt, floor, ceil

def solution(r1, r2):
    answer = 0
    for x in range(1, r2 + 1):
        _y = ceil(sqrt(pow(r1, 2) - pow(x, 2))) if x < r1 else 0
        y = floor(sqrt(pow(r2, 2) - pow(x, 2)))
        
        answer += y-_y + 1

    return answer * 4