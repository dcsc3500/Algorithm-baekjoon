function makeFront(trie,query,depth){
    if(depth === query.length){
        trie.set("done",0);
        return ;
    }
    let c = query.charAt(depth);
    
    if(trie.has(c)){
        let tempTrie = trie.get(c)
        makeFront(tempTrie,query,depth+1);
    }
    else{
        let tempTrie = new Map();  
        trie.set(c,tempTrie);
        makeFront(tempTrie,query,depth+1);
    }

}

function makeFront2(trie,query){
    let str = "";
    for(let i =0;i<query.length;i++){
        let c = query.charAt(i);
        str += c;
        if(!trie.has(str)){
            trie.set(str,-1);
        }
    }

    trie.set(str,0);

}



function makeTrie(trie, queries){
    for(let i =0;i<queries.length;i++){
        let query = queries[i];
        makeFront(trie,query,0);
    }

}

function findWord(trie,word,depth){
    if(depth === word.length){

        if(trie.has("done")){
            let num = trie.get("done");
            trie.set("done",num+1);
        }

        return;
    }
    let c = word.charAt(depth);
    
    let tempTrie;
    if(trie.has(c)){
        tempTrie = trie.get(c);
        findWord(tempTrie,word,depth+1);
    }
    if(trie.has('?')){
        tempTrie = trie.get('?')
        findWord(tempTrie,word,depth+1);
    }
}


function findWord2(trie,word){
    let str = "";
    let q = [];
    if(trie.has('?')) q.push('?');
    if(trie.has(word[0])) q.push(word[0]);
    while(q.length !=0){
        let temp = q.shift();
        let size = temp.length;
        if(size == word.length){
            let num = trie.get(temp);
            if(num>=0)
                trie.set(temp,num+1);
        }
        else{
            let c = word[size];
            let str1 = temp + c;
            if(trie.has(str1))
                q.push(str1);
            let str2 = temp +'?';
            if(trie.has(str2))
                q.push(str2);
        }
    }

    

}

function getAnswer(trie,query,depth){
    if(depth === query.length){
        return trie.get("done");
    }

    let c = query.charAt(depth)
    let tempTrie = trie.get(c);

    return getAnswer(tempTrie,query,depth+1);


}

function getAnswer2(trie,query){

    return trie.get(query);


}


function solution(words, queries) {
    let frontTrie = new Map();
    let answer = [];
    makeTrie(frontTrie,queries);
    //console.log(frontTrie);


    for(let i =0;i<words.length;i++){
        let word = words[i];
        findWord(frontTrie,word,0);
    }

    for(let i =0;i<queries.length;i++){
        let tempNum;
        let query = queries[i];
        
        tempNum = getAnswer(frontTrie,query,0);
        answer.push(tempNum);
    }

    return answer;
}