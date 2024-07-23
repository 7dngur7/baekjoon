#include <iostream>
#include <deque>

using namespace std;

int chkarr[200005]={};
deque<int> q;

int xarr[3]={-1, 1};

int n, k;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k;

    q.push_back(n);
    chkarr[n]=1;
    while (!q.empty()){
        int cur = q.front();
        q.pop_front();

        //cout<<cur<<" "<<xarr[cur]<<"\n";

        int a = cur;
        while(a<=k){
            a*=2;
            if(chkarr[a]>chkarr[cur] || chkarr[a]==0 ){
                q.push_back(a);
                chkarr[a]= chkarr[cur];
            }
            if(a==0) break;
        }

        for(int i=0; i<2; i++){
            int xcur = cur + xarr[i];

            if(xcur<0||xcur>200000)continue;
            if(chkarr[xcur]!=0 && chkarr[xcur]<chkarr[cur]+1) continue;

            q.push_back(xcur);
            chkarr[xcur]=chkarr[cur]+1;
        }
    }

    cout<<chkarr[k]-1<<"\n";
    
    
}