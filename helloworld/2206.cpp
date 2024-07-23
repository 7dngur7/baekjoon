#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

char arr[1005][1005]={};
char breakarr[1005][1005]={};
queue< pair<pair<int,int>, int> >q;

int xarr[4]={0,1,0,-1};
int yarr[4]={1,0,-1,0};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin>>n>>m;



    int onecnt = 0;

    for(int i=0; i<n; i++){
        string b;
        cin>>b;
        for(int j=0; j<m;j++){
            arr[i][j]= b[j];
        }
    }

    if(n==1&&m==1){
        cout<<"1\n";
        return 0;
    }

    int answerexist = 0;
    int answer = 1000005;

    int chkarr[1005][1005][2]={};
    q.push(make_pair(make_pair(0,0), 0));
    chkarr[0][0][0]=1;

    while(!q.empty()){
        pair<int,int> cur = q.front().first;
        int alreadybreak = q.front().second;
        q.pop();

        //cout<<alreadybreak;

        for(int i=0; i<4; i++){
            int curx = cur.first + xarr[i];
            int cury = cur.second + yarr[i];

            if(curx<0||curx>=n||cury<0||cury>=m)continue;
            if(alreadybreak==1){
                if(arr[curx][cury]=='1')continue;
                if(chkarr[curx][cury][1]!=0 && chkarr[curx][cury][1]<=chkarr[cur.first][cur.second][1]+1)continue;

                       // cout<<"chk";

                chkarr[curx][cury][1] = chkarr[cur.first][cur.second][1]+1;
                q.push(make_pair(make_pair(curx,cury),1));
            }
            else{
                                        //cout<<"chk";

                if(arr[curx][cury]=='1'){
                    if(chkarr[curx][cury][1]!=0 && chkarr[curx][cury][1]<=chkarr[cur.first][cur.second][0]+1)continue;
                    chkarr[curx][cury][1] = chkarr[cur.first][cur.second][0]+1;
                    q.push(make_pair(make_pair(curx,cury),1));

                }
                else{
                    if(chkarr[curx][cury][0]!=0 && chkarr[curx][cury][0]<=chkarr[cur.first][cur.second][0]+1)continue;
                    chkarr[curx][cury][0] = chkarr[cur.first][cur.second][0]+1;
                    q.push(make_pair(make_pair(curx,cury),0));

                }
            }
        }
    }


    if(chkarr[n-1][m-1][0]==0 && chkarr[n-1][m-1][1] ==0){
        answerexist=1;
    }
    else if(chkarr[n-1][m-1][0]==0) {
        answer = chkarr[n-1][m-1][1];
    }
    else if(chkarr[n-1][m-1][1]==0 ){
        answer = chkarr[n-1][m-1][0];

    }
    else{
        answer = min(chkarr[n-1][m-1][1],chkarr[n-1][m-1][0]);

    }

    // cout<<"\n";
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m;j++){
    //         cout<<chkarr[i][j][0]<<" ";
    //     }
    //     cout<<"\n";
    // }

    // cout<<"\n";
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m;j++){
    //         cout<<chkarr[i][j][1]<<" ";
    //     }
    //     cout<<"\n";
    // }
    

    if(answerexist==0){
        cout<<answer<<"\n";
    }
    else{
        cout<<"-1\n";
    }

}