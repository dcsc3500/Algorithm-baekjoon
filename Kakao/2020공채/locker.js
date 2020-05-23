let upLock = [];
let lockSize;
let keySize;
let sumSize;

function rotateKey(key){
    let temp = [];
    let size = key.length-1;
    for(let i =size;i>=0;i--){
        let one = []
        for(let j =0;j<key.length;j++){
            one[j] = key[j][i];
        }
        temp.push(one);
    }

    return temp;
}

function check(key,x,y){
    
    let tempLock = [];
    for(let i =0;i<upLock.length;i++){
        let aa = []
        for(let j =0;j<upLock.length;j++){
            aa[j] = upLock[i][j];
        }
        tempLock[i]=aa;
    }

    for(let i = 0;i<key.length;i++){
        for(let j =0;j<key.length;j++){
            let dirX = x+i;
            let dirY = y+j;
            if(dirX <0||dirY<0||dirX>=sumSize||dirY>=sumSize)
                continue;
            if(key[i][j] === 1 && tempLock[dirX][dirY] === 1) return false;
            if(key[i][j] === 0 && tempLock[dirX][dirY] === 1) continue;
            tempLock[dirX][dirY] = key[i][j];
        }
    }

    for(let i =0;i<lockSize;i++){
        for(let j=0;j<lockSize;j++){
            if(tempLock[i+keySize][j+keySize] === 0) return false;
        }
    }

    return true;
}


function solution(key, lock) {
    let answer = true;
    lockSize = lock.length;
    sumSize = lock.length + (2*key.length);
    keySize = key.length;
    
    for(let i=0;i<sumSize;i++){
        let temp = [];
        for(let j =0;j<sumSize;j++){
            temp.push(0);
        }
        upLock[i] = temp;
    }

    for(let i =0;i<lockSize;i++){
        for(let j =0;j<lockSize;j++){
            upLock[i+keySize][j+keySize] = lock[i][j];
        }
        
    }
    

    for(let i =0;i<4;i++){
        for(let j = 0;j<sumSize;j++){
            for(let k =0;k<sumSize;k++){
                let state = check(key,j,k);
                if(state)
                    return true;
            }
        }
        key = rotateKey(key);
    }
    
    return false;
}


(function solve(){
    let key = [[0, 0, 0], [1, 0, 0], [0, 1, 1]];
    let lock=[[1, 1, 1], [1, 1, 0], [1, 0, 1]];
    
    console.log(solution(key,lock));

})();