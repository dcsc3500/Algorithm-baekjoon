let dir;
let answer;
let board;
let N;

function dfs(x,y,nowDir,money){
    //console.log(x,y)
    if(x === N-1 && y === N-1){
        money += 100
        answer = Math.min(answer, money);
        return;
    }

    for(let i=0;i<4;i++){
        let dirX = x + dir[i][0];
        let dirY = y + dir[i][1];

        if(dirX <0 || dirY<0 || dirX>=N || dirY>=N) continue;

        if(board[dirX][dirY] === 1) continue;

        board[x][y] = 1;
        if(nowDir === i) dfs(dirX,dirY,i,money+100);
        else if(nowDir !== i) dfs(dirX,dirY,i,money+600);
        board[x][y] = 0;


    }
    

}

function solution(boards) {
    dir = [[-1,0],[0,1],[1,0],[0,-1]];
    answer = 999999999;
    N = boards.length;
    board = boards;
    if(board[0][1] === 0){
        board[0][0] = 1;
        dfs(0,1,1,0);
        board[0][0] = 0;
    }
    if(board[1][0] === 0){
        board[0][0] = 1;
        dfs(1,0,2,0);
        board[0][0] = 0;
        
    }

    return answer;
}

(function solve(){
    let board = [[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0],[0,0,0,0,0,1,0,0],[0,0,0,0,1,0,0,0],[0,0,0,1,0,0,0,1],[0,0,1,0,0,0,1,0],[0,1,0,0,0,1,0,0],[1,0,0,0,0,0,0,0]];
    console.log(solution(board));

})();