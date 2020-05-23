#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

int N, M, T;
int arr[52][52];
queue<pair<int, int> > q;
int sum, cnt;

void printA()
{
    printf("\n");
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
}

void rotate(int x, int d, int k)
{
    queue<int> rotateQ;
    //시계방향 회전

    for (int i = 0; i < M; i++)
    {
        rotateQ.push(arr[x][i]);
    }
    if (d == 0)
    {
        int index = 0;
        while (!rotateQ.empty())
        {
            int num = rotateQ.front();
            rotateQ.pop();
            arr[x][(index + k) % M] = num;
            index++;
        }
    }

    //반시계방향 회전
    else
    {
        int index = 0;
        while (!rotateQ.empty())
        {
            int num = rotateQ.front();
            rotateQ.pop();
            arr[x][(index + M - k) % M] = num;
            index++;
        }
    }
}

void check()
{
    int dir[4][2] = {
        {-1, 0}, {0, 1}, {1, 0}, {0, M - 1}};
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            bool state = false;
            if (arr[i][j] == -1)
                continue;
            for (int k = 0; k < 4; k++)
            {
                int dirX = i + dir[k][0];
                int dirY = j + dir[k][1];
                dirY = dirY % M;

                if (arr[dirX][dirY] == -1)
                    continue;
                if (dirX <= 0 || dirY < 0 || dirX > N || dirY >= M)
                    continue;
                if (arr[i][j] == arr[dirX][dirY])
                {
                    q.push(make_pair(dirX, dirY));
                    state = true;
                }
            }
            if (state)
                q.push(make_pair(i, j));
        }
    }
}

void getSum()
{
    int temp = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == -1)
                continue;

            temp += arr[i][j];
        }
    }

    sum = temp;
}

void changeVal(double avg)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == -1)
                continue;

            if (avg < arr[i][j])
                arr[i][j] -= 1;
            else if (avg > arr[i][j])
                arr[i][j] += 1;
        }
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &T);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &arr[i][j]);
            cnt++;
        }
    }
    //printA();
    for (int i = 0; i < T; i++)
    {
        int x, d, k;
        scanf("%d %d %d", &x, &d, &k);
        int besu = x;
        while (true)
        {
            if (besu > N)
                break;
            rotate(besu, d, k);
            besu += x;
        }
        //printA();

        check();
        //평균값 마이너스 1
        if (q.empty())
        {
            getSum();
            double avg = (double)sum / cnt;
            changeVal(avg);
        }
        else
        {
            while (!q.empty())
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if (arr[x][y] == -1)
                    continue;
                arr[x][y] = -1;
                cnt--;
            }
        }
        //printA();
    }

    getSum();

    printf("%d", sum);

    return 0;
}