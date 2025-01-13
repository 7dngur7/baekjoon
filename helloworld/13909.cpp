#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    if(n==1){
        cout<<"1\n";
        return 0;
    }
    
    int ans = 0;

    int cur = 1;
    for(int i = 1; i<=n; i++){
        if(i*i>n){
            cout<<ans<<"\n";
            return 0;
        }

        ans++;
    }
}