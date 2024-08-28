#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int G, P, arr[100002]={}, numarr[100002]={} , answer =0;

    cin>>G>>P;

    for(int i=0;i<P;i++){
        cin>>numarr[i];
    }

    for(int i=0;i<P;i++){
        int a = numarr[i];
        while(a>0){
            if(arr[a]==0){
                arr[a]++;
                break;
            }
            else{
                int b = arr[a];
                arr[a]++;
                a-=b;
            }
        }
        if(a<=0){
            for(int i=1;i<=G;i++){
            if(arr[i]>0) answer++;
            // cout<<"배열 : "<<arr[i]<<"\n";
            }

            cout<<answer<<endl;
            return 0;
        }
    }

    for(int i=1;i<=G;i++){
        if(arr[i]>0) answer++;
    }

    cout<<answer<<endl;
    return 0;

}