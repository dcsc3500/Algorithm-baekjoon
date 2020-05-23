let check;
let map = new Map();
let answer = 0;
let banid;
function getId(user_id,depth,N){
    //console.log(depth,N)
    if(depth === N){
        let s = "";
        //console.log("dd")
        for(let i =0;i<user_id.length;i++){
            if(check[i]){
                s+= user_id[i];
            }
            
        }
        console.log(s);
        if(!map.has(s)){
            map.set(s,true);
            answer++;
        }

        return;
    }

    let ban = banid[depth];
    //console.log(ban)
    for(let i =0;i<user_id.length;i++){
        if(check[i]) continue;
        let user = user_id[i];
        if(user.length !== ban.length) continue;
        let j;
        //console.log(user,ban,depth)
        for(j=0;j<ban.length;j++){
            if(ban[j] === '*') continue;
            if(ban[j] === user[j]) continue;
            break;
        }
        if(j === ban.length){
            
            check[i] = true;
            getId(user_id,depth+1,N);
            check[i] = false;
        }
    }
    

}

function solution(user_id, banned_id) {
    check = new Array(user_id.length).fill(false);
    banid= banned_id;

    
    getId(user_id,0,banned_id.length);

    return answer;
}

(function solve(){
    let user_id = ["frodo", "fradi", "crodo", "abc123", "frodoc"];
    let ban_id = ["*rodo", "*rodo", "******"];
    console.log(solution(user_id,ban_id));
})();