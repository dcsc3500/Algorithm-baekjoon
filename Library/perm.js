let arr = [1,2,3,4];
let visited = new Array(4).fill(false);

function swap(x,y){
    let temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
    
}

//일반순열
//모든경우 다나옴 4개중 3개만뽑기
function perm(depth,n,k){
    if(depth == k){
        let s = ""
        for(let i =0;i<k;i++){
            s+= arr[i];
        }
        console.log(s)
        return;
    }
    for(let i =depth;i<n;i++){
        swap(i,depth);
        perm(depth+1,n,k);
        swap(i,depth);
    }
}

//?
//중복되서 겹치는게 많아서 안쓸듯
function perm2(depth,n,k){
    if(depth === k){
        let s = ""
        for(let i =0; i<n ; i++){
            if(visited[i])
                s+= arr[i];
        }
        console.log(s)
        return;
    }
    for(let i =depth;i<n;i++){
        if(visited[i]) continue;

        visited[i] = true;
        perm2(depth+1,n,k);
        visited[i] = false;
    }
}

//순서있는 중복 x
//123
//124
//134
//234
function perm3(depth,n,k,start){
    if(depth === k){
        let s = ""
        for(let i =0; i<n ; i++){
            if(visited[i])
                s+= arr[i];
        }
        console.log(s)
        return;
    }
    for(let i =start;i<n;i++){
        if(visited[i]) continue;

        visited[i] = true;
        perm3(depth+1,n,k,i+1);
        visited[i] = false;
    }
}

//중복 순열 or 조합
//111
//112
//113
//114
//121
let select = new Array(4);
function perm4(depth,n,k){
    if(depth === k){
        let s = ""
        for(let i =0; i<k ; i++){
            let index = select[i]
            s+= arr[index];
        }
        console.log(s)
        return;
    }
    for(let i =0;i<n;i++){
        //if(visited[i]) continue;

        select[depth] = i
        perm4(depth+1,n,k,i+1);
    }
}





(function solve(){
    perm2(0,4,4)


    

})()