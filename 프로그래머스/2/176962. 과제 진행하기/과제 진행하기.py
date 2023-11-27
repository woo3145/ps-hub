from collections import deque

def formatPlans (plans):
    for i in range(len(plans)):
        h, m = map(lambda x : int(x), plans[i][1].split(":"))
        plans[i][1] = (h * 60) + m
        plans[i][2] = int(plans[i][2])
        
def simulateQueue (que, restTime, result):
    while(que and restTime):
        item = que.popleft()
        if(item[1] <= restTime):
            result.append(item[0])
            restTime -= item[1]
        else:
            que.appendleft([item[0], item[1] - restTime])
            restTime = 0

def solution(plans):
    formatPlans(plans)
    plans.sort(key = lambda x : x[1])

    queue = deque([])
    answer = []
    curTime = 0

    for i in range(len(plans)):
        startTime = int(plans[i][1])
        restTime = startTime - curTime

        # 다음시작 전까지 queue에 존재하는 task 처리
        simulateQueue(queue, restTime if i != 0 else 0, answer)

        queue.appendleft([plans[i][0], plans[i][2]])
        curTime = startTime

    simulateQueue(queue, 9999999999, answer)
    
    return answer