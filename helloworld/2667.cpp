#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

char chkarr[103][103]={};
queue< pair<int,int> > q;
vector<int> ans;
int xarr[4]={1,-1,0,0};
int yarr[4]={0,0,1,-1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    for(int i=0; i<n;i++){
        cin>>chkarr[i];
    }



    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(chkarr[i][j]=='1'){
                int curans = 1;
                q.push(make_pair(i,j));
                chkarr[i][j]='0';

                while(!q.empty()){
                    pair<int,int> cur = q.front();
                    q.pop();

                    //cout<<"curchk:"<<cur.first<<" "<<cur.second<<"\n";
                    
                    for(int i=0; i<4; i++){
                        int curx=cur.first+xarr[i];
                        int cury=cur.second+yarr[i];

                        if(curx<0||curx>=n||cury<0||cury>=n)continue;
                        if(chkarr[curx][cury]=='0')continue;

                        chkarr[curx][cury]='0';
                        q.push(make_pair(curx,cury));
                        curans++;

                    }
                }

                ans.push_back(curans);
                //cout<<"\n";
            
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout<<ans.size()<<"\n";
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<"\n";
    }
}