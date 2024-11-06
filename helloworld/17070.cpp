#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int state1x[] = {1,1};
int state1y[] = {0,1};
int state1[] = {1,3};

int state2x[] = {0,1};
int state2y[] = {1,1};
int state2[] = {2,3};

int state3x[] = {1,0,1};
int state3y[] = {0,1,1};
int state3[] = {1,2,3};

int arr[17][17]={};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int answer = 0;
    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int a;
            cin>>a;
            arr[i][j] = a;
        }
    }



    //뒷 좌표 x, y , state
    queue<tuple<int,int,int> > q;

    q.push(make_tuple(1,2,1));

    while(!q.empty()){
        auto curq = q.front();
        q.pop();

        int cury = get<0>(curq); 
        int curx = get<1>(curq); 
        int curstate = get<2>(curq); 

        // cout<<"curstate : "<<cury<<" "<<curx<<" "<<curstate<<"\n";

        if(curstate == 1){
            for(int i=0; i<2; i++){
                int newx = curx + state1x[i];
                int newy = cury + state1y[i];
                int newstate = state1[i];

                if(newx>n || newy>n) continue;
                
                if(newstate==1 && arr[newy][newx]==1)continue;
                if(newstate==2 && arr[newy][newx]==1) continue;
                if(newstate==3 && arr[newy][newx]==1) continue;
                if(newstate==3 && arr[cury][newx]==1) continue;
                if(newstate==3 && arr[newy][curx]==1) continue;

                if(newx==n && newy==n){

                    // cout<<"curans : "<<cury<<" "<<curx<<" "<<curstate<<"\n";
                    answer++;
                    continue;
                }

                q.push(make_tuple(newy, newx, newstate));
            }
        }
        else if(curstate == 2){
            for(int i=0; i<2; i++){
                int newx = curx + state2x[i];
                int newy = cury + state2y[i];
                int newstate = state2[i];

                if(newx>n || newy>n) continue;

                if(newstate==1 && arr[newy][newx]==1)continue;
                if(newstate==2 && arr[newy][newx]==1) continue;
                if(newstate==3 && arr[newy][newx]==1) continue;
                if(newstate==3 && arr[cury][newx]==1) continue;
                if(newstate==3 && arr[newy][curx]==1) continue;

                if(newx==n && newy==n){
                    // cout<<"curans : "<<cury<<" "<<curx<<" "<<curstate<<"\n";

                    answer++;
                    continue;
                }

                q.push(make_tuple(newy, newx, newstate));
            }
        }
        else{
            for(int i=0; i<3; i++){
                int newx = curx + state3x[i];
                int newy = cury + state3y[i];
                int newstate = state3[i];

                if(newx>n || newy>n) continue;

                if(newstate==1 && arr[newy][newx]==1)continue;
                if(newstate==2 && arr[newy][newx]==1) continue;
                if(newstate==3 && arr[newy][newx]==1) continue;
                if(newstate==3 && arr[cury][newx]==1) continue;
                if(newstate==3 && arr[newy][curx]==1) continue;


                if(newx==n && newy==n){
                    // cout<<"curans : "<<cury<<" "<<curx<<" "<<curstate<<"\n";
                    answer++;
                    continue;
                }

                q.push(make_tuple(newy, newx, newstate));
            }

        }
    }

    cout<<answer<<"\n";
    
}