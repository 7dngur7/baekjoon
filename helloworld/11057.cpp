#include <iostream>

using namespace std;

long long arr[1001][10]={};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    long long answer = 10;
    for(int i=0; i<10; i++){
        arr[1][i]=1;
    }

    for(int i=2; i<=n; i++){
        for(int j=1; j<10; j++){
            for(int k=1; k<=j; k++){
                //cout<<"k"<<k<<"\n";
                if(arr[i-1][k]>0){
                    arr[i][j]+= arr[i-1][k];
                    arr[i][j]%= 10007;
                    answer+= arr[i-1][k]%10007;
                    //cout<<"ijk:"<<i<<" "<<j<<" "<<k<<"\n";
                }
            }
        }
        answer = answer%10007;
    }


    // for(int i=1; i<=n; i++){
    //     for(int j=0; j<10; j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<"\n";

    // }
    cout<<answer;

}