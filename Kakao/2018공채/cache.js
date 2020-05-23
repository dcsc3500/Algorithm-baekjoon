function solution(cacheSize, cities) {
    let answer = 0;
    let sets = new Set();
    for(let i =0;i<cities.length;i++){
        let city = cities[i].toLowerCase();
        
        //존재한다면
        if(sets.has(city)){
            sets.delete(city);
            sets.add(city);
            answer++;
        }
        //존재하지않으면
        else{
            
            if(sets.size<cacheSize){
                sets.add(city);
            }
            else if(cacheSize != 0){
                let temps = sets.keys();
                let temp = temps.next().value;
                sets.delete(temp);
                sets.add(city);
            }
            answer += 5;
        }
        
    }


    return answer;
}