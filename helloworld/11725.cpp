#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> v[100002];
int chkarr[100002]={};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }


    queue<int> q;
    q.push(1);
    chkarr[1] = -1;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        //cout<<"cur: "<<cur<<"\n";


        for(int i=0; i<v[cur].size(); i++){
            //cout<<"chk: "<<v[cur][i]<<"\n";

            if(chkarr[v[cur][i]]!=0) continue;

            chkarr[v[cur][i]]= cur;
            q.push(v[cur][i]);
        }
    }

    for(int i=2; i<=n; i++){
        cout<<chkarr[i]<<"\n";
    }


}