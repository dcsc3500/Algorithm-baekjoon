function solution(board, moves) {
    var answer = 0;
    let index = [];
    let stack = [];

    for(let i =0;i<board.length;i++){
        let j 
        for(j = 0 ;j<board.length;j++){
            if(board[j][i] != 0)
                break;
        }
        index.push(j);
    }

    moves.forEach(item => {
        
        let temp = index[item-1];
        if(temp !== board.length){
            let doll = board[temp][item-1]
            index[item-1]++;
            if(stack.length>0 && stack[stack.length-1] === doll){
                stack.pop();
                answer +=2;
            }
            else{
                stack.push(doll);
            }
        }
        
        
    })

    return answer;
}

(function solve(){
    let board = [[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]];
    let moves = [1,5,3,5,1,2,1,4];
    console.log(solution(board,moves));
})();