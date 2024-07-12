#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int chkarr[102][102][102]={};
int arr[102][102][102]={};

int zarr[]={0,0,0,0,1, -1};
int xarr[]={0,1,0,-1, 0, 0};
int yarr[]={1,0,-1,0, 0 ,0};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, h;
    cin>>m>>n>>h;

    int maxtomato = m*n*h;
    int cnttomato = 0;
    int answer = 0;

    int curque = 1;

    queue< tuple<int,int,int> > q1;
    queue< tuple<int,int,int> > q0;


    for(int i=1; i<=h; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=m; k++){
                int a;
                cin>>a;

                if(a==1){
                    chkarr[i][j][k]=1;
                    arr[i][j][k]=1;
                    q1.push(make_tuple(i,j,k));
                    cnttomato++;
                }
                else if (a==0){

                }
                else{
                    chkarr[i][j][k]=1;
                    arr[i][j][k]=-1;
                    cnttomato++;
                }
            }
        }
    }
    if(cnttomato==maxtomato){
        cout<<0<<"\n";
        return 0;
    }

    while(!q1.empty()||!q0.empty()){
        //cout<<"test: "<<curque<<"\n";
        if(curque==1){
            tuple<int,int,int> cur = q1.front();
            int z = get<0>(cur);
            int y = get<1>(cur);
            int x = get<2>(cur);
            q1.pop();

            for(int i=0;i<6; i++){
                int curx = x+xarr[i];
                int cury = y+yarr[i];
                int curz = z+zarr[i];
               // cout<<"before chk: "<<curz<< " "<<cury<<" "<<curx<<"\n";

                if(curx<=0||cury<=0||curx>m||cury>n||curz<=0||curz>h)continue;
                if(chkarr[curz][cury][curx]==1) continue;

                //cout<<"chk: "<<curz<< " "<<cury<<" "<<curx<<"\n";
                chkarr[curz][cury][curx] = 1;
                q0.push(make_tuple(curz, cury, curx));
                cnttomato++;

            }
            if(q1.empty()){
                answer++;
                curque=0;
            }
        }
        else{
            tuple<int,int,int> cur = q0.front();
            int z = get<0>(cur);
            int y = get<1>(cur);
            int x = get<2>(cur);
            q0.pop();

            for(int i=0;i<6; i++){
                int curx = x+xarr[i];
                int cury = y+yarr[i];
                int curz = z+zarr[i];

                if(curx<=0||cury<=0||curx>m||cury>n||curz<=0||curz>h)continue;
                if(chkarr[curz][cury][curx]==1) continue;

               // cout<<"chk: "<<curz<< " "<<cury<<" "<<curx<<"\n";
                chkarr[curz][cury][curx] = 1;
                q1.push(make_tuple(curz, cury, curx));
                cnttomato++;
            }
            if(q0.empty()){
                answer++;
                curque=1;
            }

        }

    }

    if(cnttomato==maxtomato){
        cout<<answer-1<<"\n";
    }
    else{
        cout<<"-1\n";
    }

    // for(int i=1; i<=h; i++){
    //     for(int j=1; j<=n; j++){
    //         for(int k=1; k<=m; k++){
    //             int a;
    //             cout<<chkarr[i][j][k]<<" ";
    //         }
    //         cout<<"\n";
    //     }
    //     cout<<"\n";
    // }

}