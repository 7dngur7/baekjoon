#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<int> q;

pair<int,int> chkarr[100005]={};
int xarr[3]={-1, 1, 0};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin>>n>>k;

    q.push(n);
    chkarr[n]= make_pair(1,1);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        //cout<<"test: "<<cur<<"\n";

        for(int i=0; i<3; i++){
            int xcur;
            if(xarr[i]== 0){
                xcur = cur*2;
            }
            else{
                xcur = cur+ xarr[i];
            }

            if(xcur<0||xcur>100000) continue;
            if(chkarr[xcur].first==0){
                chkarr[xcur] = make_pair(chkarr[cur].first+1, 1);
                q.push(xcur);
            }
            else if(chkarr[xcur].first>chkarr[cur].first+1){
                chkarr[xcur] = make_pair(chkarr[cur].first+1, 1);
                q.push(xcur);
            }
            else if(chkarr[xcur].first==chkarr[cur].first+1){
                //cout<<"chk!!!!!!\n";
                chkarr[xcur].second++;
                q.push(xcur);
            }

        }


    }

    cout<<chkarr[k].first-1<<"\n"<<chkarr[k].second<<"\n";


}