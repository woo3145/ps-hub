

def solution(routes):
    answer = 1
    
    routes.sort(key = lambda x : x[1])
    passed = routes[0][1]
    
    print(routes)
    
    for i in range(0, len(routes)):
        if(passed < routes[i][0]):
            passed = routes[i][1]
            answer += 1
    
    return answer
