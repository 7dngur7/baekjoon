#include <iostream>
#include <queue>

using namespace std;

int chkarr[200005]={};
queue<int> q;

int xarr[3]={-1, 1, 0};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;

    cin>>a>>b;

    q.push(a);
    //chkarr[a] = 1;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        cout<<"cur: "<<cur<<"\n";

        for(int i=0; i<3; i++){
            if(xarr[i]==0){
                int xcur = cur;
                while(xcur<b*2){
                    xcur *=2;

                    cout<<xcur<<"--\n";
                    if(xcur<0)continue;
                    if(chkarr[xcur]!=0 && chkarr[xcur]<=chkarr[cur] && xcur==0)break;
                    if(chkarr[xcur]!=0 && chkarr[xcur]<=chkarr[cur])continue;
                    
                    chkarr[xcur]=chkarr[cur];
                    q.push(xcur);
                }
            }
            else{
                int xcur = cur + xarr[i];

                if(xcur>200000 || xcur<0)continue;
                if(chkarr[xcur]!=0 && chkarr[xcur]<chkarr[cur]+1)continue;

                chkarr[xcur]=chkarr[cur]+1;
                q.push(xcur);
            }
        }

    }

    cout<<chkarr[b]<<"\n";


}