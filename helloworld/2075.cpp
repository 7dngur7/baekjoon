#include <iostream>
#include <algorithm>

using namespace std;

int a[2250001];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    for(int i=0; i<n*n; i++){
        cin>>a[i];

    }

    sort(a, a+n*n);

        cout<<a[n*n-n]<<"\n";

}