#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


vector<int> coin;

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);
int arr[10005]={};

    int n, k;

    cin>>n>>k;
    for(int i=0; i<n; i++){
        int coinnum;
        cin>>coinnum;
        coin.push_back(coinnum);
    }
    sort(coin.begin(), coin.end());

    for(int i=0; i<=k; i++){
        if(i%coin[0]==0){
            arr[i] = 1;
        }
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<=k;j++){
            if(j-coin[i]>=0){
                //cout<<"test: "<<arr[j]<<" "<<arr[j-coin[i]]<<"\n";
                arr[j]= arr[j]+ arr[j-coin[i]];
               // cout<<j<< " "<<arr[j]<<"\n";
            }
        }
        
    }

    cout<<arr[k]<<"\n";
}