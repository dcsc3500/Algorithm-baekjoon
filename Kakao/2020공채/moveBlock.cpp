#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include<cstring>

using namespace std;

int N;
int visited[3][101][101];
int dir[4][2] = {
    {-1,0},
    {0,1},
    {1,0},
    {0,-1}
};
int answer = 987654321;
vector<vector<int> > board;

bool canRotate1(vector<vector<int> > &xy,int state){
    //console.log(xy)
    int dirX1,dirX2,dirY1,dirY2;
    if(state == 1){
        dirX1 = xy[0][0] + 0;
        dirY1 = xy[0][1] + 1;
        dirX2 = xy[1][0] + 0;
        dirY2 = xy[1][1] + 1;
    }

    else{
        dirX1 = xy[0][0] + 1;
        dirY1 = xy[0][1] + 0;
        dirX2 = xy[1][0] + 1;
        dirY2 = xy[1][1] + 0;
    }
    //console.log(dirX1,dirX2,dirY1,dirY2);

    if(dirX1<0|| dirY1<0 || dirX1>= N||dirY1>=N) return false;
    if(dirX2<0|| dirY2<0 || dirX2>= N||dirY2>=N) return false;
    //console.log(dirX1,dirY1,dirX2,dirY2);
    if(board[dirX1][dirY1] == 0 && board[dirX2][dirY2] == 0)
        return true;
    
    return false;

}


bool canRotate2(vector<vector<int> >& xy,int state){
    //console.log(xy)
    int dirX1,dirX2,dirY1,dirY2;
    if(state == 1){
        dirX1 = xy[0][0] + 0;
        dirY1 = xy[0][1] - 1;
        dirX2 = xy[1][0] + 0;
        dirY2 = xy[1][1] - 1;
    }
    else{
        dirX1 = xy[0][0] - 1;
        dirY1 = xy[0][1] + 0;
        dirX2 = xy[1][0] - 1;
        dirY2 = xy[1][1] + 0;
    }
    //console.log(dirX1,dirX2,dirY1,dirY2);

    if(dirX1<0|| dirY1<0 || dirX1>= N||dirY1>=N) return false;
    if(dirX2<0|| dirY2<0 || dirX2>= N||dirY2>=N) return false;
    //console.log(dirX1,dirY1,dirX2,dirY2);
    if(board[dirX1][dirY1] == 0 && board[dirX2][dirY2] == 0)
        return true;
    
    return false;

}




void move(vector<vector<int> >&xy,int state,int time){   
    //console.log(xy,state,time);
    if((xy[1][0] == N-1 && xy[1][1] == N-1) || (xy[0][0] == N-1 && xy[0][1] == N-1)){
        answer = min(answer, time);
        return;
    }
    
    if(visited[state][xy[0][0]][xy[0][1]] != -1 && visited[state][xy[0][0]][xy[0][1]] <= time) return;


    visited[state][xy[0][0]][xy[0][1]] = time;
    int dirX1,dirX2,dirY1,dirY2;
    for(int i =0;i<4;i++){
        dirX1 = xy[0][0] + dir[i][0];
        dirY1 = xy[0][1] + dir[i][1];
        dirX2 = xy[1][0] + dir[i][0];
        dirY2 = xy[1][1] + dir[i][1];
        if(dirX1<0|| dirY1<0 || dirX1>= N||dirY1>=N) continue;
        if(dirX2<0|| dirY2<0 || dirX2>= N||dirY2>=N) continue;
        if(board[dirX1][dirY1] == 1 || board[dirX2][dirY2] == 1) continue;
        
        vector<vector<int> > temp ;
        vector<int> t;
        t.push_back(dirX1);
        t.push_back(dirY1);
        temp.push_back(t);
        t.clear();
        t.push_back(dirX2);
        t.push_back(dirY2);
        temp.push_back(t);
        move(temp,state,time+1);
    }

    if(canRotate1(xy,state)){
        int tempState = (state == 1 ? 2:1);
        int tempX1,tempY1,tempX2,tempY2;
        
        if(state == 1){
            tempX1 = xy[0][0];
            tempY1 = xy[0][1] + 1;
            tempX2 = xy[1][0];
            tempY2 = xy[1][1] + 1;
        }
        else{
            tempX1 = xy[0][0] + 1;
            tempY1 = xy[0][1];
            tempX2 = xy[1][0] + 1;
            tempY2 = xy[1][1];
        }
        vector<vector<int> > temp1;
        vector<vector<int> > temp2;
        vector<int> t;
        t.push_back(xy[0][0]);
        t.push_back(xy[0][1]);
        temp1.push_back(t);
        t.clear();
        t.push_back(tempX1);
        t.push_back(tempY1);
        temp1.push_back(t);
        t.clear();
        t.push_back(xy[1][0]);
        t.push_back(xy[1][1]);
        temp2.push_back(t);
        t.clear();
        t.push_back(tempX2);
        t.push_back(tempY2);
        temp2.push_back(t);
        move(temp1,tempState,time+1);
        move(temp2,tempState,time+1);
        
    }

    if(canRotate2(xy,state)){
        int tempState = (state == 1 ? 2:1);
        int tempX1,tempY1,tempX2,tempY2;
        
        if(state == 1){
            tempX1 = xy[0][0];
            tempY1 = xy[0][1] - 1;
            tempX2 = xy[1][0];
            tempY2 = xy[1][1] - 1;
        }
        else{
            tempX1 = xy[0][0] - 1;
            tempY1 = xy[0][1];
            tempX2 = xy[1][0] - 1;
            tempY2 = xy[1][1];
        }

        vector<vector<int> > temp1;
        vector<vector<int> > temp2;
        vector<int> t;
        t.push_back(tempX1);
        t.push_back(tempY1);
        temp1.push_back(t);
        t.clear();
        t.push_back(xy[0][0]);
        t.push_back(xy[0][1]);
        temp1.push_back(t);
        t.clear();

       
       
        t.push_back(tempX2);
        t.push_back(tempY2);
        temp2.push_back(t);
        t.clear();
        t.push_back(xy[1][0]);
        t.push_back(xy[1][1]);
        temp2.push_back(t);
        move(temp1,tempState,time+1);
        move(temp2,tempState,time+1);
        
    }

}


int solution(vector<vector<int>> boards) {
    board = boards;
    N = boards.size();
    memset(visited,-1,sizeof(visited));
    vector<vector<int> > xy;
    vector<int> t;
    t.push_back(0);
    t.push_back(0);
    xy.push_back(t);
    t.clear();
    t.push_back(0);
    t.push_back(1);
    xy.push_back(t);


    move(xy,2,0);

    return answer;
}





