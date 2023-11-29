def solution(brown, yellow):
    answer = []
    
    for y in range(1, yellow + 1):
        x = yellow / y
        
        if(x != int(x)): continue
        if(y < x): continue
        
        b = (y+2) * 2 + int(x) * 2
        
        if(b == brown):
            answer = [y+2, int(x) + 2]
            break
    
    return answer
