def solution(s):
    answer = 0
    
    x = s[0]
    
    xCnt = 0
    notXCnt = 0
    
    bit = s[0]
    for i in range(len(s)):
        if xCnt == 0 and notXCnt == 0:
            x = s[i]
            xCnt += 1
            continue
        
        if s[i] == x:
            xCnt += 1
        else:
            notXCnt += 1
        
        if(xCnt == notXCnt):
            answer += 1
            xCnt = 0
            notXCnt = 0
            
    if(xCnt or notXCnt): answer += 1
    
    return answer