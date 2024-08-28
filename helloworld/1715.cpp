#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;




int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int, vector<int>, greater<int> > q;

    int n, answer=0;
    cin>>n;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;

        q.push(a);
    }

    // answer = q.top();
    // q.pop();


    while(!q.empty()){
        int a, b, c;

        a = q.top();
        q.pop();
            
        //cout<<"1 : "<<a<<"\n";


        
        if(q.empty()){
            cout<<answer<<"\n";
            return 0;
        }

        b = q.top();
        q.pop();

        answer+= a+b;
        q.push(a+b);

        //cout<<"2 : "<<a+b<<"\n";


        if(q.empty()){
            cout<<answer<<"\n";
            return 0;
        }

    }


}
