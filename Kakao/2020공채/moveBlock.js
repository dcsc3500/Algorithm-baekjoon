let board;
let answer = 987654321;
let N;
let visited = new Array();
let q = new Array();
let dir = [
    [-1,0],[0,1],[1,0],[0,-1]
];


function init(boards){
    board = boards
    N = boards.length;
    for(let i =0;i<2;i++){
        let arr1 = new Array();
        for(let j =0;j<N;j++){
            let arr2 = new Array();
            for(let k =0;k<N;k++){
                arr2.push(-1);
            }
            arr1.push(arr2);
        }
        visited.push(arr1);
    }

    //console.log(visited);
    
}


function canRotate0(pos){
    let tDir = [
        [0,0],[0,1],[1,0],[1,1]
    ];
    let X = pos.x1;
    let Y = pos.y1;
    for(let i=0;i<4;i++){
        let dirX = X + tDir[i][0];
        let dirY = Y + tDir[i][1];
        if(dirX<0 || dirY<0 || dirX >=N || dirY>=N) return false;;
        if(board[dirX][dirY] === 1) return false;
    }
    return true;
}
function canRotate1(pos){
    let tDir = [
        [0,0],[0,-1],[-1,0],[-1,-1]
    ];
    let X = pos.x2;
    let Y = pos.y2;
    for(let i=0;i<4;i++){
        let dirX = X + tDir[i][0];
        let dirY = Y + tDir[i][1];
        if(dirX<0 || dirY<0 || dirX >=N || dirY>=N) return false;
        if(board[dirX][dirY] === 1) return false;
    }
    return true;
}


function solution(boards) {
    init(boards)
    let curPos = {
        x1 : 0,
        y1 : 0,
        x2 : 0,
        y2 : 1,
        state : 0,
        time : 0
    };
    
    q.push(curPos);

    while(q.length !== 0){
        let pos = q.shift();
        let dirX1,dirX2,dirY1,dirY2;
        let time = pos.time;
        let state = pos.state;
        if((pos.x1 === N-1 && pos.y1 === N-1) || (pos.x2 === N-1 && pos.y2 === N-1)) return time;

        //console.log(pos)

        if(visited[state][pos.x1][pos.y1] !== -1 && visited[state][pos.x1][pos.y1] <= time) continue;

        visited[state][pos.x1][pos.y1] = time;
        
        for(let i =0;i<4;i++){
            dirX1 = pos.x1 + dir[i][0];
            dirY1 = pos.y1 + dir[i][1];
            dirX2 = pos.x2 + dir[i][0];
            dirY2 = pos.y2 + dir[i][1];
           
            if(dirX1<0 || dirY1<0 || dirX1 >=N || dirY1>=N) continue;
            if(dirX2<0 || dirY2<0 || dirX2 >=N || dirY2>=N) continue;
            if(board[dirX1][dirY1] === 1 || board[dirX2][dirY2] === 1) continue;
            
            q.push({x1 : dirX1, y1 : dirY1, x2: dirX2, y2 : dirY2, time : time+1, state : state});
        }

        if(canRotate0(pos)){
            let tempX1,tempX2,tempY1,tempY2;
            let tempState;
            if(state === 1){
                tempX1 = pos.x1;
                tempY1 = pos.y1+1;
                tempX2 = pos.x2;
                tempY2 = pos.y2 +1;
                tempState = 0;
                q.push({x1 : pos.x1, y1 : pos.y1, x2 : tempX1, y2 : tempY1, state : tempState, time : time+1});
                q.push({x1 : pos.x2, y1 : pos.y2, x2 : tempX2, y2 : tempY2, state : tempState, time : time+1});
            }
            else{
                tempX1 = pos.x1 + 1;
                tempY1 = pos.y1;
                tempX2 = pos.x2 + 1;
                tempY2 = pos.y2;
                tempState = 1;
                q.push({x1 : pos.x1, y1 : pos.y1, x2 : tempX1, y2 : tempY1, state : tempState, time : time+1});
                q.push({x1 : pos.x2, y1 : pos.y2, x2 : tempX2, y2 : tempY2, state : tempState, time : time+1});
            }
            

        }
        if(canRotate1(pos)){
            let tempX1,tempX2,tempY1,tempY2;
            let tempState;
            if(state === 1){
                tempX1 = pos.x1;
                tempY1 = pos.y1 -1;
                tempX2 = pos.x2;
                tempY2 = pos.y2 -1;
                tempState = 0;
                q.push({x1 : tempX1, y1 : tempY1, x2 : pos.x1, y2 : pos.y1, state : tempState, time : time+1});
                q.push({x1 : tempX2, y1 : tempY2, x2 : pos.x2, y2 : pos.y2, state : tempState, time : time+1});
            }
            else{
                tempX1 = pos.x1 - 1;
                tempY1 = pos.y1;
                tempX2 = pos.x2 - 1;
                tempY2 = pos.y2;
                tempState = 1;
                q.push({x1 : tempX1, y1 : tempY1, x2 : pos.x1, y2 : pos.y1, state : tempState, time : time+1});
                q.push({x1 : tempX2, y1 : tempY2, x2 : pos.x2, y2 : pos.y2, state : tempState, time : time+1});
            }
        }
        

    }
    

  

    return answer;
}


(function solve(){
    let board = [[0, 0, 0, 1, 1],[0, 0, 0, 1, 0],[0, 1, 0, 1, 1],[1, 1, 0, 0, 1],[0, 0, 0, 0, 0]];
    
    console.log(solution(board));

})();