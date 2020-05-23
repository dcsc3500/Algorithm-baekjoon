#include <string>
#include <vector>
#include<iostream>

using namespace std;

bool board[101][101][2];
int n;

bool buildGi(int y,int x){

    //기둥을 벗어나므로
    if(y == n) return false;

    //바닥위
    if(y == 0) return true;

    //다른 기둥 위
    if(board[y-1][x][0]) return true;

    //지금 아래 보위
    if(board[y][x][1]) return true;

    //다른 보 위
    if(x == 0) return false;
    if(board[y][x-1][1]) return true;
    

    return false;
}

bool buildBo(int y,int x){

    if(y == 0) return false;
    
    //지금 밑에 기둥
    if(board[y-1][x][0]){
        //cout<<"1"<<endl; 
        return true;
    }

    //다른 한쪽이 기둥
    if(x+1<=n){
        if(board[y-1][x+1][0]){
            //cout<<"2"<<endl; 
            return true;
        }
    }

    //양쪽 보사이
    if(x-1>=0 && x+1<=n){
        if(board[y][x-1][1] && board[y][x+1][1]){
            //cout<<"3"<<endl;  
            return true;
        }
    }

    return false;
}


void canRemove(int y,int x, int type){
    board[y][x][type] =false;
    //cout<<"type : " << type+1<<endl;

    for(int i =0;i<=n;i++){
        for(int j =0;j<=n;j++){
            
            if(board[i][j][0]){
             
                if(!buildGi(i,j)){
                
                   //cout<<i<<j<<"여기"<<endl;
                    board[y][x][type]= true;
                    return;
                }
            }
            if(board[i][j][1]){
                if(!buildBo(i,j)){
                    //ccout<<i<<j<<"여기"<<endl;
                    board[y][x][type] = true;;
                    return;
                }
            }
            
        
        }
    }

}

vector<vector<int>> solution(int N, vector<vector<int>> build_frame) {
    n = N;
    vector<vector<int>> answer;

    for(int i =0;i<build_frame.size();i++){
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];
        if(b == 1){
            if(a == 0){
                if(buildGi(y,x)){
                    board[y][x][a] = true;
                }
            }
            else if(a == 1){
                if(buildBo(y,x)){
                    board[y][x][a] = true;
                }
            }
        }
        else if (b == 0){          
            canRemove(y,x,a);
        }

    }


    for(int i = 0 ;i<=n;i++){
        for(int j =0;j<=n;j++){
            for(int k =0;k<2;k++){
            vector<int> v;
            if(board[j][i][k]){
                v.push_back(i);
                v.push_back(j);
                v.push_back(k);
            }

            if(v.size()>0) answer.push_back(v);
            }
        }
    }

    return answer;
}