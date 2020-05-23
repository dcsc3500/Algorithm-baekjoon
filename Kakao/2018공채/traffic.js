let startTime = [];
let endTime = [];

function timePlus(et, duration){
    
    endTime.push(et);
    let st = et;
    let durDot = duration.indexOf('.');

    if(durDot != -1){
        let durss = duration.substr(0,durDot);
        let durnn = duration.substr(durDot+1,duration.length-durDot-2);
        st = st - (durss*1000 ) - durnn + 1;
        

    }
    else{
        let durss = duration.substr(0,duration.length-1)
        st = st - (durss*1000) + 1;
        
    }
    startTime.push(st);

}

function timeInit(lines){
    for(let i =0;i<lines.length;i++){
        let line = lines[i];
        let date =new Date(line.substring(0,23))
        //console.log(date);
        let duration = line.substring(24);
        timePlus(date.getTime(),duration)
        
    }
}

function solution(lines) {
    let answer = 0;

    timeInit(lines);

    for(let i =0;i<lines.length;i++){
        let et = endTime[i] + 999;
        let cnt = 1;
       // let st = startTime[i] + 999;
        for(let j =i+1;j<lines.length;j++){
            if(et>=startTime[j]) cnt++;
        }
        answer = Math.max(answer,cnt);
    }
    
    return answer;
}

(function solve(){
    let lines = [
        "2016-09-15 01:00:04.001 2.0s",
        "2016-09-15 01:00:07.000 2s"
        ];
   
    
    console.log(solution(lines));

})();