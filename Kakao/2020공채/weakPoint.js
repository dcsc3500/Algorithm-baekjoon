let weaks;
let dists;
let q;
let N;

function letCheck(){
    let ans;
    
    let i = 0
    for(ans = 0;ans<dists.length;ans++){
        let canMove = dists[ans] + q[i];
        while(canMove >= q[i]){
            //console.log(ans,i)
            i++;
            if(i>=q.length){
                return ans+1;
            } 
        }

    }  
    return 999999;
}

function makeQ(start){
    for(let i =start;i<weaks.length;i++){
        q.push(weaks[i]);
    }
    for(let i = 0;i<start;i++){
        q.push(weaks[i]+N);
    }
    //console.log(q)
}

function solution(n, weak, dist) {
    N = n;
    weaks = weak;
    dist.sort(function(a, b) { // 내림차순
        return b - a;
    });
    dists = dist;
    let answer =999999;
    for(let i =0;i<weaks.length;i++){
        q= new Array();
        makeQ(i);
        //console.log(q)
        answer = Math.min(answer,letCheck());
    }

    if(answer == 999999) answer = -1;

    return answer;
}

(function solve(){
    let n =12;
    let weak = [0,5,6,11];
    let dist = [1,5,3];
   
    console.log(solution(n,weak,dist));

})();