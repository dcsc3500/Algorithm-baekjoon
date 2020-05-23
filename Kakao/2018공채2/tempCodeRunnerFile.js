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

function songLen(song){
    let cnt = 0;
    for(let i =0;i<song.length;i++){
        if(song[i] === '#') cnt++;
    }
    

    return song.length - cnt;
}


function solution(m, musicinfos) {
    
    let answer = "(none)";

    musicinfos.map( s =>{
        let spliter = s.split(",");
        let song = spliter[3];

        let songLength = songLen(spliter[3]);

        let playTime = getPlayTime(spliter[1],spliter[0]);
        let gop = parseInt(playTime / songLength);
        let nam = parseInt(playTime % songLength);
        let fullsong = "";

        for(let i =0;i<gop;i++){
            fullsong += song;
        }


        let index = 0;
        let cnt = 0;
        while(true){
            if(cnt === nam) break;
            let c = song[index];
            if(c === '#'){
                fullsong += c;
                index++;
            }
            else{
                fullsong += c;
                index++;
                cnt++;
            }
        }
       

        let maxIndex = fullsong.length - m.length;
        //console.log(fullsong.length-m.length)
        for(let i =0;i<maxIndex;i++){
            
            
            let cmp = fullsong.substr(i,m.length);
            
            let shop = i+m.length;
            if(shop<fullsong.length && fullsong[shop] === '#'){
                cmp += '#';
            }

            //console.log(i,cmp,m)
            if(cmp === m){
                answer = spliter[2];
            }
        }
    
    })
    

    return answer;
}
