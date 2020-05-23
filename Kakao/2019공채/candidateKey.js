let visited = []
let n;
let bitSet = [];

function check(relation){
    let map = new Map();
    let temp  = []
    
    for(let i =0;i<visited.length;i++){
        if(visited[i])
            temp.push(i);
    }
   
    for(let i=0;i<relation.length;i++){
        let s = "";
        for(let j =0;j<temp.length;j++){
            s = s+relation[i][temp[j]];
            
        }
        
        if(map.get(s)) return;
        map.set(s,1);
    }
    //console.log(visited);
    let myBit= 0;
    for(let i = 0;i<visited.length;i++){
        if(visited[i]){
            let tempBit = 1 <<i;
            myBit = myBit | tempBit          
        }     
       
    }
        bitSet.push(myBit);
}

function comb(relation, start, n, r) {
    if(r == 0) {
        //console.log("a");
        //console.log(visited);
        check(relation);
        return;
    } 
    //console.log(r);
    for(let i=start; i<n; i++) {
        visited[i] = true;
        comb(relation, i + 1, n, r - 1);
        visited[i] = false;
    }
}

function solution(relation) {
    let answer = 0;
    n = relation[0].length;

    for (let i = 1; i <= n; i++) {
        comb(relation, 0, n, i);
    }
    let check = [];
    //console.log(bitSet)

    for(let i =0;i<bitSet.length;i++){
        
        if(check[i]) continue;
        //console.log(bitSet[i]);
        for(let j =i+1;j<bitSet.length;j++){
            if(check[j]) continue;
            if((bitSet[i]&bitSet[j]) === bitSet[j] || (bitSet[i]&bitSet[j]) === bitSet[i]){
                //console.log(bitSet[i],bitSet[j],bitSet[i]&bitSet[j])
                check[j] = true;
            }
        }
 
        check[i] = true;
        answer++;
    }
    return answer;
}

(function solve(){
    let N = 5;
    let relation = [["100","ryan","music","2"],["200","apeach","math","2"],["300","tube","computer","3"],["400","con","computer","4"],["500","muzi","music","3"],["600","apeach","music","2"]];
    console.log(solution(relation));

})();