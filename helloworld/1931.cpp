#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
vector< pair<long,long> > arr;
vector< pair<long, long> >ans;

// bool cmp(pair<long ,long> a, pair<long, long> b){
//     long anum=a.second-a.first;
//     long bnum = b.second-b.first;
//     return anum<bnum;
// }
bool cmp(pair<long ,long> a, pair<long, long> b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second<b.second;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long n;
    cin>>n;

    for(long i=0; i<n; i++){
        long a, b;

        cin>>a>>b;

        arr.push_back(make_pair(a, b));
    }

    sort(arr.begin(), arr.end(), cmp);

    long ans = 0;
    long lastnum = 0;

    for( int i=0; i<arr.size();i++){
        auto cur = arr[i];

        if(cur.first>=lastnum){
            ans++;
            lastnum = cur.second;
        }

    }

    cout<<ans<<"\n";


    //오답
    // for(int i=0; i<arr.size();i++){
    //     auto cur = arr[i];
    //     int chk = 0;
    //     for(int j=0; j<ans.size(); j++){
    //         auto anscur = ans[j];
    //         if(cur.first>=anscur.first && cur.first<anscur.second){
    //             chk =1;
    //             break;
    //         }
    //         if(anscur.first>=cur.first && anscur.first<cur.second){
    //             chk=1;
    //             break;
    //         }
    //     }
    //     if(chk==0){
    //         ans.push_back(cur);
    //     }
    // }
}