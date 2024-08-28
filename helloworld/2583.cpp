#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int chkarr[103][103]={};
queue< pair<int,int> > q;
vector<int> ans;
int xarr[4]={1,-1,0,0};
int yarr[4]={0,0,1,-1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, k;

    cin>>n>>m>>k;

    //cout<<"\n";

    for(int r=0; r<k; r++){
        int a, b, c, d;
        cin>>a>>b>>c>>d;

        for(int x=a; x<c; x++){
            for(int y=b; y<d; y++){
                chkarr[x][y]=1;
            }
        }
    }

    // for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<chkarr[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

     for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(chkarr[i][j]==0){
                int curans = 1;
                q.push(make_pair(i,j));
                chkarr[i][j]=1;

                while(!q.empty()){
                    pair<int,int> cur = q.front();
                    q.pop();

                    //cout<<"curchk:"<<cur.first<<" "<<cur.second<<"\n";
                    
                    for(int i=0; i<4; i++){
                        int curx=cur.first+xarr[i];
                        int cury=cur.second+yarr[i];

                        if(curx<0||curx>=m||cury<0||cury>=n)continue;
                        if(chkarr[curx][cury]>0)continue;

                        chkarr[curx][cury]=1;
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

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";


}