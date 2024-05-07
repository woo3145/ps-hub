import sys
import math

def split_score(str):
    arr = []
    score = ''
    for char in str:
        if char in '+-':
            arr.append(score + char)
            score = ''
        else:
            if(score != ''): 
                arr.append(score)
            score = char
    if(score != ''): arr.append(score)

    return arr

def replace_new_format(score, prev_score):
    if score in ['C+', 'C-', 'C']: return 'B'
    elif score in ['B', 'B-']: 
        if prev_score == '' or prev_score in ['C+', 'C', 'C-']: return 'D'
        else: return 'B'
    elif score in ['A-', 'B+']:
        if prev_score == '' or prev_score in ['B', 'B-', 'C+', 'C', 'C-']: return 'P'
        else: return 'D'
    elif score == 'A':
        if prev_score == '' or prev_score in ['A-', 'B+', 'B', 'B-', 'C+', 'C', 'C-']: return 'E'
        else: return 'P'
    else: return 'E'

def solve():
    n = int(sys.stdin.readline().strip())
    s = sys.stdin.readline().replace("0", "").strip()
    scores = split_score(s)

    answer = ''
    prev_score = ''
    for score in scores:
        answer += replace_new_format(score, prev_score)
        prev_score = score
    
    print(answer)

if __name__ == "__main__":
    # sys.stdin = open("input.txt", "r")
    solve()