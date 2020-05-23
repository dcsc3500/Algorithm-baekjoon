class Node {
    data;
    cnt;
    constructor(data) { 
        this.data = data; 
        for (let i = 0; i < 26; i++) { 
            const tmp = String.fromCharCode(97 + i); 
            this[tmp] = undefined; 
        } 
    } 
} 
class Trie { 
    root;
    constructor(root) { 
        this.root = root; 
    } 
    add = (word) => { 
        let currentNode = this.root; 
        let previousWhileChar = ''; 
        for (let i = 0; i < word.length; i++) { 
            let currentChar = word.charAt(i); 
            previousWhileChar += currentChar; 
            if (currentNode[currentChar] === undefined) { 
                const newNode = new Node(previousWhileChar); 
                currentNode[currentChar] = newNode; 
                currentNode = newNode; 
            } 
            else { 
                currentNode = currentNode[currentChar]; 
            } 
        } 
    }; 
    
    lookUp = (word) => { 
        let currentNode = this.root; 
        for (let i = 0; i < word.length; i++) { 
            let currentChar = word.charAt(i); 
            currentNode = currentNode[currentChar]; 
            if (currentNode.data === word) 
            return currentNode; 
        } 
        return 'no match'; 
    } 
}



function solution(words) {
    let answer = 0;
    
    words.map(item => {
        for(let i =0;i<item.length;i++){
            let c = item[i];
            if()
        }
    })

    return answer;
}


(function solve(){
    let words;

    console.log(solution(words));

})();