#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
struct myStruct {
    unordered_map<char, myStruct*> map;
    bool done = false;
    int cnt;
};

unordered_map<char, myStruct*> frontTrie;


void makingTrie(unordered_map<char, myStruct*>& trie, string& query, int depth) {
    if (query.size() == depth) {
        if(trie.find(0) == trie.end()){
            myStruct *temp = new myStruct;
            temp->done = true;
            temp->cnt = 0;
            trie[0]=temp;
        }
        return;
    }
    char c = query.at(depth);
    auto it = trie.find(c);
    //trie가 존재
    if (it != trie.end()) {
        makingTrie(trie.find(c)->second->map, query, depth + 1);
    }
    else {
        myStruct* temp = new myStruct;
        trie.insert(make_pair(c, temp));
        makingTrie(trie.find(c)->second->map, query, depth + 1);

    }
}


void findWord(unordered_map<char, myStruct*>& trie, string& word, int depth) {
    if (word.size() == depth) {
        if(trie.find(0) != trie.end()){
             if (trie[0]->done) {
                trie[0]->cnt++;
            }
        }
        return;
    }
    char c = word.at(depth);

    auto it = trie.find(c);
    
    if (it != trie.end()) {
        findWord(trie.find(c)->second->map, word, depth + 1);
    }

    it = trie.find('?');

    if (it != trie.end()) {
        findWord(trie.find('?')->second->map, word, depth + 1);
    }

}

int getAnswer(unordered_map<char, myStruct*>& trie, string& query, int depth) {
    if (query.length() == depth) {
        return trie[0]->cnt;
    }
    char c = query.at(depth);
    auto it = trie.find(c);
    return getAnswer(trie.find(c)->second->map, query, depth + 1);


}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    for (int i = 0; i < queries.size(); i++) {
        string query = queries[i];
        makingTrie(frontTrie, query, 0);
    }
    


    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        findWord(frontTrie, word, 0);
    }

    for (int i = 0; i < queries.size(); i++) {
        string query = queries[i];
        int num = getAnswer(frontTrie, query, 0);
        answer.push_back(num);
    }



    return answer;
}