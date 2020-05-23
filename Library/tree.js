class Node{
    constructor(index,x){
        this.index = index
        this.x=x;
        this.left = null;
        this.right = null
    }
}
let i1 =[[5,3],[11,5],[13,3],[3,5],[6,1],[1,3],[8,6],[7,2],[2,2]];
let prearr=[];
let postarr= []
function solve(input){
    let new_info = input.map((i,idx)=>{
        return {'x':i[0],'y':i[1],'idx':idx+1}
    }).sort((a,b)=>{
        return b.y - a.y === 0? a.x-b.y : b.y-a.y
    })

    console.log(new_info);
    
    let root = new Node(new_info[0].idx,new_info[0].x)

    for(let i = 1 ; i< new_info.length ; i ++){
        let node = root;
        let temp = new Node(new_info[i].idx,new_info[i].x)

        while(true){
            if(node.x > temp.x){
                if(node.left == null){
                    node.left = temp;
                    break;
                }
                node =node.left
            }
            if(node.x < temp.x){
                if(node.right == null){
                    node.right = temp;
                    break;
                }
                node = node.right
            }
        }
    }
    preother(root)
    postohter(root)
    return [prearr,postarr]
}

function preother(node){
    if(node == null) return ;
    prearr.push(node.index)
    preother(node.left)
    preother(node.right)
}
function postohter(node){
    if(node == null) return ;
    postohter(node.left)
    postohter(node.right)
    postarr.push(node.index)

}
console.log(solve(i1));