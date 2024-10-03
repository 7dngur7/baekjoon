#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> v;
int chkv[300001]={};

class cmp{
    public:
    bool operator()(pair<int,int>a, pair<int,int>b){
        return a.first>b.first;
    }
};

bool cmpfunc(int a, int b){
    return a<b;
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin>>n>>k;

    priority_queue<pair<int,int> , vector<pair<int,int> >, cmp >q;

    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;

        q.push(make_pair(a,b));
    }

    for(int i=0; i<k; i++){
        int a;
        cin>>a;

        v.push_back(a);
    }

    sort(v.begin(),v.end(), cmpfunc);

    int ans = 0;

    for(int i=0; i<k; i++){
        int cur = v[i];

        pair<int,int> curans;
        int curchk = 0;

        queue< pair<int,int> > saveq;


        while(!q.empty()){
            auto qcur = q.top();
            if(cur<qcur.first) break;

            q.pop();

            if(curchk == 0){
                curans = qcur;
                curchk = 1;
            }
            else if(qcur.second > curans.second){
                saveq.push(curans);
                curans = qcur;
            }
            else{
                saveq.push(qcur);
            }
        }
        if(curchk !=0){
            ans += curans.second;
        }

        while(!saveq.empty()){
            q.push(saveq.front());
            saveq.pop();
        }

    }



    cout<<ans<<"\n";

    // for(int i=0; i<n; i++){
    //     auto a = q.top();

    //     q.pop();
    //     cout<<a.first<<" "<<a.second<<"\n";
    // }

    // for(int i=0; i<k; i++){
    //     cout<<v[i]<<"\n";
    // }



}