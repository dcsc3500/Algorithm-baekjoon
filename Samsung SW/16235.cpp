#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int N, M, K;
int arr[11][11];
int vitamin[11][11];

struct Tree
{
    int x, y, age;
};

struct cmp
{
    bool operator()(Tree t1, Tree t2)
    {
        return t1.age > t2.age;
    }
};

priority_queue<Tree, vector<Tree>, cmp> trees;
vector<Tree> dead;

void spring()
{
    vector<Tree> oldTree;
    oldTree.reserve(10000);
    int s = trees.size();
    for (int i = 0; i < s; i++)
    {
        Tree temp = trees.top();
        trees.pop();
        int x = temp.x - 1;
        int y = temp.y - 1;
        int age = temp.age;

        if (arr[x][y] >= age)
        { // 양분이 더작다면
            arr[x][y] -= age;
            age++;
            x++;
            y++;
            temp.x = x;
            temp.y = y;
            temp.age = age;
            oldTree.push_back(temp);
        }
        else
        {
            dead.push_back(temp);
        }
    }

    for(int i =0;i<oldTree.size();i++){
        trees.push(oldTree[i]);
    }
}

void summer()
{
    for (int i = 0; i<dead.size(); i++)
    {
        Tree temp = dead[i];
        int x = temp.x - 1;
        int y = temp.y - 1;
        int age = temp.age;

        arr[x][y] += (age / 2);
    }
    dead.clear();
}

void autum()
{
    int dir[8][2] = {
        {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}
    };
    vector<Tree> newTree;
    newTree.reserve(10000);
    vector<Tree> oldTree;
    oldTree.reserve(10000);
    int s = trees.size();
    for (int i = 0; i < s; i++)
    {
        Tree temp = trees.top();
        trees.pop();
        if (temp.age % 5 == 0)
        {
            int x = temp.x - 1;
            int y = temp.y - 1;
            
            for(int j = 0;j<8;j++){
                int dirX = x + dir[j][0];
                int dirY = y + dir[j][1];
                if(dirX<0 || dirX>=N || dirY <0 || dirY >=N)
                    continue;
                Tree pushTree = {dirX+1,dirY+1,1};
                newTree.push_back(pushTree);
            }
        }
        oldTree.push_back(temp);
    }

    for(int i =0;i<newTree.size();i++){
        trees.push(newTree[i]);
    }
    for(int i =0;i<oldTree.size();i++){
        trees.push(oldTree[i]);
    }

}

void winter(){
    for(int i =0;i<N;i++){
        for(int j =0;j<N;j++){
            arr[i][j] += vitamin[i][j];
        }
    }
}

int main()
{

    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &vitamin[i][j]);
            arr[i][j] = 5;
        }
    }

    for (int i = 0; i < M; i++)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        Tree pushTree = {x,y,z};
        trees.push(pushTree);
    }
    for(int i =0;i<K;i++){
        spring();
        summer();
        autum();
        winter();
    }

    cout<<trees.size()<<endl;

    return 0;
}