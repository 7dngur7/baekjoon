#include <iostream>
#include <queue>

using namespace std;

int arr[302][302]={}, checkarr[302][302], dx[]={0,-1,0,1}, dy[]={-1,0,1,0}, minusarr[302][302]={};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m, maxnum=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            maxnum = max(maxnum, arr[i][j]);
        }
    }
    // cout<<maxnum<<"확인\n";
    for(int a=0;a<100000;a++){
        int landnum=0;

        queue<pair<int,int> >q;

        //빙하덩이확인
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]!=0 && checkarr[i][j]==0){
                    q.push(make_pair(i,j));
                    landnum++;
                    while(!q.empty()){
                        pair<int, int>cur = q.front();
                        q.pop();

                        for(int k=0;k<4;k++){
                            int newx=cur.first+dx[k];
                            int newy=cur.second+dy[k];

                            if(newx<0||newy<0||newx>=n||newy>=m)continue;
                            if(arr[newx][newy]==0||checkarr[newx][newy]!=0)continue;

                            checkarr[newx][newy]=1;
                            q.push(make_pair(newx,newy));

                        }


                    }



                }
            }
        }

        if(landnum>1){
            cout<<a<<endl; 
            return 0;
        }
        else if(landnum==0){
            cout<<"0"<<endl;
            return 0;
        }


        //매년 빙하 녹이기
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]!=0){
                    for(int k=0;k<4;k++){
                        int newx=i+dx[k];
                        int newy=j+dy[k];
                        if(newx<0||newy<0) continue;
                        if(arr[newx][newy]==0){
                            minusarr[i][j]--;
                        }

                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i][j]+=minusarr[i][j];
                if(arr[i][j]<0) arr[i][j]=0;
            }
        }

        //check, minusarr 0으로
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                checkarr[i][j]=0;
                minusarr[i][j]=0;
            }
        }

        // //배열 테스트
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<arr[i][j];
        //     }
        //     cout<<"\n";
        // }
        // cout<<"\n";

    }

    cout<<"0"<<endl;
    return 0;


}