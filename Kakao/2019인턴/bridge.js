let indexTree = [];
let offset;

function findOffset(num){
    let cnt = 1;
    
    while(num != 1){
        //console.log(num)
        num = num/2;
        num = Math.floor(num)
        cnt++;
    }

    let ret = 1;
    for(let i = 0;i<cnt;i++){
        ret = ret * 2;
    }
    return (ret);
    
    
}

function segmentInit(stones){
    //console.log(stones)
    indexTree[0] = 0;
    offset = findOffset(stones.length-1);
    //console.log(offset)
    for(let i =0;i<stones.length;i++){
        indexTree[i+offset] = stones[i];
        //console.log(indexTree[i+offset+1]);
    }
    
    let lastIndex = (offset)*2;
    for(let i = stones.length+offset;i<=lastIndex;i++){
        indexTree[i] = 0;
    }
    for(let i = offset-1;i>0;i--){
        indexTree[i] = Math.max(indexTree[i*2],indexTree[(i*2)+1]);
    }
    
    //console.log(indexTree);

}

function query(left,right){
    let l = left + offset;
    let r = right + offset;
    //console.log(l,r)
    let rval = -1;
        while (l <= r) {
            if (l % 2 === 0){ 
                l /= 2;
                l = Math.floor(l)
            }
            else {
                rval = Math.max(rval, indexTree[l]);
                l = (l / 2) + 1;
                l = Math.floor(l)
            }
            if (r % 2 === 1) {
                r /= 2;
                r = Math.floor(r);
            }
            else {
                rval = Math.max(rval, indexTree[r]);
                r = (r / 2) - 1;
                r = Math.floor(r);
            }
        }
        //console.log(rval)
        return rval;
        
}

function solution(stones, k) {
    if( stones.length == 1)
    return stones[0];
    segmentInit(stones)
    let mini =300000000;
    for(let i =0;i<stones.length-k+1;i++){
        mini = Math.min(mini,query(i,i+k-1));
        //console.log(mini)
    }
    
    return mini;
}


(function solve(){
    let k = 2;
    let stones = [2]	;
    
    console.log(solution(stones,k));

})();