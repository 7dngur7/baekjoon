#include <iostream>
#include <queue>

using namespace std;

int arr[1002][1002]={};
queue< pair<int, int> >q;
int xarr[4]={-1,0,1,0};
int yarr[4]={0,1,0,-1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        string a;
        cin>>a;
        for(int j=0; j<m; j++){
            arr[i][j]=a[j]-'0';
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]>0){
                int chkarr[1002][1002]={};
                int curans=1;

                q.push(make_pair(i,j));
                chkarr[i][j]=1;

                while(!q.empty()){
                    pair<int,int> cur = q.front();
                    q.pop();

                    for(int i=0; i<4; i++){
                        int xcur=cur.first+xarr[i];
                        int ycur=cur.second+yarr[i];

                        if(xcur<0||xcur>=n||ycur<0|| ycur>=m)continue;
                        if(chkarr[xcur][ycur]>0)continue;
                        if(arr[xcur][ycur]>0)continue;

                        q.push(make_pair(xcur, ycur));
                        chkarr[xcur][ycur]=1;
                        curans++;

                        //cout<<"cur:"<<xcur<<" "<<ycur<<"\n";
                    }
                }

                arr[i][j]=curans%10;

            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j];
        }
        cout<<"\n";
    }

}