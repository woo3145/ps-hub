



function solution(tickets) {
    const result = ["ICN"];
    let answer = [];
    const used = Array.from({length: tickets.length}, () => false)
    
    tickets.sort((a, b) => {
        if(a[0] === b[0]){
            return a[1] > b[1] ? -1 : 1
        }
        return a[0] > b[0] ? -1 : 1
    })
    
    const recur = (cur, cnt) => {
        if(tickets.length < cnt) {
            return
        }
        if(tickets.length + 1 === result.length) {
            answer = [...result]
            return
        }
        
        for(let i = 0; i < tickets.length; ++i){
            [s, e] = tickets[i];
            
            if(used[i]) continue;
            if(cur !== s) continue;
            
            used[i] = true;
            result.push(e)
            recur(e, cnt + 1);
            result.pop()
            used[i] = false
        }
    }  
    answer.push("ICN")
    recur("ICN", 0)
    
    return answer;
}