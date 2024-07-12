#include <iostream>
#include <queue>

using namespace std;

int arr[10][10]={};

int xarr[4]={1,0,-1,0};
int yarr[4]={0,1,0,-1};


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    int answer = 0;

    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int a;
            cin>>a;
            arr[i][j]= a;
        }
    }


    for(int d = 0; d<n*m-2;d++){
        for(int e=d+1; e<n*m-1; e++){
            for(int f=e+1; f<n*m; f++){
                int blockx1 = d/m;
                int blocky1 = d%m;
                int blockx2 = e/m;
                int blocky2 = e%m;            
                int blockx3 = f/m;
                int blocky3 = f%m;

                if(arr[blockx1][blocky1]||arr[blockx2][blocky2]||arr[blockx3][blocky3]) continue;

                //cout<<d<<" "<<e<<" "<<f<<"\n";

                int chkarr[10][10]={};

                chkarr[blockx1][blocky1]=1;
                chkarr[blockx2][blocky2]=1;
                chkarr[blockx3][blocky3]=1;

                queue< pair<int,int> > q;

                for(int i=0; i<n; i++){
                    for(int j=0; j<m; j++){
                        if(arr[i][j]==2){
                            q.push(make_pair(i,j));
                        }
                    }
                }

                while(!q.empty()){
                    pair<int,int>cur = q.front();
                    q.pop();

                    int curx = cur.first;
                    int cury = cur.second;

                    for(int i=0; i<4; i++){
                        int newx = curx+xarr[i];
                        int newy = cury+yarr[i];

                        if(newx<0||newx>=n||newy<0||newy>=m) continue;
                        if(chkarr[newx][newy]==1 || arr[newx][newy]==1||arr[newx][newy]==2)continue;

                        q.push(make_pair(newx,newy));
                        chkarr[newx][newy]=1;
                    }
                }


                int curanswer =0;   

                for(int i=0; i<n; i++){
                    for(int j=0; j<m; j++){
                        if(chkarr[i][j]==0 && arr[i][j]==0)curanswer++;
                    }
                }

                answer = max(curanswer, answer);
            }
        }
    }


    cout<<answer<<endl;


    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<"\n";

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<chkarr[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

}