#include <iostream>

using namespace std;

int N;
int ans;
int cache[101][101] = {-1};

int making_poly(int remain, int post){
    //cout<<remain<<" " << post<<endl;
    if (remain == 0){
        return 1;
    }
    if(cache[remain][post] != -1) return cache[remain][post];

    cache[remain][post] = 0;
    for (int i = 1; i <= remain; i++){
        int add = post + i -1;
        add *= making_poly(remain - i, i);
        add = add%10000000;
        cache[remain][post] += add;
        cache[remain][post] %= 10000000;
    }
    return cache[remain][post];
}

int main()
{

    cin >> N;
    memset(cache,-1,sizeof(cache));

    for(int i =1;i<=N;i++){
        ans+= making_poly(N-i,i);
        ans %= 10000000;
    }
    cout << ans;

    return 0;
}