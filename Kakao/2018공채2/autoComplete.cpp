#include <string>
#include <iostream>
#include <vector>

using namespace std;

#define nodeNum 27


int getIndex(char c){
    return c-'a';
}



struct Trie{
    
        Trie* node[nodeNum];
        int cnt;
    
        Trie(){
            cnt = 0;
            for(int i =0;i<nodeNum;i++){
                node[i] = nullptr;
            }
        }
        ~Trie(){
            for(int i =0;i<nodeNum;i++){
                if(node[i])
                    delete node[i];
            }
        }

        void add(const char* query){
            if(*query == 0){
                return; 
            }
            char c = *query;
            //char c = query[depth];
            int index = getIndex(c);
            if(node[index] == nullptr){
                node[index] = new Trie();
            }
            node[index]->cnt++;
            node[index]->add(query+1);
        }

        int find(const char* key,int depth){
            char c = *key;
            //char c = key[depth];
            int index = getIndex(c);
            if(*key == 0){
                return depth; 
            }
            if(cnt == 1) return depth;
            if(node[index] != nullptr){
                return node[index]->find(key+1,depth+1);
            }

        }


};

int solution(vector<string> words) {
    int answer = 0;
    Trie trie;
    for(int i =0;i<words.size();i++){
        string word = words[i];
        trie.add(word.c_str());
    }

    for(int i =0;i<words.size();i++){
        string word = words[i];
        answer += trie.find(word.c_str(),0);
    }



    return answer;
}

int main(){


    vector<string> temp;

    temp.push_back("go");
    temp.push_back("gone");
    temp.push_back("guild");

    cout<<solution(temp)<<endl;

    return 0;
}