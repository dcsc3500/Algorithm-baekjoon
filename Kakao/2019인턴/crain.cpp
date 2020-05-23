#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;


stack<int> s;
vector<int> check;
vector<vector<int> > board;
int N;

void init(){
    for(int i =0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[j][i] != 0){
                check.push_back(j);
                break;
            }
        }
    }
    

}

int solution(vector<vector<int> > boards, vector<int> moves) {
    
    int answer = 0;
    board = boards;
    N = boards.size();
    init();

    for(int i =0;i<moves.size();i++){
        int temp = moves[i] -1;
        int& index = check[temp];
        if(index<N){
            int num = boards[index][temp];
            cout<< num<<endl;
            index++;
            if(s.size()>0){
                if(s.top() == num){
                    s.pop();
                    answer += 2;

                } 
                else s.push(num);
            }
            else s.push(num);
        }
    }


    return answer;
}
