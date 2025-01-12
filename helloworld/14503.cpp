#include <iostream>


using namespace std;

int arr[50][50]={};
int chkarr[50][50]={};

int narr[] = {-1,0,1,0};
int marr[] = {0,1,0,-1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin>>n>>m;

    int r, c, direct;
    cin>>r>>c>>direct;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<arr[i][j];
    //     }
    //     cout<<"\n";
    // }
    int ans = 0;

    while(1){
        if(chkarr[r][c] == 0){
            chkarr[r][c] = 1;
            ans++;
        }
        // cout<<"test: "<<r<<" "<<c<<" "<< direct<<"\n";
        // cout<<"\n";
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout<<chkarr[i][j];
        //     }
        //     cout<<"\n";
        // }


        int chkspace = 0;

        for(int i=0; i<4; i++){
            int curr = r + narr[i];
            int curc = c + marr[i];

            if(curr<0 || curr>=n || curc<0 || curc>=m) continue;
            if(arr[curr][curc]==1) continue;
            if(chkarr[curr][curc]==1)continue;

            chkspace = 1;
            break;

        }

        if(chkspace == 0){
            int curdirect = (direct+2)%4;

            int curr = r + narr[curdirect];
            int curc = c + marr[curdirect];

            if(curr<0 || curr>=n || curc<0 || curc>=m) break;
            if(arr[curr][curc]==1) break;

            r = curr;
            c = curc;
        }
        else{
            direct = (direct+3)%4;

            int curr = r + narr[direct];
            int curc = c + marr[direct];

            if(curr<0 || curr>=n || curc<0 || curc>=m) continue;
            if(arr[curr][curc]==1) continue;
            if(chkarr[curr][curc]==1)continue;

            r = curr;
            c = curc;
        }
        

    }

    // cout<<"\n";
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<chkarr[i][j];
    //     }
    //     cout<<"\n";
    // }
    cout<<ans<<"\n";
}