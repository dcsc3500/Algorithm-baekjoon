function solution(records) {
    let answer = [];
    let map = new Map();
    records.map(item =>{
        
        let spliter = item.split(" ");
        let order = spliter[0];
        let id = spliter[1];
        
        if(order === "Enter" || order ==="Change"){
            let name = spliter[2];
            map.set(id,name);
        }
    });


    for(let item of records){
        let spliter = item.split(" ");
        let order = spliter[0];
        let id = spliter[1];

        if(order === "Change")
            continue;
        let name = map.get(id);
        let s = "";
        if(order ==="Enter"){
            s += name + "님이 들어왔습니다."
        }
        else{
            s += name + "님이 나갔습니다."
        }
        answer.push(s);
    }




    

    return answer;
}

(function solve(){
    let records = ["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"];
    console.log(solution(records));
})();