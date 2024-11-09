#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<string> set;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a;

    cin>>a;

    for(int i=0; i<a.length(); i++){
        for(int j=i+1; j<=a.length(); j++){
            // cout<<"test: "<<a.substr(i, j-i)<<"\n";
            set.insert(a.substr(i, j-i));
        }
    }

    cout<<set.size()<<"\n";
}