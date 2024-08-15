#include <iostream>
#include <vector>

using namespace std;
int v[2002]={};
int arr[2002][2002]={};
int chkarr[2002][2002]={};

int func(int i, int j){
    if(i<=j){
        if (chkarr[i][j]) return arr[i][j]; 

        chkarr[i][j]=1;

        if(i==j){
            arr[i][j]=1;
        }
        else if(abs(i-j)==1){
            if(v[i]==v[j]){
                arr[i][j]=1;
            }
        }
        else{
            if(v[i]==v[j]){
                if(chkarr[i+1][j-1]==1){
                    arr[i][j]=arr[i+1][j-1];
                }
                else{
                    int result = func(i+1,j-1);
                    arr[i][j]=result;
                }
            }
        }
    }
    return arr[i][j];
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>v[i];
    }

    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            func(i,j);
        } 
    }




    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout<<arr[i][j]<<" ";
    //     } 
    //     cout<<"\n";
    // }


    int m;
    cin>>m;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;

        cout<<arr[a][b]<<"\n";



    }
}