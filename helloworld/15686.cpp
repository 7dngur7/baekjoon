#include <iostream>
#include <vector>

using namespace std;

int arr[52][52]={};
int dist[52][52]={};
int homecnt = 0, chickcnt = 0;
vector<pair<int,int> > homev;
vector<pair<int,int> > chickenv;

int ans = 1000000000;
vector<int> selected;

int n, m;

void dfs (int start, int depth, vector<int>& selected){

    if(depth == m){
        int sum = 0;

        for(int i=0; i<homecnt; i++){
            int d = 1000000000;

            int curx = homev[i].second;
            int cury = homev[i].first;

            for(int j=0; j<m; j++){
                int curchickx = chickenv[selected[j]].second;
                int curchicky = chickenv[selected[j]].first;

                d = min(d, abs(curx-curchickx)+abs(cury-curchicky));
            }
            

            sum+=d;

        }
        ans = min(ans, sum);
    }

    for(int i=start; i<chickcnt; i++){
        selected.push_back(i);
        dfs(i+1, depth+1, selected);
        selected.pop_back();
    } 

}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);


    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];

            if(arr[i][j]==1){
                homecnt++;
                homev.push_back(make_pair(i,j));
            }
            else if(arr[i][j]==2){
                chickcnt++;
                chickenv.push_back(make_pair(i,j));
            }

        }
    }


    dfs(0,0, selected);

    cout<<ans<<"\n";



}
