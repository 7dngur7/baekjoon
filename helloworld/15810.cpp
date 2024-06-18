#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin>>n>>m;

    long long left = 0;
    long long right = 1000000000005;

    long long staff[1000005]={};

    for(int i = 0; i<n; i++){
        cin>>staff[i];

    }

    while(left+1<right){
        long long mid = (left+right)/2;
        long long cur_baloon = 0;
        for(int i = 0 ;i<n; i++){
                cur_baloon += mid / staff[i];
        }

       // cout<<"mid: "<<mid<<", curtree: "<<cur_tree<<"\n";

        if(cur_baloon>=m) right = mid;
        if(cur_baloon<m) left = mid;


    }

    cout<<right<<"\n";

}