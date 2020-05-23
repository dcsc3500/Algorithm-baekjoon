
let cnt = [];
let answer = 0;
let tong = [];
function check(){
    let a = tong[tong.length-1];
    let b = tong[tong.length-2];
    if(a === b){
        answer = answer + 2;
        tong.pop();
        tong.pop();
    }
}

function solution(board, moves) {
   
    for(let i = 0;i<board[0].length;i++){
        let j = 0;
        for(;j<board.length;j++){
            //console.log(board[j][i]);
            if(board[j][i] !== 0)
                break;
        }
        //console.log("j: "+j);
        cnt.push(j);
    }
    //console.log(cnt);

    for(let i =0;i<moves.length;i++){
        let temp = moves[i] - 1;
        let index = cnt[temp];
        //console.log(index,temp);
        if(index >= board.length ) continue;
        tong.push(board[index][temp]);
        cnt[temp]++;
        //console.log(tong);

        if(tong.length>=2){
            check();
        }

    }

    return answer;
}

(function solve(){
    let b = [[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]];
    let m = [1,5,3,5,1,2,1,4];
    
    console.log(solution(b,m));

})();