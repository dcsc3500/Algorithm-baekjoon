function solution(n, t, m, p) {
    var answer = '';
    

    let num = 0;
    p--;
    let start = m;

    while(true){
        let s = num.toString(n);
        //console.log(s)
        
        for(let i =0;i<s.length;i++){
            let c =s[i].toUpperCase();

            if(start%m ===p)
                answer += c;
            
            if(answer.length === t)
                break;

            start++;
            
        }
        if(answer.length === t)
                break;
        num++;


        
    }

    return answer;
}



(function solve(){

    console.log(solution(2,4,2,1));
})();