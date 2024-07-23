#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector< pair<int,int> > v[10002];
int ansarr[10002]={};

queue< pair<int,int> >q;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    int leafcnt = 0;

    for(int i=0; i<n-1; i++){
        int a, b, c;
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));

        if(i==n-2){
            leafcnt = a;
        } 
    }

    int answer=0;

    for(int i=1; i<=n; i++){
        int ansarr[10002]={};
        int chkarr[10002]={};

        q.push(make_pair(i,0));

        //cout<<"curans: "<<answer<<"\n";

        while(!q.empty()){
            pair<int,int> cur = q.front();
            q.pop();
            chkarr[cur.first]=1;
            //cout<<"cur: "<<cur.first<<"\n";

            for(int j=0; j<v[cur.first].size(); j++){
                pair<int,int> xcur = v[cur.first][j];

                //cout<<"xcur: "<<xcur.first<<" "<<xcur.second<<"\n";

                if(chkarr[xcur.first]==1)continue;
                if(ansarr[xcur.first]>=ansarr[cur.first]+xcur.second) continue;

                //cout<<"xcur chke: "<<xcur.first<<" "<<ansarr[xcur.first]<<" "<<ansarr[cur.first]<<" "<<xcur.second<<"\n";
                ansarr[xcur.first] = ansarr[cur.first]+xcur.second;
                //cout<<"ansarr: "<<ansarr[xcur.first]<<" "<<ansarr[cur.first]+cur.second<<"\n";

                q.push(xcur);
                
                answer = max(answer, ansarr[xcur.first]);

            }
        }

    }

    cout<<answer<<"\n";



}
