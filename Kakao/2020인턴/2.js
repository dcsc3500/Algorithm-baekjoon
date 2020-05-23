let arr = [];
let ex;
let saveEx;
let answer;

function swap(x,y){
    let temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
    
}

function doCalculate(index){
    let start = index
    let end = index;
    let i;
    for(i = index;i>=0;i--){
        if( ex[i] === '(')
            break;
    }
    i++;
    start = i;

    for(i = index+1;i<ex.length;i++){
        if( ex[i] === ')')
            break;
    }
    end = i;

    let first = parseInt(ex.substring(start,index));
    let second = parseInt(ex.substring(index+2,end));
    //console.log(first,second)
    let cal;
    if(ex[index] === '*'){
        cal = first*second;
    }
    else if(ex[index] === '+'){
        cal = first + second;
    }
    else if (ex[index] === '-'){
        cal = first - second;
    }
    let ret = "";
    ret += '('
    ret += cal;
    ret += ')'
    //console.log(ret)

    ex = ex.replace(ex.substring(start-1,end+1),ret)
    console.log(ex)

    //console.log(first, second, ex[index], cal)
    

}

function perm(depth,n,k){
    if(depth == k){
        saveEx = ex;
        //console.log(arr)
        for(let i =0;i<3;i++){  
            while(true){
                let j =0;
            for(j=0;j<ex.length-1;j++){
                if(ex.substr(j,2) === arr[i]){
                    //console.log(ex.substr(j,2), ex[j+1])
                    doCalculate(j+1);
                    break;
                }
            }
            if(j== ex.length-1) break;
            }
            
        }
        let temp = parseInt(ex.substr(1,ex.length-2));
        console.log(temp)
        temp = Math.abs(temp);
        answer = Math.max(answer,temp);  

        ex = saveEx;
        return;
    }
    for(let i =depth;i<n;i++){
        swap(i,depth);
        perm(depth+1,n,k);
        swap(i,depth);
    }
}



function solution(expression) {
    answer = -1;
    ex = "";
    ex += '(';
    expression = expression.replace(/[-]/g,')-(');
    
    expression = expression.replace(/[+]/g,')+(');
    expression = expression.replace(/[*]/g,')*(');
    ex += expression;
    ex += ')';
    //console.log(ex)
    
    arr.push(')*');
    arr.push(')-');
    arr.push(')+');
    //console.log(arr)

    perm(0,3,3)


    

    return answer;
}

(function solve(){

    let expression = "100*121-11111-1"	;
    console.log(solution(expression));

})();