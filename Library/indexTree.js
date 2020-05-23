let tree;

let offset;
function query(left,right){
    let l = left + offset;
    let r = right + offset;

    let ret = -1;
    while(l<=r){
        
        if(l%2 === 1){
            ret = Math.max(ret,tree[l]);
            l += 1;
        }
        
        if(r%2 === 0){
            ret = Math.max(ret,tree[r]);
            r -= 1;
        }
        l=parseInt(l/2);
        r=parseInt(r/2);
    }
    return ret;

}

function solution(stones, k) {
    var answer = 0;
    
    two = parseInt(Math.log2(stones.length)) +1;
    offset = 1;
    for(let i =0;i<two;i++){
        offset*= 2;
    }
    tree = new Array(stones.length*4).fill(0);

    for(let i = 0;i<stones.length;i++){
        tree[offset+i] = stones[i];
    }

    for(let i =offset-1;i>0;i--){
        tree[i] = Math.max(tree[i*2], tree[i*2 + 1]);
    }
    console.log(tree)

    console.log(query(4,7));

    


    return answer;
}

(function solve(){
    let stones = [2, 4, 5, 3, 2, 1, 4, 2, 5, 1];
    console.log(solution(stones,3));

})();