#include <cstdio>
#include <iostream>

using namespace std;

int arr[1000001];
long long ans = 0;
int N,B,C;

int main(){
    
    
    cin>>N;
    for(int i =0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    cin>>B>>C;

    for(int i =0;i<N;i++){
        arr[i] -= B;
        ans++;

        if(arr[i]>0){
            if(arr[i] % C == 0)
                ans += (arr[i] / C);
            else
                ans += (arr[i] / C) +1;
        }
    }

    cout<<ans<<endl;

    return 0;
}