#include<iostream>
#include<queue>

using namespace std;

    int arr[102][102], checkarr[102][102]={}, dx[]={0,-1,0,1}, dy[]={-1,0,1,0};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arrnum;
    cin>>arrnum;
    int maxheight=0, answernum = 0;


    for(int i=0;i<arrnum;i++){
        for(int j=0;j<arrnum;j++){
            cin>>arr[i][j];
            maxheight = max(arr[i][j], maxheight);
        }
    }



    for(int a=0;a<=maxheight;a++){
        for(int i=0;i<arrnum;i++){
            for(int j=0;j<arrnum;j++){
                if(arr[i][j]>a || checkarr[i][j] != 0) continue;
                queue<pair<int,int> > q;
                checkarr[i][j]=1;
                q.push(make_pair(i,j));
                while (!q.empty()){
                
                pair<int, int>cur = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int newx=cur.first+dx[k];
                    int newy = cur.second+dy[k];
                    if(newx<0||newy<0||newx>=arrnum||newy>=arrnum)continue;
                    if(checkarr[newx][newy]!=0 || arr[newx][newy]>a)continue;
                    checkarr[newx][newy]=1;
                    q.push(make_pair(newx,newy));
                }

            }
        
            }
        }

    // for(int i=0;i<arrnum;i++){
    //     for(int j=0;j<arrnum;j++){
    //         cout<<checkarr[i][j];
    //     }
    //     cout<<"\n";
    // }


        int roundbiggest=0;
        for(int i=0;i<arrnum;i++){
            for(int j=0;j<arrnum;j++){
                if(checkarr[i][j] != 0) continue;
                queue<pair<int,int> > q;
                checkarr[i][j]=1;
                q.push(make_pair(i,j));
                roundbiggest++;

                while (!q.empty()){
                pair<int, int> cur = q.front();
                q.pop();

                for(int k=0;k<4;k++){
                    int newx=cur.first+dx[k];
                    int newy = cur.second+dy[k];
                    if(newx<0||newy<0||newx>=arrnum||newy>=arrnum)continue;
                    if(checkarr[newx][newy]!=0)continue;

                    checkarr[newx][newy]=1;
                    q.push(make_pair(newx,newy));
                }

            }
        
        }
     }
        answernum=max(roundbiggest, answernum);
        // cout<<answernum<<"\n";


    for(int i=0;i<arrnum;i++){
        for(int j=0;j<arrnum;j++){
            checkarr[i][j]=0;
        }
    }


    }
    cout<<answernum<<endl;

}