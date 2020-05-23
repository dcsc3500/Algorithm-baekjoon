function solution(record) {
    let answer = [];
    let map = new Map();
   
    for(let element in record){
        
        let spliter = record[element].split(' ');
        if(spliter[0] == 'Leaver') continue;
        map.set(spliter[1],spliter[2]);
    }

    for(let element in record){
        let spliter = record[element].split(" ");
        
        let order = spliter[0];
        let id = map.get(spliter[1]);
        let s;
        if(order === "Enter")
            s = id+ "님이 들어왔습니다."
        
        else if(order === "Leave")
            s = id+"님이 나갔습니다."

        else continue;
        
        answer.push(s);

    }

    return answer;
}

(function solve(){
    let record = ["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"];
    
    console.log(solution(record));

})();