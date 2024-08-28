#include <iostream>
#include <queue>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int> q;

    int n;

    cin>>n;


    for(int i=0; i<n; i++){
        int a;
        cin>>a;

        if(a==0){
            if(!q.empty()){
                cout<<q.top()<<"\n";
                q.pop();
            }
            else{
                cout<<"0\n";
            }
        }
        else{
            q.push(a);
        }


    }

}