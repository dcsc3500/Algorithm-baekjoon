#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const pair<int,int> &p1, const pair<int,int> &p2){
    if(p1.first == p2.first) return p1.second < p2.second;
    else
        return p1.first < p2.first;
}

void print(vector<pair<int,int> > v){
    for(int i =0;i<v.size();i++){
        printf("%d %d\n",v[i].first,v[i].second);
    }

}

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    vector<pair<int,int> > copy;
    long long total = 0;
    
    for(int i =0;i<food_times.size();i++){ 
        total += food_times[i];
        copy.push_back(make_pair(food_times[i],i+1) );
    }

    if(total <= k) return -1;

    sort(copy.begin(),copy.end(),comp);
    //print(copy);
    
    int lastTime = 0;
    
    for(int i =0;i<copy.size();i++){
        int len = copy.size()-i;
        lastTime = copy[i].first;
        int sub = len * (copy[i].first - (i == 0 ? 0 : copy[i-1].first));
        if(k-sub>=0){
            k = k- sub;
        }
        else{
            int temp = k/sub;
            k = k - (len*temp);
            break;
        }
    }

    printf("%d %lld\n",lastTime,k);
    for(answer =0;answer<food_times.size();answer++){
        if(lastTime>food_times[answer]) continue;
        k--;
        if(k<=0) break;
        
    }



    return answer+1;
}

int main(){
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    
    long long k = 10;
    printf("%d\n",solution(v,k));
    //vector<pair<int, int> > v2;
    //v2.push_back({1,2});

}