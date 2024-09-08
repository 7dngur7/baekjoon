#include <iostream>
#include <queue>

using namespace std;

int cost[3][1001]={};

pair<int,int> pairarr[3][1001]={};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>cost[0][i]>>cost[1][i]>>cost[2][i];
    }

    int ans;

    for(int k=0; k<3; k++){
        int arr[3][1001]={};

        for(int i=0; i<3; i++){
            if(i==k){
                arr[i][0]= cost[i][0];
            }
            else{
                arr[i][0]=1000002;
            }
        }

        for(int i=1; i<n; i++){
            arr[0][i] = min(arr[1][i-1], arr[2][i-1])+cost[0][i];
            arr[1][i] = min(arr[0][i-1], arr[2][i-1])+cost[1][i];
            arr[2][i] = min(arr[0][i-1], arr[1][i-1])+cost[2][i];
        }

        if(k==0){
            ans = min(arr[1][n-1], arr[2][n-1]);
        }
        else if(k==1){
            ans = min(min(arr[0][n-1], arr[2][n-1]),ans);
        }
        else{
            ans = min(min(arr[0][n-1], arr[1][n-1]),ans);
        }

    }
    cout<<ans<<"\n";
}