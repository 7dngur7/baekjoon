#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

class cmp{
public:
    bool operator()(int a, int b){
        if(abs(b)<abs(a)){
            return true;
        }
        else if(abs(a)==abs(b) && b<a){
            return true;
        }

        return false;

    }
};



int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n;

    priority_queue<int, vector<int>, cmp> q;

    cin>>n;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;

        if(a==0){
            if(q.size()==0){
                cout<<0<<"\n";
            }
            else{
                int ans = q.top();
                cout<<ans<<"\n";
                q.pop();
            }
        }
        else{
            q.push(a);
        }


    }
    cout<<"\n";
    return 0;
}