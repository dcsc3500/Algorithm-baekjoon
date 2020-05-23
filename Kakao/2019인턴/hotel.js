let answer = [];
let map = new Map();

function checkIn(wantRoom){
    let visitedRoom = [];
    while(map.get(wantRoom)){
        visitedRoom.push(wantRoom);
        wantRoom = map.get(wantRoom);
    }
    visitedRoom.push(wantRoom);
    for(let i =0;i<visitedRoom.length;i++){
        map.set(visitedRoom[i], wantRoom+1);
    }
    return wantRoom;

}

function solution(k, room_number) {
    
    

    for(let i =0;i<room_number.length;i++){
        let wantRoom = room_number[i];
        answer[i] = checkIn(wantRoom);
    }


    return answer;
}


(function solve(){
    let k = 10;
    let rooms = [1,3,4,1,3,1];
    
    console.log(solution(k,rooms));

})();