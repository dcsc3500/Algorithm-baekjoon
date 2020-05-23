let K;
let count;
let temp = [];
let answer = new Array(2);
let lastIndex = [];
function check(arr,m){
    //console.log(m)
    let state = false;


    for(let i=0;i<=arr.length-m;i++){
        let cnt = 0;
        let map = new Map();
        for(let j =i;j<i+m;j++){
            
            let gem = arr[j];
            //console.log(gem)
            if(!map.has(gem)){
                map.set(gem,true);
                cnt++;
            }
            if(count === cnt){
                state= true;
                temp.push({s : i, e: i+m, len : m});
                return state;
            }
        }
    }
    return state;
}

function upperBound(arr, l, h) {  
    h = h +1;   
    let m;     
    while(l<h){         
        m = parseInt((l+h)/2);
        //console.log(m)
         
        let state = check(arr,m);
        if(!state) l=m+1;         
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
    upperBound(gems,0,K)

    temp.sort(function(a,b){
        if(a.len === b.len){
            return a.x - b.x;
        }
        return a.len -b.len;
    })
   // console.log(temp)
    answer = new Array(2);
    answer[0] = temp[0].s + 1;
    answer[1] = temp[0].e;

    return answer;
}