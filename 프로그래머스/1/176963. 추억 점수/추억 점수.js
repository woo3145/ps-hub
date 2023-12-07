function solution(name, yearning, photo) {
    const answer = [];
    const dict = new Map();
    
    name.forEach((n, i) => {
        dict.set(n, yearning[i]);
    })
    
    photo.forEach(p => {
        let sum = 0;
        p.forEach(n => {
            if(dict.get(n)){ 
                sum += dict.get(n);
            }
        })
        answer.push(sum);
    })
    
    return answer;
}