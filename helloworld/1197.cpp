#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int grparr[10005]={};
vector< tuple<int,int,int> > arr;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int v, e;
    cin>>v>>e;

    for(int i=0; i<e; i++){
        int a, b, c;
        
        cin>>a>>b>>c;

        arr.push_back(make_tuple(c,a,b));
    }

    sort(arr.begin(), arr.end());

    int answer = 0;
    int grpcnt = 1;

    for(int i=0; i<e; i++){
        auto cur = arr[i];
        int c = get<0>(cur);
        int a = get<1>(cur);
        int b = get<2>(cur);

        if(grparr[a]!=0&&grparr[b]!=0&&grparr[a]==grparr[b])continue;

        answer += c;

        if(grparr[a]==0&&grparr[b]==0){
            grparr[a]=grpcnt;
            grparr[b]=grpcnt++;
        }
        else if(grparr[a]==0){
            grparr[a]= grparr[b];
        }
        else if(grparr[b]==0){
            grparr[b]= grparr[a];
        }
        else{
            int grpnum = grparr[b];
            for(int i=1; i<=v; i++){
                if(grparr[i]== grpnum){
                    grparr[i]= grparr[a];
                }
            }
        }


    }

    cout<<answer<<"\n";

    // for(int i=0; i<arr.size(); i++){
    //     auto a = arr[i];

    //     cout<<get<0>(a)<<" "<<get<1>(a)<<" "<<get<2>(a)<<"\n";
    // }


}