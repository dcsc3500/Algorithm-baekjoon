function solution(s) {
    var answer = [];
    s = s.slice(2,s.length-2)
    let spliter = s.split('},{');
    
    spliter.sort(function (a,b){
        return a.length- b.length;
    })
    let map = new Map();
    spliter.map(item => {
        
        let spl = item.split(',');
        for(let t of spl){
            //console.log(t)
            if(!map.has(t)){
                answer.push(t*1);
                map.set(t,true);
            }
        }
    })


    return answer;
}

(function solve(){
    let s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
    console.log(solution(s));

})();