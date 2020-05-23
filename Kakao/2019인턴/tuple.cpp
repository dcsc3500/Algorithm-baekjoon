    #include <string>
    #include <vector>
    #include <algorithm>
    #include <unordered_map>
    #include <iostream>
    using namespace std;

    unordered_map<int,bool> map;

    bool comp(vector<int> &a, vector<int> &b){
        return a.size()<b.size();
    }

    vector<vector<int> > split(string &s){
        vector<vector<int> > ret;
        vector<int> temp;
        int num = 0;
        for(int i =0;i<s.size();i++){
            char c = s.at(i);
            if(c == ','){
                if(num>0){
                    temp.push_back(num);
                    num = 0;
                }
                continue;
            }
            if(c == '{') continue;
            if(c == '}'){
                temp.push_back(num);
                num = 0;
                ret.push_back(temp);
                temp.clear();
                continue;
            }
            num = num*10 + (c-'0');
            //cout<< c<< " ";
            
        }
        
        return ret;

    }

    vector<int> solution(string s) {
        vector<int> answer;

        string temp = s.substr(1,s.size()-2);
        //cout<<temp<<endl;
        vector<vector<int> > spliter = split(temp);
        
        sort(spliter.begin(),spliter.end(),comp);


        answer.clear();
        for(int i =0;i<spliter.size();i++){
            for(int j=0;j<spliter[i].size();j++){
                int num = spliter[i][j];
                if(map.find(num) == map.end()){
                    map.insert(make_pair(num,true));
                    answer.push_back(num);
                }
            }
        }
        
        
        return answer;
    }