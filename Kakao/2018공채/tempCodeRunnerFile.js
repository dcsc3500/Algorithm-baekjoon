let visited = []
let board = [];
function makeFalse(m,n){
    for(let i =0;i<m;i++){
        for(let j =0;j<n;j++){
            visited[i][j] = false;
        }
    }
    //console.log(visited)
}

function check(m,n){
    let dir = [
        [0,1],[1,0],[1,1]
    ];
    for(let i =0;i<m-1;i++){
        for(let j=0;j<n-1;j++){
            if(board[i][j] === '0') continue;
            let state = true;
            for(let k =0;k<3;k++){
                let ti = i+dir[k][0];
                let tj = j+dir[k][1];
                if((board[i][j] !== board[ti][tj]) || (board[ti][tj] === '0')){
                    state = false;
                    break;
                }
            }
            if(state){
                visited[i][j] = true;
                for(let k =0;k<3;k++){
                    let ti = i+dir[k][0];
                    let tj = j+dir[k][1];
                    visited[ti][tj] = true;
                }
            }
        }
    }

}

function deleteItem(m,n){
    let ans = 0;
    for(let i =0;i<m;i++){
        for(let j =0;j<n;j++){
            if(visited[i][j]){
                board[i][j] = '0';
                ans++;
            }
        }
    }
    //console.log(visited)
    return ans;
}

function letDown(m,n){
    for(let i =0;i<n;i++){
        let holeIndex = m-1;
        for(holeIndex;holeIndex>=0;holeIndex--){
            if(board[holeIndex][i] == '0') break;
        }
        let downIndex = holeIndex;
        for(downIndex;downIndex>=0;downIndex--){
            if(board[downIndex][i] !='0') break;
        }
        //console.log(holeIndex,downIndex);
        if(downIndex>=0){
            let sub = holeIndex - downIndex;
            for(let j = downIndex;j>=0;j--){
                board[j+sub][i] = board[j][i];
                //console.log(board[j+sub][i])
                board[j][i] = '0';
            }
        }
    }
}


function solution(m, n, boards) {
    let answer = 0

    for(let i =0;i<boards.length;i++){
        let s = boards[i];
        //console.log(s);
        let temp = [];
        for(let j =0;j<s.length;j++){
            temp.push(s[j]);
        }
        board.push(temp);
    }
    //console.log(board)

    for(let i =0;i<m;i++){
        visited.push(new Array(n).fill(false))
    }

    let state = true;
    while(state){
        check(m,n);
        let num = deleteItem(m,n);
        answer += num
        letDown(m,n);
        //console.log(board)
        makeFalse(m,n);
        //console.log(num)
        if(num === 0){
             state = false;
        }
    }



    return answer;
}

(function solve(){
    let m,n,boards;
   //boards = ["CCBDE", "AAADE", "AAABF", "CCBBF"]
   boards = ["AA","AA"]
    
    console.log(solution(2,2,boards));

})();