    #include <string>
    #include <vector>
    #include <queue>
    #include <cstdio>
    #include <iostream>
    #include<algorithm>

    using namespace std;
    vector<vector<int> > board;
    int dir[5][2] = {
        {0,0},
        {0,1},
        {0,2},
        {1,1},
        {1,2}
    };

    int findY(int X){
        int i;
        for(i=0;i<board.size();i++){
            if(board[i][X] != 0)
                break;
        }
        return i-1;
    }
    int checkY(int X){
        int i;
        for(i=0;i<board.size();i++){
            if(board[i][X] != 0)
                break;
        }
        return i;
    }

    bool check(int dir, int Y, int X){
        
        //세로로 긴
        if(dir == 0 ||dir ==3){
            if(Y+2>=board.size())
                return false;
            int num = board[Y+2][X];
            for(int i =Y;i<Y+3;i++){
                for(int j = X;j<X+2;j++){
                    if(board[i][j] == 0)
                        return false;
                    if(board[i][j] == -1)
                        continue;
                    if(board[i][j] != num)
                        return false;
                }
            }
        }
        //가로체크
        else{
            if(Y+1 >=board.size())
                return false;
            int num = board[Y+1][X];
            for(int i =Y;i<Y+2;i++){
                for(int j = X;j<X+3;j++){
                    if(board[i][j] == 0)
                        return false;
                    if(board[i][j] == -1)
                        continue;
                    if(board[i][j] != num)
                        return false;
                    
                }
            }

        }
        return true;

    }

    void removeBlock(int dir, int Y, int X){
        
        //세로로 긴
        if(dir == 0 ||dir ==3){
            for(int i =Y;i<3+Y;i++){
                for(int j = X;j<2+X;j++){
                    board[i][j] = 0;
                }
            }
        }
        //가로체크
        else{
            for(int i =Y;i<2+Y;i++){
                for(int j = X;j<3+X;j++){
                    board[i][j] = 0;
                }
            }

        }
    }

    bool drop(int X){  
        for(int i =0;i<5;i++){
            int Y = 51;
            queue<pair<int,int> > q; 
            for(int j =0;j<2;j++){
                int dirX = X+dir[i][j];
                int dirY = findY(dirX);
                Y = min(dirY,Y);
                if(dirX>=board[0].size() || dirY<0) break;
                board[dirY][dirX] = -1;
                q.push(make_pair(dirY,dirX));
            }
            if(q.size() == 2){
                if(check(i,Y,X)){
                    removeBlock(i,Y,X);
                    return true;
                }
            }
            while(!q.empty()){
                int dirY = q.front().first;
                int dirX = q.front().second;
                board[dirY][dirX] = 0;
                q.pop();
            }
        }
        return false;
        

    }

    void printBoard(){
        for(int i =0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                printf("%d ",board[i][j]);
            }
            printf("\n");
        }
    }



    int solution(vector<vector<int> > b) {
        board = b;

        int answer = 0;
        int i = 0;
        while(true){
            for(i =0;i<board.size();i++){
                //cout<<i<<endl;
                if(drop(i)){
                    answer++;
                    break;
                }
                //printBoard();
            }
            if(i == board.size())
                break;
        }

        return answer;
    }


int main(){
    int arr[10][10] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,4,0,0,0},
        {0,0,0,0,0,4,4,0,0,0},
        {0,0,0,0,3,0,4,0,0,0},
        {0,0,0,2,3,0,0,0,5,5},
        {1,2,2,2,3,3,0,0,0,5},
        {1,1,1,0,0,0,0,0,0,5}
        };
        vector<vector<int> > b;
        
        for(int i =0;i<10;i++){
            vector<int> temp;
            for(int j =0;j<10;j++){
                temp.push_back(arr[i][j]);
            }
            b.push_back(temp);
        }
        cout<<solution(b)<<endl;


}
