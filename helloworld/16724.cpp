#include <iostream>
#include <vector>

using namespace std;

int arr[1002][1002] = {};
int ansarr[1002] = {};
char chararr[1002][1002];

int xarr[] = {1, 0, -1, 0};
int yarr[] = {0, 1, 0 ,-1};
int n, m;

// int get_parent(int x, int y){
//     if(arr[x][y] == (x-1)*m+y) return arr[x][y];

//     int newx = arr[x][y]/n+1;
//     int newy = arr[x][y]%m;

//     return arr[x][y] = get_parent(newx,newy);
// }

// //여기서 이제 역순으로 들어가면서 바꿔줘야됨
// void union_parent(int x1, int y1, int x2, int y2){
//     //재귀적으로 들어가며 다 바꿔주는 것


// }

// int find_parent(int x1, int y1, int x2, int y2){
//     if(get_parent(x1, y1) == get_parent(x2, y2)){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;

    for(int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            arr[i][j] = (i-1)*m+j;
        }
    }    


    for(int i=1; i<=n; i++){
        string a;
        cin>>a;
        for (int j=1; j<=m; j++){
            char cmd = a[j-1];

    for(int i=1; i<=n; i++){
        string a;
        cin>>a;
        for (int j=1; j<=m; j++){
            char cmd = a[j-1];
            
            // cout<< "test: "<<(i-1)*m+j<<"\n";
            if(cmd == 'U'){
                // union_parent(i, j, i-1, j);

                union_parent(i, j, i-1, j);
            }
            else if(cmd == 'D'){
                // union_parent(i, j, i+1, j);

                union_parent(i, j, i+1, j);

            }
            else if(cmd == 'L'){
                // union_parent(i, j, i, j-1);


                union_parent(i, j, i, j-1);

            }
            else{
                // union_parent(i, j, i, j+1);

                union_parent(i, j, i, j+1);

            } 

            // for(int i=1; i<=n; i++){
            //     for (int j=1; j<=m; j++){
            //         cout<< arr[i][j]<<" ";
            //     }
            //     cout<<"\n";
            // }
        }
    }


    for(int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cout<< arr[i][j]<<" ";
        }
        cout<<"\n";
    }

    for(int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            ansarr[arr[i][j]]++;
        }
    }
    int answercnt = 0;
    for(int i=1; i<=n*m; i++){
        if(ansarr[i]>0){
            answercnt++;
        }
    }

    cout<<answercnt<<"\n";

}