import sys
from itertools import combinations

def find_brackets_pair(str):
    pair = []
    stack = []
    for idx in range(len(str)):
        if str[idx] == '(':
            stack.append(idx)
        elif str[idx] == ')':
            pair.append([stack.pop(), idx])
    return pair

def generate_expressions(str, pair):
    result = set()
    for i in range(1, len(pair) + 1):
        for comb in combinations(pair, i):
            temp = list(str)
            for a, b in comb:
                temp[a] = ''
                temp[b] = ''
            result.add(''.join(temp))
    return sorted(result)

def solve():
    s = sys.stdin.readline().strip()
    brackets_pair = find_brackets_pair(s)
    answer = generate_expressions(s, brackets_pair)
    
    for i in answer:
        print(i)

if __name__ == "__main__":
    # sys.stdin = open("input.txt", "r")
    solve()
