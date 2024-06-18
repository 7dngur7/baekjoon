#include <iostream>
#include <map>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<int, int>m;

    int a, b;
    cin>>a>>b;

    for(int i = 0 ; i<a; i++){
        int c;
        cin>>c;

        m.insert({c, 1});

    }

    for(int i=0; i<b; i++){
        int c;
        cin>>c;
        if(m.find(c)!=m.end()){
            m.erase(c);
        }

    }


    cout<<m.size()<<"\n";
    for(auto a : m){
        cout<<a.first<<" ";
    }

    cout<<endl;

}