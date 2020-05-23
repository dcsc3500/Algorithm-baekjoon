#include <cstdio>
#include <algorithm>

using namespace std;

bool check[102];
int dice[10];
int ans;

int map[4][100] ={
    {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20},
    {0,1,2,3,4,5,21,22,23,24,30,31,20},
    {0,1,2,3,4,5,6,7,8,9,10,25,26,24,30,31,20},
    {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,27,28,29,24,30,31,20}
};
int score[4][100] = {
    {0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40}, //21
    {0,2,4,6,8,10,13,16,19,25,30,35,40},//13
    {0,2,4,6,8,10,12,14,16,18,20,22,24,25,30,35,40},//16
    {0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,28,27,26,25,30,35,40}//23
};
int mal[4][2];

void go(int cnt,int sum){
    if(cnt == 10){
        if(sum>ans)
            ans = sum;
        return;
    }
    int num = dice[cnt];
    for(int i =0;i<4;i++){
        int tempA = mal[i][0];
        int tempB = mal[i][1];
        int tempIndex = map[mal[i][0]][mal[i][1]];
        mal[i][1] += num;
        int index = map[mal[i][0]][mal[i][1]];
        
        if(check[index] && index != 0){
            mal[i][1] -= num;
            continue;
        }
        
        if((mal[i][1]==5|| mal[i][1]== 10 || mal[i][1]== 15) && mal[i][0] == 0){
            
            mal[i][0] += (mal[i][1]/5);

        }

        check[index] = true;
        check[tempIndex] = false;
        go(cnt+1,sum + score[mal[i][0]][mal[i][1]]);
        check[index] = false;
        check[tempIndex] = true;
        mal[i][0] = tempA;
        mal[i][1] = tempB;
    }

}

int main(){
    int num;
    for(int i =0;i<10;i++){
        scanf("%d",&dice[i]);
    }
    go(0,0);

    printf("%d\n",ans);
    return 0;
}