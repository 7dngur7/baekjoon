#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;


vector< vector<int> > arr(1002);
queue<int> q;
stack<int> s;

int chkq[1002]={};
int chks[1002]={};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, v;

    cin>> n>>m>>v;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;

        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        sort(arr[i].begin(), arr[i].end());
    }


    s.push(v);

    while(!s.empty()){
        int cur = s.top();
        s.pop();
        
        if(chks[cur]==1)continue;

        chks[cur]= 1;
        cout<<cur<<" ";

        for(int i=arr[cur].size()-1; i>=0; i--){
            int xcur = arr[cur][i];

            if(chks[xcur]==1)continue;
            
            s.push(xcur);

        }
    }
    cout<<"\n";


    q.push(v);

    chkq[v]= 1;
    cout<<v<<" ";

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i=0; i<arr[cur].size(); i++){
            int xcur = arr[cur][i];

            if(chkq[xcur]==1)continue;
            
            q.push(xcur);
            chkq[xcur]= 1;
            cout<<xcur<<" ";
        }
    }
    cout<<"\n";


}