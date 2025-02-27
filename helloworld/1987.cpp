#include <iostream>

using namespace std;

char arr[22][22]={};

int ans=0;
int r, c;

void dfs(int curR, int curC, int score ,int* alphabet){
if(curR>=r || curC>=c || curR < 0 || curC < 0 ){
// if(max(score, ans)!=ans){
// for(int i=0; i<26; i++){
// if(alphabet[i]>0){
// cout<<char(i+65)<<" ";
// }
// }
// cout<<"\n";
// }

    ans = max(score, ans);
    return;
}
if(alphabet[((int)arr[curR][curC])-65]!=0){
    // if(max(score, ans)!=ans){
    //     for(int i=0; i<26; i++){
    //         if(alphabet[i]>0){
    //             cout<<char(i+65)<<" ";
    //         }
    //     }
    //     cout<<"\n";            
    // }
    
    ans = max(score, ans);
    return;
}
alphabet[((int)arr[curR][curC])-65]=1;

dfs(curR+1, curC, score+1, alphabet);
dfs(curR, curC+1, score+1, alphabet);
dfs(curR, curC-1, score+1, alphabet);
dfs(curR-1, curC, score+1, alphabet);

alphabet[((int)arr[curR][curC])-65]=0;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

cin>>r>>c;

for(int i=0; i<r; i++){
    string a;
    cin>>a;
    for(int j=0; j<c; j++){
        arr[i][j]=a[j];
    }
}

// for(int i=0; i<r; i++){
//     for(int j=0; j<c; j++){
//         cout<<arr[i][j]<<" ";
//     }
//     cout<<"\n";
// }

int alphabet[30] = {};
dfs(0,0,0,alphabet);

cout<<ans<<"\n";

return 0;
}