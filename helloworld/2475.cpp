#include <iostream> 

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string mode;
    int arr[8];
    for(int i=0; i<8; i++){
        cin>>arr[i];
    
    }
    if(arr[0]<arr[1]){
        mode = "ascending";
    }
    else if(arr[0]>arr[1]){
        mode = "descending";
    }
    else{
        cout<<"mixed\n";
        return 0;
    }

    for(int i=1; i<7; i++){
        if(mode=="ascending"){
            if(arr[i]>=arr[i+1]){
                cout<<"mixed\n";
                return 0;
            }
        }
        else{
            if(arr[i]<=arr[i+1]){
                cout<<"mixed\n";
                return 0;
            }
        }
    }
    cout<<mode<<"\n";

}