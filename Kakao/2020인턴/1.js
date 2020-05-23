let left =[];
let right=[];
let answer = '';
let hand;

function getShort(number){
    let lx,ly,rx,ry;
    //console.log(left[0],left[1])
    if(number === 2){
        lx = Math.max(left[0] - 0, 0 - left[0]);
        ly = Math.max(left[1] - 1, 1 - left[1]);
        rx = Math.max(right[0] - 0, 0 - right[0]);
        ry = Math.max(right[1] - 1, 1 - right[1]);
    }
    if(number === 5){
       
        lx = Math.max(left[0] - 1, 1 - left[0]);
        ly = Math.max(left[1] - 1, 1 - left[1]);
        rx = Math.max(right[0] - 1, 1 - right[0]);
        ry = Math.max(right[1] - 1, 1 - right[1]);
    }
    if(number === 8){
        lx = Math.max(left[0] - 2, 2 - left[0]);
        ly = Math.max(left[1] - 1, 1 - left[1]);
        rx = Math.max(right[0] - 2, 2 - right[0]);
        ry = Math.max(right[1] - 1, 1 - right[1]);
    }
    if(number === 0){
        lx = Math.max(left[0] - 3, 3 - left[0]);
        ly = Math.max(left[1] - 1, 1 - left[1]);
        rx = Math.max(right[0] - 3, 3 - right[0]);
        ry = Math.max(right[1] - 1, 1 - right[1]);
    }
    console.log(lx+ly,rx+ry)
    if(lx + ly > rx + ry){
        return 'R'
    }
    else if (lx +ly<rx+ry){
        return 'L';
    }
    else{
        if(hand === 'right') return 'R';
        else return 'L';
    }


}

function getAns(number){
    if(number === 1){
        left[0] = 0;
        left[1] = 0;
        answer += 'L';
    }
    if(number === 4){
        left[0] = 1;
        left[1] = 0;
        answer += 'L';
    }
    if(number === 7){
        left[0] = 2;
        left[1] = 0;
        answer += 'L';
    }
    if(number === 3){
        right[0] = 0;
        right[1] = 2;
        answer += 'R';
    }
    if(number === 6){
        right[0] = 1;
        right[1] = 2;
        answer += 'R';
    }
    if(number === 9){
        right[0] = 2;
        right[1] = 2;
        answer += 'R';
    }
    if(number === 2){
        let temp = getShort(2);
        if(temp === 'L'){
            left[0] = 0;
            left[1] = 1;
            answer += 'L';
        }
        else{
            right[0] = 0;
            right[1] = 1;
            answer += 'R';
        }
    }
    if(number === 5){
        let temp = getShort(5);
        //console.log(temp)
        if(temp === 'L'){
            left[0] = 1;
            left[1] = 1;
            answer += 'L';
        }
        else{
            right[0] = 1;
            right[1] = 1;
            answer += 'R';
        }
    }
    if(number === 8){
        let temp = getShort(8);
        if(temp === 'L'){
            left[0] = 2;
            left[1] = 1;
            answer += 'L';
        }
        else{
            right[0] = 2;
            right[1] = 1;
            answer += 'R';
        }
    }
    if(number === 0){
        let temp = getShort(0);
        if(temp === 'L'){
            left[0] = 3;
            left[1] = 1;
            answer += 'L';
        }
        else{
            right[0] = 3;
            right[1] = 1;
            answer += 'R';
        }
    }
    

}

function solution(numbers, hands) {
    left.push(3);
    left.push(0);
    right.push(3);
    right.push(2);
    hand = hands
    numbers.map(number =>{
        //console.log(number)
        getAns(number); 
    })

    
    return answer;
}
(function solve(){
    let numbers = [1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5];
    let hand = 'right';
    console.log(solution(numbers, hand));

})();