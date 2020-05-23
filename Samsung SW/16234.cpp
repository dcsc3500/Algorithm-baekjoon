#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;


queue<pair<int,int>> q;

int N,L,R;

int map[51][51];

int dir[4][2] = {
    {-1,0},
    {0,1},
    {1,0},
    {0,-1}
};

int main(){
    cin>>N>>L>>R;

    for(int i =0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&map[i][j]);
        }
    }

    while(true){
       
    }

    return 0;
}