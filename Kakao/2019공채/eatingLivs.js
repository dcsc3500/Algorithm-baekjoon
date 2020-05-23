function binSearch(r,k,len){

    for(let i = r;i>=0;i--){
        if((k-(len*i)) >= 0) return i;
    }
}


function solution(food_times, k) {
    let answer = 0;

    let foods = [];
    
    for(let i =0;i<food_times.length;i++){
        foods.push({times : food_times[i], index : i+1});
    }
    
    
    foods.sort(function(a,b){
        if(a.times === b.times)
            return a.index - b.index;
        return a.times - b.times;
    });

    let start = 0;
    let end = foods.length;
    let loop = 0;
    
    
    while(true){
        while(true){
            if(start>=end)
                return -1;
            if(loop === foods[start].times)
                start++;
            else break;    
        }
        console.log("start :",start,"k :",k,"loop : ",loop);
        let len = end - start;
        if(k - (len * (foods[start].times - loop)) <0){
            let temp = binSearch(foods[start].times - loop,k,len);
            k = k-(temp*len);
            break;
        }
        k = k- (len*(foods[start].times - loop));
       loop += (foods[start].times - loop);

    }

    let i;
    for(i=0;i<food_times.length;i++){
        if(k<0) break;
        if(foods[start].times > food_times[i]) continue;
        k--;
    }

    if(k>=0) answer = -1;
    else answer = i;

   
    return answer;

} 



(function solve(){
    let k = 8;
    let food_times = [3,2,2,4];
    
    console.log(solution(food_times,k));

})();