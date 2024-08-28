#include <iostream>
#include <queue>

using namespace std;

int arr[1005][1005]={};
int chkarr[1005][1005]={};

int xarr[4]={1,0,-1,0};
int yarr[4]={0,1,0,-1};

//세로, 가로
queue< pair<int,int> > q;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin>>n>>m;

    for(int i=0; i<n ;i++){
        for(int j=0; j<m; j++){
            int a;
            cin>>a;
            if(a==0){
                chkarr[i][j]=1;
            }
            else if(a==1){

            }
            else if(a==2){
                q.push(make_pair(i,j));
                chkarr[i][j]=1;
            }
        }
    }

    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int cury = cur.first + yarr[i];
            int curx = cur.second + xarr[i];

            if(cury<0||curx<0||cury>=n||curx>=m) continue;
            if(chkarr[cury][curx]==1)continue;

            arr[cury][curx]= arr[cur.first][cur.second]+1;
            chkarr[cury][curx]=1;
            q.push(make_pair(cury, curx));
        }
    }

    for(int i=0; i<n ;i++){
        for(int j=0; j<m; j++){
            if(chkarr[i][j]==0){
                cout<<"-1 ";
            }
            else{
                cout<<arr[i][j]<<" ";

            }
        }
        cout<<"\n";
    }
}