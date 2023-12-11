function solution(s){
    let p = 0; 
    let y = 0;
    s.toLowerCase().split("").forEach(a => {
        if(a==="p"){
            ++p;
        }else if(a === "y"){
            ++y;
        }
    })

    return p === y;
}