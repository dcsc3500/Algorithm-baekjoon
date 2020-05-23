let answer = 0;
let visited = [];
let size;
let user_id;
let banned_id;
let map = new Map();

function solution(_user_id, _banned_id) {
    user_id = _user_id;
    banned_id = _banned_id;
    //console.log(banned_id);
    size = banned_id.length;

    matching(0);
    

    

    return answer;
}

function check(banUser, user){

    if(banUser.length !== user.length) return false;

    for(let i =0;i<banUser.length;i++){
        if(banUser[i] === '*')
            continue;
        
        if(banUser[i] !== user[i])
            return false;
    }
    return true;

}

function matching(depth){
    if(depth === size){
        //console.log(visited);
        let key = '';
        for(let i = 0;i<visited.length;i++){
            if(visited[i])
                key+= user_id[i];
        }
        //console.log(key);
        if(!map[key]){
            map[key] = 1;
            answer++;
        }
        
        return;
    }

    let banUser = banned_id[depth];
    //console.log();
    
    for(let i = 0; i<user_id.length;i++){
        if(visited[i]) continue;
        //console.log(depth,banUser,user_id[i]);
        if(check(banUser,user_id[i])){
            
            visited[i] = true;
            matching(depth+1);
            visited[i] = false;
        }
    }

}


(function solve(){
    let user_id = ["frodo", "fradi", "crodo", "abc123", "frodoc"];
    let banned_id = ["*rodo", "*rodo", "******"];
    
    console.log(solution(user_id,banned_id));

})();