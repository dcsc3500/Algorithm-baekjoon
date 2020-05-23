function solution(n, arr1, arr2) {
    let answer = [];
    for(let i =0;i<arr1.length;i++){
        let t = arr1[i] | arr2[i];
        let s = "";
        while(t != 0){
            //console.log(t);
            if(t%2 == 1){
                s+='#';
            }
            else s+= ' ';
            t/=2;
            t = parseInt(t);
        }
        let ans = '';
        let j = n-1;
        for(j;j>=s.length;j--){
            ans+= ' ';
        }
        for(let j =s.length-1;j>=0;j--){
            
                ans= ans +s[j];
            
            
        }
        answer.push(ans);
    }
    
    return answer;
}

(function solve(){
    let n = 6;
    let arr1 = [46, 33, 33 ,22, 31, 50]
    let arr2 = [27 ,56, 19, 14, 14, 10]
    
    console.log(solution(n,arr1,arr2));

})();