#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 0, cur_score = 0, answer = 0, n, m;

    int v[10005]={};
    queue<int> q;


    cin>>n>>m;
    for(int i = 0;i<n;i++){
        cin>>v[i];

    }

    while(cnt <= n){
        //cout<<"cur_score: "<<cur_score<<"\n";
        if(cur_score<m){
            int k = v[cnt++];
            cur_score += k;

            q.push(k);
        }
        else if(cur_score>m){
            int k = q.front();

            cur_score-=k;
            q.pop();
        }
        else{
            answer++;
            int k = q.front();

            cur_score-=k;
            q.pop();

        }
    }

    cout<<answer<<"\n";





}