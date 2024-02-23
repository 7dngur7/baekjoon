#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int  N, answer=0, placearr[200002]={}, arr[200002]={};
vector<pair<int, int> > pairarr;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    //pair로 만들어 넣기(앞뒤 바꿈)
    for(int i=0;i<N;i++){
        int a, b;
        cin>>a>>b;
        pairarr.push_back(make_pair(b,a));
    }

    sort(pairarr.begin(), pairarr.end());
    
    for(int i=0;i<pairarr.size();i++){
        int a = pairarr[i].second;
        while(a>0){
            if(placearr[a]==0){
                arr[a]=pairarr[i].first;
                placearr[a]++;
                break;
            }
            else{
                if(arr[a]<pairarr[i].first){
                    
                }
                int b = placearr[a];
                placearr[a]++;
                a-=b;
            }

        }
        
    }

    for(int i=0;i<N;i++){
        answer+=arr[i];
        // cout<<arr[i]<<" ";
    }

    cout<<answer<<endl;

}