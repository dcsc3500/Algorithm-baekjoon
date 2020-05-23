#include <cstdio>

using namespace std;

int N, M, x, y, k;
int map[21][21];
int dice[7];
int dir[4][2] = {
    {0, 1},
    {0, -1},
    {-1, 0},
    {1, 0}};

void move(int t)
{
    t--;
    if (x + dir[t][0] < 0 || x + dir[t][0] >= N || y + dir[t][1] < 0 || y + dir[t][1] >= M)
        return;

    x += dir[t][0];
    y += dir[t][1];
    
    int temp = dice[1];

    if(t == 0){
        dice[1] = dice[4];
        dice[4] = dice[6];
        dice[6] = dice[3];
        dice[3] = temp;
    }
    else if (t == 1){
        dice[1] = dice[3];
        dice[3] = dice[6];
        dice[6] = dice[4];
        dice[4] = temp;

    }
    else if(t == 2){
        dice[1] = dice[5];
        dice[5] = dice[6];
        dice[6] = dice[2];
        dice[2] = temp;
    }
    else if(t == 3){
        dice[1] = dice[2];
        dice[2] = dice[6];
        dice[6] = dice[5];
        dice[5] = temp;
    }

    if(map[x][y] != 0 ){
        dice[6] = map[x][y];
        map[x][y] = 0;
    }
    else{
        map[x][y] = dice[6];
    }

    printf("%d\n",dice[1]);

}

int main()
{
    scanf("%d %d %d %d %d", &N, &M, &x, &y, &k);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }

    for (int i = 0; i < k; i++)
    {
        int t;
        scanf("%d", &t);
        move(t);
    }

    return 0;
}