#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string S, T;

    cin>>S;
    cin>>T;


    while(!T.empty()){
        if(S==T){
            cout<<"1"<<endl;
            return 0;
        }
        if(T[T.length()-1]=='A'){
            T.pop_back();
        }
        else if(T[T.length()-1]=='B'){
            T.pop_back();
            reverse(T.begin(), T.end());
        }
        else{
            cout<<"error";
        }
    }

    cout<<"0"<<endl;
}