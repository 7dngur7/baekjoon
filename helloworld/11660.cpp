#include <iostream>
#include <vector>

using namespace std;

int arr[1500][1500]={};
int xPlusArr[1500][1500]={};
int yPlusArr[1500][1500]={};


vector<pair<int,int> > xyarr;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=n; j++){
            cin>>arr[i][j];
        }
    }

    int xPlus = 0;
    int yPlus = 0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=n; j++){
            xPlus += arr[i][j];
            xPlusArr[i][j] = xPlus;

            yPlus += arr[j][i];
            yPlusArr[j][i] = yPlus;
        }
    }


    for(int i=0; i<m; i++){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        xyarr.push_back(make_pair(a,b));
        xyarr.push_back(make_pair(c,d));
    }

    for(int i=0; i<m; i++){
        pair<int,int> startPair, endPair;

        startPair = xyarr[2*i];
        endPair = xyarr[2*i+1];

        int ans = xPlusArr[endPair.first][endPair.second]
                + xPlusArr[startPair.first-1][startPair.second];

    }


}