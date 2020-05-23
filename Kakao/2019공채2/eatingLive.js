function solution(food_times, k) {
    let answer = 0;
    let foods = new Array();
    

    for(let i =0;i<food_times.length;i++){
        foods.push({time: food_times[i], idx: i});
    }

    foods.sort(function(a,b){
        return a.time-b.time;
    })

    let post =0;
    let gop ,len;
    let i;
    for(i =0;i<foods.length;i++){
        gop = foods[i].time - post;
        len = foods.length - i;
        console.log(k,gop,len)
        if(k - (gop * len) >=0){
            k -= (gop*len);
        }
        else{
            post = foods[i].time
            console.log(k)
            break;
        }
        post = foods[i].time;
 
    }
    if(i === foods.length) return -1;
    //console.log(k)
    
    // console.log(len)
    if( parseInt(k / (len)) >0 ){
        let gg = parseInt(k/len);
        k -= (gg*len);
    }
    //console.log(k)
    


    foods = foods.filter(function(n){
        return n.time-post >=0;
    });
    foods.sort(function(a,b){
        return a.idx-b.idx
    })
    // console.log(foods.length,k)
    if(foods.length === 0) return -1
    
    //console.log(foods)
        answer = (foods[k].idx)+1;
    
    //console.log(answer)




    return answer;
}
(function solve(){
    let food_times = [3, 1, 2];
    let k = 6;
    console.log(solution(food_times,k));
})();