#include <iostream>

using namespace std;

int arr[100005]={};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin>>n>>k;

    int startchk = 0;
    int startnum = 0;
    int plusnum = 0;
    while(startchk<k){
        if(startnum>=n){
            startchk += --plusnum;
            startnum++;
        }
        else{
            startchk += ++plusnum;
            startnum++;
        }

    }

    for(int i=1; i<=n;i++){
        arr[i]=1;
    }

    int curchknum = startchk-plusnum;

    startnum--;
    //cout<<--startnum<<" "<<curchknum<<"\n";

    int delcnt = 0;
    int delnum = 0;

    for(int i=startnum; i>0; i--){
        arr[i] += ++delcnt;
    }

    for(int i=1; i<=n; i++){
        if(arr[i]>n){
            delnum++;
        }
    }

    // cout<<delnum<<"\n";

    // for(int i=1; i<=n; i++){
    //     cout<<arr[i]<<" ";
    // }
    //cout<<"\n";

    pair<int,int> answer = make_pair(-1,-1);
    for(int i=curchknum+1; i<=k; i++){
        for(int j = delnum+1; j<=n; j++){
            if(answer.first == -1){
                answer.first = arr[j];
                answer.second = j;
            }
            else{
                if(answer.first * answer.second>arr[j]*j){
                    answer.first = arr[j];
                    answer.second = j;
                }
            }
        }
        if(++arr[answer.second]>n){
            delnum++;
        }
    }

    cout<<answer.first*answer.second<<"\n";




}