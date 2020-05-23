

function check(left,right){
    let mid = left+right/2;


}

function solution(stones, k) {
    let state = false;
    let left = 0;
    let right = 200000000;
    let mid
    while(left<right){
        mid = Math.floor((left+right)/2);
        console.log(mid)
        let cnt = 0;
        let i;
        for(i =0;i<stones.length;i++){
            if(stones[i] - mid <=0) cnt++;
            else cnt = 0;
            //건너뛰어야하는 징검다리수가 k개 넘는다
            if(cnt>=k) break;
        }
        //끝까지 갔으므로 아직 더 건널수 있다.
        if(i === stones.length){
            left= mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return right
}


(function solve(){
    let k = 3;
    let stones = [2, 4, 5, 3, 2, 1, 4, 2, 5, 1]	;
    
    console.log(solution(stones,k));

})();