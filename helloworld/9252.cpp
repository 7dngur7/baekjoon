#include <iostream>
#include <vector>

using namespace std;

int arr[1005][10005]={};
vector<char> ansstr;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin>>a>>b;

    for(int i=1; i<=a.size(); i++){
        for(int j=1; j<=b.size(); j++){
            if(a[i-1]==b[j-1]){
                arr[i][j]= arr[i-1][j-1]+1;
            }
            else{
                arr[i][j]= max(arr[i-1][j], arr[i][j-1]);
            }
        }
    }

     cout<<arr[a.size()][b.size()]<<"\n";
    // for(int i=1; i<=a.size(); i++){
    //     for(int j=1; j<=b.size(); j++){

    //             cout<<arr[i][j];  
    //     }
    //     cout<<"\n";

    // }


    int i=a.size();
    int j=b.size();
    while(i>0&&j>0){
        if(arr[i][j]==arr[i][j-1]&&arr[i][j]==arr[i-1][j]){
            //셋 다 같음 -> 아무데나 
            i--;
        }
        else if(arr[i][j]==arr[i][j-1]){
            j--;
        }
        else if(arr[i][j]==arr[i-1][j]){
            i--;
        }
        else{
            //둘 다 1 적음 -> 글자 적음  
            ansstr.push_back(a[i-1]);
            i--;
            j--;
            //cout<<"chk\n";
        }
        //cout<<"a: "<<i<<",b: "<<j<<"\n";
    }

    

    for(int i=ansstr.size()-1; i>=0; i--){
        cout<<ansstr[i];
    }
    cout<<"\n";

}