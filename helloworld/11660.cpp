#include <iostream>
#include <vector>

using namespace std;

int arr[1500][1500]={};


vector<pair<int,int> > xyarr;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<=n; j++){
            arr[i][j] += arr[i-1][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<=n; j++){
            arr[i][j] += arr[i][j-1];
        }
    }

    for(int i=0; i<m; i++){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;

        cout<<""<< arr[x2][y2] - arr[x2][y1-1] - arr[x1-1][y2] + arr[x1-1][y1-1]<<"\n";
    }


}