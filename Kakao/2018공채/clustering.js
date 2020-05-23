function solution(str1, str2) {
    let answer = 0;
    let temp = "asd+1A2 DD"

    str1 = str1.toLowerCase();
    str2 = str2.toLowerCase();

    let split1 = [];
    let split2 = [];

    let filter1 = [];
    let filter2 = [];
    
    for(let i =0;i<str1.length-1;i++){
        let s = str1.substr(i,2);
        split1.push(s);
    }

    for(let i =0;i<str2.length-1;i++){
        let s = str2.substr(i,2);
        split2.push(s);
    }

    for(let i =0;i<split1.length;i++){
        let s = split1[i];
        //console.log(s[0]);
        if(!('a' <= s[0] && s[0] <= 'z')) continue;
        if(!('a' <= s[1] && s[1] <= 'z')) continue;
        filter1.push(s);
    }

    for(let i =0;i<split2.length;i++){
        let s = split2[i];
        if(!('a' <= s[0] && s[0] <= 'z')) continue;
        if(!('a' <= s[1] && s[1] <= 'z')) continue;
        filter2.push(s);
    }
    
    //console.log(filter1,filter2);
    let map1 = new Map();
    

    for(let i =0;i<filter1.length;i++){
        let s = filter1[i];
        if(map1.has(s)){
            map1.set(s,map1.get(s)+1);
        }
        else{
            map1.set(s,1);
        }
    }
    let za = new Map();
    let mo = new Map();
    

    for(let i =0;i<filter2.length;i++){
        let s = filter2[i];
        //console.log(s)
        if(map1.has(s)){
            let num = map1.get(s);
            if(num === 1){
                map1.delete(s);
            }
            else{
                map1.set(s,num-1);
            }
            
                
            if(za.has(s)){
                za.set(s,za.get(s) +1);
            }
            else{
                za.set(s,1);
            }

            if(mo.has(s)){
                mo.set(s,mo.get(s) +1);
            }
            else{
                mo.set(s,1);
            }
        }
        else{
            if(mo.has(s)){
                mo.set(s,mo.get(s) +1);
            }
            else{
                mo.set(s,1);
            }
        }
        //console.log(map1);
        //console.log(mo);
        //console.log(za);
    }
    let sum1 = 0;
    let sum2 = 0;
    //console.log(mo.values());
    for (let value of map1.values()) {
        sum2 += value;
      }
      for (let value of mo.values()) {
        sum2 += value;
      }
      for (let value of za.values()) {
        sum1 += value;
      }
    //console.log(sum1,sum2);





    //console.log(split1);
answer = parseInt((sum1/sum2) * 65536);
if(isNaN(answer)) return 65536

    return answer;
}


(function solve(){
    let str1,str2;
    str1 = "aa1+aa2";
    str2 = "AAAA12"
   
    
    console.log(solution(str1,str2));

})();