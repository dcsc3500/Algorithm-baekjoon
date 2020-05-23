function getTime(curBus,t){
    let time = t;

    let hour = parseInt(time/60);
    let min = time % 60;
    

    let curHour = parseInt(curBus.substr(0,2));
    let curMin = parseInt(curBus.substr(3,2));
    hour = hour + curHour;
    min = curMin + min;
    if(min>=60){
        min -= 60;
        hour++;
    }
    let s = "";
    if(hour < 10) hour = '0' + hour;
    if(min<10) min = '0' + min;
    s += hour + ":" +min;
    //console.log(s);
    return s;

}


function getMinus(time){
    let curHour = parseInt(time.substr(0,2));
    let curMin = parseInt(time.substr(3,2));

    curMin--;
    if(curMin<0){
        curMin += 60;
        curHour--;
    }

    let hour = curHour;
    let min = curMin;

    if(hour < 10) hour = '0' + hour;
    if(min < 10) min = '0' + min ;
    let s = hour + ":" +min;
    return s;
    
    

}

function solution(n, t, m, timetable) {
    let answer = '';
    let curBus = "09:00";
    timetable.sort(function (a,b){
        if (a > b) return 1;
        if (b > a) return -1;
    })
    
    let index = 0;
    let time;

    for(let i=0;i<n;i++){
        
        //console.log(curBus)
        let cnt = m;
        let flag = false;
        while(true){
            time = timetable[index];
            //console.log(time,curBus)
            //console.log(time)
            if(time <= curBus){
                index++;
                cnt--;
                //console.log(cnt)
            }
            //다음버스를 타야함
            else{
                break;
            }
            //지금버스 꽉차서 다음버스타야함
            if(cnt === 0){
                break;
            }
            
            if(index>timetable.length){
                flag = true;
                break;
            } 
        }
        if(i<n-1){
            curBus = getTime(curBus,t);
        }  
    }
    if(!time){
        time = curBus;
    }
    else{
        time = getMinus(time);
    }

    //console.log(time, curBus)
    if(curBus<time)
        answer = curBus;
    else{
        answer = time;
    }



    return answer;
}

(function solve(){
    let n = 10;
    let t = 60;
    let m = 1;
    
    let timetable = ["10:30", "10:28"];	
    
    console.log(solution(n,t,m,timetable));

})();