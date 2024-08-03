#include <iostream>
#include <queue>

using namespace std;

int xarr[2]={};
int chkarr[1000002]={};
queue<int> q;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int f,s,g,u,d;

    cin>>f>>s>>g>>u>>d;

    xarr[0]=u;
    xarr[1]=-d;

    q.push(s);
    chkarr[s]=1;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i=0; i<2; i++){
            int xcur = cur+xarr[i];

            if(xcur<=0||xcur>f)continue;
            if(chkarr[xcur]!=0 && chkarr[cur]+1>=chkarr[xcur])continue;

            chkarr[xcur] = chkarr[cur]+1;
            q.push(xcur);

        }


    }

    if(chkarr[g]==0){
        cout<<"use the stairs\n";
    }
    else{
        cout<<chkarr[g]-1<<"\n";
    }

}