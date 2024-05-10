import sys
from collections import defaultdict, deque

def solve():
    times = defaultdict(int)
    indegree = defaultdict(int)
    graph = defaultdict(list)

    for l in sys.stdin:
        if l == '\n':
            break
        line= l.split()
        a = line[0]
        times[a] = int(line[1])
        if 2 < len(line):
            b = line[2]
            for char in list(b):
                graph[char].append(a)
                indegree[a] += 1

    queue = deque()
    for key in times.keys():
        if indegree[key] == 0:
            queue.append(key)

    cache = times.copy()
    while len(queue):
        cur = queue.popleft()

        for next in graph[cur]:
            cache[next] = max(cache[next], cache[cur] + times[next])
            indegree[next] -= 1
            if(indegree[next] == 0):
                queue.append(next)

    print(max(cache.values()))

if __name__ == "__main__":
    # sys.stdin = open("input.txt", "r")
    solve()
