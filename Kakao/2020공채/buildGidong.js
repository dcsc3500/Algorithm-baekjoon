let N;
let map = [[]];

function getIndex( index){
    return N-index;
}

function canBuildGi(x,y){

    if(x<0 || x>N || y>0 || y>N) return false;
    //기둥위나 보의 한쪽끝이면
    if(map[x][y] > 0){
        return true;
    }

    //다른 보의 끝
    if(y-1 >= 0){
        if(map[x][y-1] == 2)
            return true;
    }

    return false;
}


function canBuildBo(x,y){

    //보가 바닥이면
    if(x == N) return false;

    if(x<0 || x>N || y>0 || y>N) return false;

    if(map[x+1][y] === 1 || map[x+1][y] === 3) return true;
    
    if(y == 0 || y == N) return false;

    if(map[x][y-1] >=2 && map[x][y+1] >=2) return true;

    return false;

}

function canDeleteGi(x,y){
    
    map[x][y] -= 1;
    
    if(map[x-1][y] ==1 || map[x-1][y] == 3)
        if(!canBuildGi(x-1,y)){
            map[x][y] +=1
            return false;
        }
    
    if(map[x-1][y] >=2){
        if(!canBuildBo(x-1,y)){
            map[x-1][y] +=1
            return false;
        }
    }
    
    if(map[x-2][y] >=2){
        if(!canBuildBo(x-1,y)){
            map[x-2][y] += 1;
            return false;
        }
    }

    return true;
    
}


function canDeleteBo(x,y){
    map[x][y] -= 2;
    if(map[x][y] ==1 || map[x][y] == 3){
        if(!canBuildGi(x,y)){
            map[x][y] += 2;
            return false;
        }
    }
    if(map[x][y+1] ==1 || map[x][y+1] == 3){
        if(!canBuildGi(x,y+1)){
            map[x][y] += 2;
            return false;
        }
    }

    if(map[x][y-1] >=2){
        if(!canBuildBo(x,y-1)){
            map[x][y-1]+= 2;
            return false;
        }
    }
    if(map[x][y+1] >=2){
        if(!canBuildBo(x,y+1)){
            map[x][y+1]+= 2;
            return false;
        }
    }

    

}

function solution(n, build_frame) {
    N = n;
    var answer = [[]];
    
    

    for(let i =0;i<n;i++){
        let temp  =[]
        for(let j =0;j<=n;j++){
            temp.push(0);
        }
        map.push(temp);
    }
    let temp = []
    for(let i =0;i<=n;i++){
        temp.push(2);
    }
    map.push(temp);

    for(let i =0;i<build_frame.length;i++){
        let x = getIndex(build_frame[i][0]);
        let y = build_frame[i][1];
        let a = build_frame[i][2];
        let b = build_frame[i][3];
        //구조물 설치
        if(b ===0){
            //기둥설치
            if(a == 0){
                if(canBuildGi(x,y)){
                    map[x][y] += 1;
                }
            }

            //보설치
            else if(a == 1){
                if(canBuildBo(x,y)){
                    map[x][y] +=2;
                }
            }

        }
        //구조물 삭제
        else{
            //기둥삭제
            if(a == 0){
                canDeleteGi(x,y);

            }

            //보 삭제
            else if(a == 1){
                canDeleteBo(x,y);
            }


        }
    }

    
    

    return map;
}