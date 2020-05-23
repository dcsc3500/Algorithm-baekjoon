#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<vector<int> > bans;
bool check[8] = {false};
int answer = 0;
int userSize;
unordered_map<string,bool> map;

bool isSame(string ban,string user){
    if(ban.size() != user.size()) return false;
    
    for(int i =0;i<ban.size();i++){
        char bc = ban.at(i);
        char uc = user.at(i);
        if(bc == '*') continue;
        if(bc != uc) return false;
    }
    //<<ban<<endl;
    return true;

}


void selects(int depth){
    if(depth == bans.size()){
        
        string num = "";
        for(int i =userSize-1;i>=0;i--){
            if(check[i]){
                string ss = to_string(i);
                num += ss;
            }
        }
        //cout<< num<<endl;
        if(map.find(num) == map.end()){
            answer++;
            map.insert({num,true});
        }
        return;
    }
    
    vector<int> temp = bans[depth];

    for(int i =0;i<temp.size();i++){
        int index = temp[i];
        if(!check[index]){
            check[index] = true;
            selects(depth+1);
            check[index] = false;
        }
    }

}



int solution(vector<string> user_id, vector<string> banned_id) {
    userSize = user_id.size();

    for(int i =0;i<banned_id.size();i++){
        string banid = banned_id[i];
        //cout<<banid<<endl;
        vector<int> tempban;
        for(int j =0;j<user_id.size();j++){
            string userid = user_id[j];
            
            if(isSame(banid,userid)){
                tempban.push_back(j);
            }
        }
        bans.push_back(tempban);
        tempban.clear();
    }
    
    selects(0);


    return answer;
}