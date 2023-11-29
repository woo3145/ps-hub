def solution(people, limit):
    answer = 0
    
    people.sort()
    left = 0
    right = len(people) - 1
    while(left <= right):
        
        if(limit < people[left] + people[right]):
            right -= 1
            answer += 1
            continue
        elif (left == right):
            answer += 1
            break
        else:
            right -=1
            left += 1
            answer += 1
    return answer