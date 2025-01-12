#include <iostream>

using namespace std;

int arr[1005] = {};
int uparr[1005]= {};
int downarr[1005] = {};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
        uparr[i] = 1;
        downarr[i] = 1;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[i]>arr[j]){
                uparr[i] = max(uparr[i], uparr[j]+1);
            }
        }
    }

    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>i; j--){
            if(arr[i]>arr[j]){
                downarr[i] = max(downarr[i], downarr[j]+1);
            }
        }
    }

    // for(int i=0; i<n; i++){
    //     cout<<uparr[i]<<" ";
    // }
    // cout<<"\n";

    // for(int i=0; i<n; i++){
    //     cout<<downarr[i]<<" ";
    // }
    // cout<<"\n";

    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, uparr[i] + downarr[i]);
    }
    cout<<ans-1<<"\n";
}