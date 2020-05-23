#include <vector>
#include <iostream>

using namespace std;
vector<int> v2;

int main(){
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v2 = v1;

    cout<< v2[1]<<endl;

}