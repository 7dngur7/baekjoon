#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10005]={};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;

    int n, k;

    cin>>n>>k;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    arr[0]=0;

    for(int i=1; i<=k; i++ ){
        int best = -1;

        for(int j=0; j<n; j++){
            if(i-v[j]>=0 && best<0 && arr[i-v[j]]>=0){
                best = arr[i-v[j]]+1;
            }
            else if(i-v[j]>=0 && best>arr[i-v[j]]&& arr[i-v[j]]>=0){
                best = arr[i-v[j]]+1;
            }

        }
        //cout<<"best: "<<best<<"\n";
        arr[i] = best;


    }

    cout<<arr[k]<<"\n";
}