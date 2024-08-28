#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque< pair<int, int> > d;

    int n, l;
    cin>>n>>l;

    for(int i=1; i<=n; i++){
        if(!d.empty() && d.front().first<=i-l){
            d.pop_front();
        }

        int a;
        cin>>a;
        while(!d.empty() && d.back().second >= a){
            d.pop_back();
        }

        d.push_back(make_pair(i,a));

        cout<<d.front().second<<" ";
    }
    cout<<"\n";
}