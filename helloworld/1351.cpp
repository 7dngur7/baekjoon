#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> map;

long long n, p, q;


long long myfind(long long a){
    // 찾으면
    if(map.find(a) != map.end()){
        return map[a];
    }
    else{
        map[a] = myfind(a/p) + myfind(a/q);
        return map[a];
    }


}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin>>n>>p>>q;

    map[0] = 1;

    myfind(n);

    cout<<map[n]<<"\n";
}