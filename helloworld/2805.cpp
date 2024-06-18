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
    long long right = -1;

    long long trees[1000005]={};

    for(int i = 0; i<n; i++){
        cin>>trees[i];
        if(trees[i]>right) right = trees[i];

    }

    while(left+1<right){
        long long mid = (left+right)/2;
        long long cur_tree = 0;
        for(int i = 0 ;i<n; i++){
            int a = trees[i] - mid;

            if(a>0){
                cur_tree += a;
            }
        }

       // cout<<"mid: "<<mid<<", curtree: "<<cur_tree<<"\n";

        if(cur_tree>m) left = mid;
        if(cur_tree<m) right = mid;

        if(cur_tree == m){
            cout<<mid<<"\n";
            return 0;
        }

    }

    cout<<left<<"\n";

}