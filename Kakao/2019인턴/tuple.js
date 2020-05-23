function solution(s) {
    let answer = [];
    s =s.substr(1,s.length -2);
    let cs = s.split(',');
    let spliter = [];
    let arr = []
    for(let i =0;i<cs.length;i++){
        
        if(cs[i].charAt(0) === '{'){
            cs[i] = cs[i].substr(1);
        }
        if(cs[i].charAt(cs[i].length-1) === '}'){
            arr.push(cs[i].substr(0,cs[i].length-1));
            spliter.push(arr);
            arr = [];
        }
        
        else{
            arr.push(cs[i]);
        }
    }

    spliter.sort(function(a,b){
        return a.length-b.length;
    });

    
    let nextMap = new Map;
    for(let i =0;i<spliter.length;i++){
        let map = nextMap;
        for(let j =0;j<spliter[i].length;j++){
            let num = spliter[i][j];
            if(!map[num]){
                answer.push(num*1);
                map[num] = 1;
            }

        }
    }

   



    return answer;
}

(function solve(){
    let s = "{{1,2,3},{2,1},{1,2,4,3},{2}}";
    
    console.log(solution(s));

})();