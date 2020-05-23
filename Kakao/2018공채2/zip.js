function solution(msg) {
    let answer = [];
    let map = new Map();
    let index = 1;

    for(let i=0;i<26;i++){
        let c = String.fromCharCode(65+i);
        map.set(c,index);
        index++;
    }
    
    let indexA = "A".charCodeAt(0);

    let s = "";
    let val;
    for(let i =0;i<msg.length;i++){
        let c = msg[i];
        
        s+=c;
        console.log(s)
        if(map.has(s)){
            val = s;
        }
        else{
            //console.log("11")
            i--;
            answer.push(map.get(val))
            map.set(s,index);
            index++;
            s="";
            val ="";
        }
        //console.log(map)
    }
    if(map.has(s)){
        answer.push(map.get(s));
    }




    return answer;
}

(function solve(){
    let msg = "KAKAO";

    console.log(solution(msg));
})();