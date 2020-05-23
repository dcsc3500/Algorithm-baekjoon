#include <string>
#include <functional>
#include <vector>

using namespace std;

vector<int> pre;
vector<int> post;

struct temp{
    int num,y,x;
};

bool comp(temp a,temp b){
    if(a.y == b.y)
        return a.x <b.x;
    return a.y>b.y;
    
}



class Node {
public:
    int num,y,x;
    Node *left;
    Node *right;
    Node(int num, int y, int x, Node* left = nullptr, Node* right = nullptr) {
        this->y = y;
        this->x = x;
        this->num = num;
        this->left = left;
        this->right = right;
    }

};

class Tree{

public:
    Node* root;

    Tree(int num,int y,int x){
        root = new Node(num,y,x);
    }


    void addNode(Node* cur,Node *temp){

        if(cur->x > temp->x){
            if(cur->left == nullptr){
                cur->left = temp;
                return;
            }
            addNode(cur->left,temp);
        }
        else{
            if(cur->right == nullptr){
                cur->right = temp;
                return;
            }
            addNode(cur->right, temp);
        }
        

    }


    void preOrder(Node *cur){
        if(cur != nullptr){
            pre.push_back(cur->num);
            preOrder(cur->left);
            preOrder(cur->right);
        }
    }

    void postOrder(Node *cur){
        if(cur != nullptr){
            
            postOrder(cur->left);
            postOrder(cur->right);
            post.push_back(cur->num);
        }
    }

};



vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    vector<temp> temps;

    for(int i =0;i<nodeinfo.size();i++){
        temps.push_back({i+1,nodeinfo[i][1],nodeinfo[i][0]});
    }

    sort(temps.begin(),temps.end(),comp);

    Tree tree(temps[0].num,temps[0].y,temps[0].x);

    for(int i=1;i<temps.size();i++){
        Node* temp = new Node(temps[i].num,temps[i].y,temps[i].x);
        tree.addNode(tree.root,temp);
    }

    tree.postOrder(tree.root);
    tree.preOrder(tree.root);

    answer.push_back(pre);
    answer.push_back(post);



    return answer;
}
