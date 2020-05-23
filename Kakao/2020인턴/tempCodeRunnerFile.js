let K;
let count;
let temp = [];
let answer = new Array(2);
function check(arr,m){
    for(let i=0;i<arr.length-m;i++){
        let cnt = 0;
        let map = new Map();
        for(let j =i;j<i+m;j++){
            let gem = arr[j];
            if(!map.has(gem)){
                map.set(gem,true);
                count++;
            }
            if(count === cnt){
                temp.push({s : i, e: i+m, len : m});
            }
        }
    }
}

function upperBound(arr, l, h) {  
    h = h+1;   
    let m;     
    while(l<h){         
        
        m = parseInt((l+h)/2);
        //console.log(m)
         
        let state = check(arr,m);
        if(state) l=m+1;         
        else h = m;     
    }     
}

function init(gems){
    let m = new Map();
    let cnt = 0;

    for(let i =0;i<gems.length;i++){
        let gem = gems[i];
        if(!m.has(gem)){
            m.set(gem,true);
            cnt++;
        }
    }
    count = cnt;


}

function solution(gems) {
    K = gems.length;
    init(gems);
    upperBound(gems,0,K*2)
    temp.sort(function(a,b){
        if(a.len === b.len){
            return a.x - b.x;
        }
        return a.len -b.len;
    })

    answer.push(temp[0].s,temp[0].e);

    return answer;
}

(function solve(){
    let gems = ["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"];
    console.log(solution(gems));
})();