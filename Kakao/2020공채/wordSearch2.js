let root=[];
let reversRoot=[];
function solution(words, queries) {
    var answer = [];
    
    words.map(word=>{
        let arr = root[word.length] === undefined?new Map():root[word.length];
        let arr2 = reversRoot[word.length] === undefined ? new Map() : reversRoot[word.length];
        
        
        let node = arr;
        let node2 =arr2;
        
        arr2.set('?',arr2.get('?') === undefined ? 1: arr2.get('?') +1)


        if(!arr2.has('next'))
            arr2.set('next',new Map())
        arr2 = arr2.get('next')
        for(let i = 0 ,k=word.length -1; i < word.length ; i ++,k--){
            if(arr2.has(word[k]))
                arr2.set(word[k],arr2.get(word[k]) +1)
            else
                arr2.set(word[k],1)
            if(!arr2.has(word[k]+"next"))
                arr2.set(word[k]+'next',new Map())
            
            if(arr.has(word[i]))
                arr.set(word[i],arr.get(word[i]) +1)
            else
                arr.set(word[i],1)
            if(!arr.has(word[i]+"next"))
                arr.set(word[i]+'next',new Map())

            arr =arr.get(word[i]+'next');             
            arr2=arr2.get(word[k]+'next')
        }
        root[word.length] = node;
        reversRoot[word.length] = node2;        
    })
    
    for(let i = 0 ; i < queries.length; i ++){
        if(queries[i][0] !== '?'){
            if(root[queries[i].length]=== undefined)
                answer [i] = 0
            else
                answer[i] = get_trie(queries[i]);
        }
        else{
            if(reversRoot[queries[i].length] ===undefined)
                answer[i] = 0;
            else
                answer[i] = reverse_get_trie(queries[i])
        }
    }
    // console.log(reversRoot[5]);
    
    return answer;
}
function get_trie(querie){
    let node = root[querie.length]
    for(let i = 0 ; i< querie.length ; i ++){
        if(!node.has(querie[i]))
            return 0;
        if(node.has(querie[i])){
            if(querie[i+1] ==='?'){
                return node.get(querie[i])
            }
            node= node.get(querie[i]+'next')
        }
    }
    return 0;
}
function reverse_get_trie(querie){    
    let node =reversRoot[querie.length];
    if(querie[querie.length-1] ==='?')
        return node.get('?')
    node= node.get('next')
    
    for(let i = querie.length-1 ; i >= 0 ;i--){
        if(!node.has(querie[i]))
            return 0;
        if(node.has(querie[i])){
            if(querie[i-1] ==='?')
                return node.get(querie[i])
            node= node.get(querie[i]+'next')
        }
    }
    return 0;
}

(function solve(){
   
    console.log(solution(words,queries));

})();