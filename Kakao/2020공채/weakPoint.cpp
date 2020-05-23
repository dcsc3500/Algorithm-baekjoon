#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

vector<int> weaks;
vector<int> dists;
vector<int> q;
int sizeDist;
int N;
int answer = 999999;

int letCheck(){
    int ans;
    
    int i = 0;
    for(ans = 0;ans<dists.size();ans++){
        int canMove = dists[ans] + q[i];
        while(canMove >= q[i]){
            //console.log(ans,i)
            i++;
            if(i>=q.size()){
                return ans+1;
            } 
        }

    }  
    return 999999;

}

void makePermutation(int depth){
    if(depth == sizeDist){
        answer = min(answer,letCheck());
        return;
    }
    for(int i =depth;i<dists.size();i++){
        swap(dists[i],dists[depth]);
        makePermutation(depth+1);
        swap(dists[i],dists[depth]);
    }


}

void makeQ(int start){
    for(int i =start;i<weaks.size();i++){
        q.push_back(weaks[i]);
    }
    for(int i = 0;i<start;i++){
        q.push_back(weaks[i]+N);
    }
    //console.log(q)
}

int solution(int n, vector<int> weak, vector<int> dist) {
     N = n;
    weaks = weak;
    dists = dist;
    sizeDist = dists.size();
    for(int i =0;i<weaks.size();i++){
        q.clear();
        makeQ(i);
        makePermutation(0);
    }

    if(answer == 999999) answer = -1;

    return answer;
}

int main(){
    vector<int> weak;
    vector<int> dist;
    int n = 12;

    weak.push_back(1);
    weak.push_back(5);
    weak.push_back(6);
    weak.push_back(10);
    dist.push_back(1);
    dist.push_back(2);
    dist.push_back(3);
    dist.push_back(4);
    
    cout<<solution(n,weak,dist)<<endl;


    return 0;
}

