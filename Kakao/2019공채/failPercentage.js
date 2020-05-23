

function solution(N,stages) {
    let clear = [];
    let tryNum = [];
    let temp = [];
    let answer = [];

    for(let i =0;i<=N+1;i++){
        clear[i] = 0;
    }

    for(let i =0;i<stages.length;i++){
        clear[stages[i]]++;
    }

    tryNum[N] = clear[N+1] + clear[N];
    for(let i= N-1;i>=0;i--){
        tryNum[i] = tryNum[i+1] + clear[i]
    }
    
    for(let i =1;i<=N;i++){
        if(tryNum[i] === 0)
            temp.push({rate : 0,id:i});
        else
            temp.push({rate : clear[i]/tryNum[i],id :i});
    }

    temp.sort(function(a,b){
        if(a.rate === b.rate)
            return a.id-b.id;
        return b.rate - a.rate;
    })
   
    //console.log(temp[0].id);

    for(let i =0;i<N;i++){
        answer.push(temp[i].id);
    }
    return answer;

}

(function solve(){
    let N = 5;
    let record = [2, 1, 2, 6, 2, 4, 3, 3];
    
    console.log(solution(N,record));

})();