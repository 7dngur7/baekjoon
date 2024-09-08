#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//우선순위
int narr[1002]={};

vector<int> answer;

vector<vector<int> > v(1003);

queue<int> q;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;

    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a;
        cin>>a;

        int before;

        cin>>before;

        for(int j=1; j<a; j++){

            int b;
            cin>>b;

            v[before].push_back(b);

            narr[b]++;
            before = b;
        }

    }
    
    // for(int i=1; i<=n; i++){
    //     cout<<narr[i]<<" ";
    // }
    // cout<<"\n";



    for(int i=1; i<=n; i++){
        if(narr[i]==0){
            q.push(i);
            narr[i]=-1;
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        answer.push_back(cur);

        for(int i=0; i<v[cur].size(); i++){
            narr[v[cur][i]]--;
        }

        for(int i=1; i<=n; i++){
            if(narr[i]==0){
                q.push(i);
                narr[i]=-1;
            }
        }

        // for(int i=1; i<=n; i++){
        //     cout<<narr[i]<<" ";
        // }
        // cout<<"\n";


    }

    if(answer.size()!= n){
        cout<<"0\n";
    }
    else{
        for(int i=0; i<n; i++){
            cout<<answer[i]<<"\n";
        }
    }

}

