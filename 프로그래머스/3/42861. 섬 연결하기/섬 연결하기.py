import heapq

def dijk(start, graph, visited):
    que = []
    
    heapq.heappush(que, [0, start])
    
    cost = 0
    while(que):
        curCost, cur = heapq.heappop(que)
        if(visited[cur]): continue
        visited[cur] = True
        cost += curCost
        
        for next in graph[cur]:
            if(visited[next[0]]): continue
            heapq.heappush(que, [next[1], next[0]])
    
    return cost
    

def solution(n, costs):
    graph = [[] for _ in range(n)]
    
    for cost in costs:
        x, y, c = cost    
        graph[x].append([y, c])
        graph[y].append([x, c])
    
    visited = [False for _ in range(n )]

    answer = dijk(0, graph, visited)
    
    return answer