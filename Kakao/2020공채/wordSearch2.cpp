#include <string>
#include <vector>

using namespace std;

#define nodeNum 27


int getIndex(char c){
    if(c=='?') return 26;
    return c-'a';
}



struct Trie{
    
        Trie* node[nodeNum];
        bool finish;
        int cnt;
    
        Trie(){
            finish = false;
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

        void add(const char* query,int depth){
            if(*query == 0){
                finish = true;
                return; 
            }
            char c = *query;
            //char c = query[depth];
            int index = getIndex(c);
            if(node[index] == nullptr){
                node[index] = new Trie();
            }
            node[index]->add(query+1,depth+1);
        }

        void find(const char* key,int depth){
            if(*key == 0){
                if(finish) cnt++;
                return ;
            }
            char c = *key;
            //char c = key[depth];
            int index = getIndex('?');
            if(node[index] != nullptr){
                node[index]->find(key+1,depth+1);
            }
            
            index = getIndex(c);
            if(node[index] != nullptr){
                node[index]->find(key+1,depth+1);
            }

        }

        int getCnt(const char* key,int depth){
            if(*key == 0){
                return cnt;
            }
            char c = *key;
            //char c = key[depth];
            int index = getIndex(c);
            return node[index]->getCnt(key+1,depth+1);
        }
        


};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    Trie trie;
    for (int i = 0; i < queries.size(); ++i)
    {
        trie.add(queries[i].c_str(),0);
    }

    for (int i = 0; i < words.size(); ++i)
    {
        trie.find(words[i].c_str(),0);
    }

    for (int i = 0; i < queries.size(); ++i)
    {
        answer.push_back(trie.getCnt(queries[i].c_str(),0));
    }


    return answer;
}