function splitFile(name){
    let head = "";
    let num;
    let tail = "";

    //console.log(name)

    let i;
    for(i =0;i<name.length;i++){
        let c = name[i];

        if('0'<=c && c<='9')
            break;
    }
    head = name.substr(0,i).toLowerCase();
    let j
    for(j = i;j<name.length;j++){
        let c = name[j];
        //console.log(c)

        if(c<'0' || c>'9')
            break;
    }
    num = parseInt(name.substr(i,j-i));
    //console.log(j)
    tail = name.substr(j).toLowerCase();

    return {name,head,num,tail}


}

function solution(tfiles) {
    let answer = [];

    let files = [];
    //console.log(tfiles)

    let cnt = 0;

    tfiles.map(name=>{
        //console.log(name)
        let tt = splitFile(name);
        tt.idx = cnt;
        cnt++;
        files.push(tt);
    })




    //console.log(files)

    files.sort(function (a,b){
        if(a.head===b.head){
            if(a.num == b.num){
                if(a.idx>b.idx) return 1;
                return -1;
            }
            if(a.num>b.num) return 1;
            return -1;
            

        }
        if(a.head>b.head) return 1;
        return -1;
    })

   // console.log("------")
  //  console.log(files)

    files.map(item => {
        answer.push(item.name)
    })



    return answer;
}

(function solve(){
    let files =		["F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"]

    console.log(solution(files));
})();