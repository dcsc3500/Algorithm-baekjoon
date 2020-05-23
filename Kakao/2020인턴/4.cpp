#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

int cache[26][26];

int dir[4][2] = 
    {
        {-1,0},{0,1},{1,0},{0,-1}
    };
int answer;
vector<vector<int>> board;
int N;

void dfs(int x,int y,int nowDir,int money){
    //cout<<x<<"  "<<y<<endl;
    

    if(x == N-1 && y == N-1){
        money += 100;
        answer = min(answer, money);
        return;
    }

    if(cache[x][y] < money) return;
    //cout<<x<<"  "<<y<<endl;
    cache[x][y] = money;

    for(int i=0;i<4;i++){
        int dirX = x + dir[i][0];
        int dirY = y + dir[i][1];

        if(dirX <0 || dirY<0 || dirX>=N || dirY>=N) continue;

        if(board[dirX][dirY] == 1) continue;
        
        

        board[x][y] = 1;
        if(nowDir == i) dfs(dirX,dirY,i,money+100);
        else if(nowDir != i) dfs(dirX,dirY,i,money+600);
        board[x][y] = 0;


    }
    

}

int solution(vector<vector<int>> boards) {
    

    for(int i =0;i<26;i++){
        for(int j =0;j<26;j++){
            cache[i][j] = 999999999;
        }
    }
    
    answer = 999999999;
    
    N = boards.size();
    board = boards;
    if(board[0][1] == 0){
        board[0][0] = 1;
        dfs(0,1,1,0);
        board[0][0] = 0;
    }
    if(board[1][0] == 0){
        board[0][0] = 1;
        dfs(1,0,2,0);
        board[0][0] = 0;
        
    }

    return answer;
}