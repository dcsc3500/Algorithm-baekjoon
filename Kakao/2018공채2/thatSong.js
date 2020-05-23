function getPlayTime(end,start){

    let eh = parseInt(end.substr(0,2));
    let em = parseInt(end.substr(3,2));
    let sh = parseInt(start.substr(0,2));
    let sm = parseInt(start.substr(3,2));


    let disM = em - sm;
    let disH = eh - sh;
    
    if(disM <0){
        disM += 60;
        disH--;
    }

    let min = (disH * 60) + disM;

    return min;
}


function solution(M, musicinfos) {
    
    let answer = "(None)";
    let ansMin = -1;

    let m = "";
    for(let i =0;i<M.length-1;i++){
        let c1 =M[i];
        let c2 = M[i+1];
        if(c1 === '#')continue;
        if(c2 === '#')
            c1 = c1.toLowerCase();
        m += c1;
        
    }

    if(M[M.length-1] !== '#')
        m+=M[M.length-1];

    //console.log(m)

    musicinfos.map( s =>{
        let spliter = s.split(",");
        let temp = spliter[3];
        let song = '';

        for(let i =0;i<temp.length-1;i++){
            let c1 =temp[i];
            let c2 = temp[i+1];
            if(c1 ==='#')continue;
            if(c2 ==='#')
                c1 = c1.toLowerCase();
            song += c1;
            
        }
        if(temp[temp.length-1] !== '#')
            song+=temp[temp.length-1];

        //console.log(song)

        let playTime = getPlayTime(spliter[1],spliter[0]);
        let gop = parseInt(playTime / song.length);
        let nam = parseInt(playTime % song.length);
        let fullsong = "";

        for(let i =0;i<gop;i++){
            fullsong += song;
        }
        fullsong += song.substr(0,nam);

        let maxIndex = fullsong.length - m.length;
        //console.log(fullsong.length-m.length)
        for(let i =0;i<=maxIndex;i++){
            
            
            let cmp = fullsong.substr(i,m.length);
            //console.log(i,cmp,m)
            if(cmp === m){
                if(ansMin<playTime){
                    answer = spliter[2];
                    ansMin = playTime
                }
            }
        }
    
    })
    

    return answer;
}

(function solve(){
    let m ="ABC";
    let musicinfos = ["12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"]

    console.log(solution(m,musicinfos));

})();