function go(){

}

function makingTwo(s,start){
    let arr = [];
    arr[0] = 0;
    arr[1] = 0;
    for(let i =start;i<s.length;i++){
        if(s[i] == '(')
            arr[0]++;
        else
            arr[1]++;
        if(arr[0] === arr[1])
            return i+1;
    }

}

function rightString(s){
    let stack = 0;
    for(let i =0;i<s.length;i++){
        if(s[i] == '(') stack++;
        else stack--;
        if(stack<0) return false;
    }
    return true;
}

function make(p){
    if(p.length == 0) return p;
    
    let index = makingTwo(p,0);
    let one = p.substr(0,index);
    let two = p.substr(index);
    let tempS ='';
    let tempTwo;
    if(rightString(one)){
        tempTwo = solution(two);
        return one + tempTwo;
    }
    else{
        let s3 = solution(two);
        tempS += '(';
        tempS += s3;
        tempS += ')';
        let rever1 = one.substr(1,one.length-2);
        let rever2 = "";
		for (let j = 0; j < rever1.length; j++) {
			let a = rever1[j];
			if (a == '(')
				rever2+=")";
			else
				rever2+="(";
		}
        tempS+=rever2;
        return tempS;
    }

}

function solution(p) {
    let answer = '';
    if(p.length == 0) return answer;
    answer = make(p);
    return answer;
}

(function solve(){
    let k = 10;
    let s = "()))((()";
    console.log(solution(s));

})();