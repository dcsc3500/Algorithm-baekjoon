#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>


using namespace std;

struct item{
  string s;
  int size,level;
};



int cache[101][1001] = {-1};
bool check[101] = {false};
vector<item> items;
int N;


int dp(int item, int capacity,int sum){
  if(item == N){
    return sum;
  }
  int &ret = cache[item][capacity];
  
  if(ret != -1) return ret;


  ret = dp(item+1, capacity,sum);
  
  if(capacity - items[item].size >=0)
    ret = max(ret,dp(item+1, capacity - items[item].size,sum + items[item].level) ) ;

  return ret;

}

int dp2(int item, int capacity){
  if(item == N){
    return 0;
  }
  int &ret = cache[item][capacity];
  
  if(ret != -1) return ret;


  ret = dp2(item+1, capacity);
  
  if(capacity - items[item].size >=0)
    ret = max(ret,dp2(item+1, capacity - items[item].size)+ items[item].level ) ;

  return ret;

}

void printCache(int W){
  for(int i =0;i<N;i++){
    for(int j =0;j<=W;j++){
      printf("%3d",cache[i][j]);
    }
    printf("\n");
  }
  
}

int main(){
    int C;
    scanf("%d",&C);

    for(int c = 0;c<C;c++){
      int W;
      items.clear();
      memset(check,false,sizeof(check));
      memset(cache,-1,sizeof(cache));
      scanf("%d %d",&N,&W);
      for(int i =0;i<N;i++){
        string s;
        int size, level;
        cin>>s>>size>>level;
        item temp = {s,size,level};
        items.push_back(temp);
      }
      dp2(0,W);
      //dp(0,W,0);
      printCache(W);
      
      printf("\n");
      printf("%d",cache[0][W]);

    }
    

    return 0;
}


/*
1
6 10
laptop 4 7
camera 2 10
xbox 6 6
grinder 4 7
dumbell 2 5
encyclopedia 10 4
*/