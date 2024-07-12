#include <iostream>

using namespace std;

int arr[1005][1005]={};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin>>a>>b;

    for(int i=1; i<=a.length(); i++){
        for(int j=1; j<=b.length(); j++){
            arr[i][j] = max(max(arr[i - 1][j], arr[i][j - 1]), arr[i - 1][j - 1] + (a[i - 1] == b[j - 1]));

        }
    }
    cout<<arr[a.length()][b.length()]<<"\n";

}