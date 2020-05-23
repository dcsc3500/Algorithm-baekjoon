function solution(N, stages) {
    let answer = [];

    let clear = new Array(N+1).fill(0);

    stages.map(stage => {
        clear[stage-1]++;
    });


    let sums = new Array(N+1).fill(0);
    let sum = clear[clear.length-1];
    for(let i = clear.length-2;i>=0; i--){
        sum+=clear[i];
        sums[i] = sum;
    }

    let fail = [];

    for(let i =0;i<sums.length-1;i++){
        let percent;
        if(sums[i] === 0) percent = 0;
        else{
            percent = clear[i]/sums[i]
        }

        fail.push( {percent : percent, stage : i+1} );
    }

    fail.sort(function (a,b){
        if(b.percent == a.percent){
            return a.stage-b.stage
        }
        return b.percent-a.percent;
    })

    fail.map(item => {
        answer.push(item.stage)
    })

    

    

    console.log(answer)


    return answer;
}

(function solve(){

    let N = 5;
    let stages = [2, 1, 2, 6, 2, 4, 3, 3];
    

    solution(N,stages);


})();