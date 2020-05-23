#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<long long,long long> map;
vector<long long> answer;
long long K;


long long getRoom(long long room){

    if(map.find(room) == map.end()){
        
        map[room] = (room+1) % (K+1);
        answer.push_back(room);
        return map[room];
    }
    else{
        return map[room] = getRoom(map[room]);
    }

}


vector<long long> solution(long long k, vector<long long> room_number) {
    K = k;

    for(int i =0;i<room_number.size();i++){
        map[room_number[i]] = getRoom(room_number[i]);
    }


    return answer;
}