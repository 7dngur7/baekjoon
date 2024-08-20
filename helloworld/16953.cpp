#include <iostream>
#include <queue>

using namespace std;

int arr[1000001]={};
queue<int> q;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin>>a>>b;

    arr[a]=0;
    q.push(a);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i=0; i<2; i++){
            int xcur;
            if(i==0){
                xcur = cur*10 +1;
            }
            else{
                xcur = cur*2;
            }

            if(xcur>b)continue;
            if(arr[xcur]!=0 && arr[xcur]<=arr[cur]+1)continue;

            arr[xcur]= arr[cur]+1;
            q.push(xcur);
            
            //cout<<xcur<<" "<<arr[xcur]<<"\n";

        }
    }

    if(arr[b]==0){
        cout<<"-1\n";
    }
    else{
        cout<<arr[b]+1<<"\n";
    }


}