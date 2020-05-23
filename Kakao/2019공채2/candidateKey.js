let mini = new Map();
let answer = 0;
let rel;
let maxN;

function checkUniq(selected){

    let tmap = new Map();
    //console.log(selected)
    
    for(let i =0;i<rel.length;i++){
        let s = "";
        for(let j =0;j<selected.length;j++){
            let t = parseInt(selected[j]);
            s += rel[i][t];            
        }
        //console.log(s);
        if(tmap.has(s)) return false;
        tmap.set(s, true);

    }

    return true;

}

function perm(start,depth,selected,n){
    if(n === depth){
        
        let state = checkUniq(selected);
        if(state){
            console.log(selected)
            mini.set(selected,true);
            answer++;
        }
        
        return;
    }

    for(let i = start;i<maxN;i++){
        let temp = "" + i;

        let s = selected + i;
        
        if(mini.has(s) || mini.has(temp)){
            continue;
        }
       
        perm(i+1,depth+1,s,n);
    }

}

function solution(relations) {
    maxN = relations[0].length;
    rel = relations;
    //console.log(n)
    for(let i =1;i<=maxN;i++){
        //console.log("")
        perm(0,0,"",i);
    }
    return answer;
}

(function solve(){
    let relations = [["100","ryan","music","2"],["200","apeach","math","2"],["300","tube","computer","3"],["400","con","computer","4"],["500","muzi","music","3"],["600","apeach","music","2"]];
    
    console.log(solution(relations));
})();