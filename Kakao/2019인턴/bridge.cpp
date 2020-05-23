#include <string>
#include <vector>

using namespace std;
vector<int> stones;
int k;

bool isPossible(int middle){
    int cnt = 0;
    for(int i =0;i<stones.size();i++){
            if(stones[i] - middle <0) cnt++;
            else cnt = 0;
            if(cnt>= k){
                return false;
            }
    }
    return true;
}

int binSearch(int l, int r){
    int middle;
    while(l<=r){
        middle = (l+r)/2;
        if(isPossible(middle)){
            l = middle+1;
        }
        else{
            r= middle-1;
        }
    }
    return l;
}

int solution(vector<int> stoness, int K) {
    int answer = 0;
    stones = stoness;
    k = K;

    answer = binSearch(1,200000000);

    return answer;
}