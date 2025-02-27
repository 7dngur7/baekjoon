#include <iostream>
#include <queue>

using namespace std;

queue<pair<int,int> >q;
int arr[101][101]={};
int xarr[] = {0, 0, 1, -1};
int yarr[] = {1,-1, 0, 0};

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

int n, m;
cin>>n>>m;

for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        cin>>arr[i][j];
    }
}
int ans = 0;
int cheesecnt = 1;
while(cheesecnt>0){
    
    // cout<<"test!\n";
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    
    ans++;
    cheesecnt = 0;
    int chkarr[101][101]={};
    int cheesearr[101][101]={};
    
    q.push(make_pair(0,0));
    
    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int newx = curx + xarr[i];
            int newy = cury + yarr[i];
            
            if(newx<0 || newy<0 || newx>=n || newy>=m ) continue;
            if(chkarr[newx][newy]>0) continue;
            
            if(arr[newx][newy]>0){
                cheesearr[newx][newy]++;
                cheesecnt++;
                
                if(cheesearr[newx][newy]>=2){
                    arr[newx][newy] = 0;
                }
                
            }
            else{
                chkarr[newx][newy] = 1;
                if(cheesearr[newx][newy]==0){
                     q.push(make_pair(newx, newy));   
                }
            }
            
        }
        
    }
}

cout<<ans-1<<"\n";
return 0;
}