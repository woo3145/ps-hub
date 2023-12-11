function solution(absolutes, signs) {
    var answer = absolutes.reduce((result, num, i) => {
        if(signs[i]){
            return result += num;
        }else{
            return result -= num;
        }
    }, 0);
    
    return answer;
}