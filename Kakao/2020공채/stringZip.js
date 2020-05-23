function solution(s) {
    let answer = 9999999;
    if(s.length === 1) return 1;

    for(let i =1;i<=s.length/2;i++){
        let makeString = "";
        let tempSub = s.substr(0,i);
        let cnt =1;
        for(let j =i;j<s.length;j += i){
            let cmpSub = s.substr(j,i);
            //console.log(tempSub, cmpSub,j,i)
            if(tempSub === cmpSub) cnt++;
            else {
                makeString = makeString + (cnt === 1 ? tempSub : cnt+tempSub);
                cnt = 1;
                tempSub =cmpSub;
            }
        }
        makeString = makeString + (cnt === 1 ? tempSub : cnt+tempSub);
        //console.log(makeString);
        answer = Math.min(answer,makeString.length);
    }

    return answer;
}

(function solve(){
    let k = 10;
    let s = "a";
    
    console.log(solution(s));

})();