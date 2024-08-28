#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int arr[50001][10]={};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string strn;
    cin>>strn;

    long n = (long)stoi(strn);

    if(strn[0]=='0'){
        cout<<0<<"\n";
        return 0;
    }

    for(int i=1; i<10; i++){
        arr[0][i]=1;
    }

    for(int i=10; i<=n; i++){
        int onenum = i%10;
        int tennum = (i%100)/10;
        int hundrednum = (i%1000)/100;

        if(tennum==2&&onenum<=6){
            arr[i/10][i%10]=(arr[i/10-1][i%10]+arr[i/10-2][hundrednum])%1000000;

        }
        else if(tennum==1){
            arr[i/10][i%10]=(arr[i/10-1][i%10]+arr[i/10-2][hundrednum])%1000000;
        }
        else{
            arr[i/10][i%10]= arr[i/10-1][i%10];
        }
    }

    for(int i=0; i<50; i++){
        for(int j=0; j<10; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<arr[n/10][n%10]<<"\n";
}