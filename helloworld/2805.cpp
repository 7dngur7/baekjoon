#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
ios::sync_with_stdio(0);
cin.tie(0);

long long cnt, tree;
cin>>cnt>>tree;
vector<long long> v;

for(int i = 0 ; i<cnt; i++){
    long long k;
    cin>>k;
    v.push_back(k);
}
if(cnt == 1){
    cout<<v[0] - tree<<"\n";
    return 0;
}
sort(v.begin(), v.end());

v.push_back(0);

long long biggest = v[cnt-1];

long long bigger, smaller;

long long answer[biggest+2];

for(int i = 0; i<=biggest; i++){
    answer[i]=(0);
}

for(int i = 1; i<cnt; i++){
    
    bigger = v[cnt-i];
    smaller = v[cnt-i-1];
    
    //cout<<bigger<<" "<<smaller<<"\n";
     //cout<<cnt-i<<" "<<cnt-i-1<<"\n";
     //cout<<v[cnt-i]<<" "<<v[cnt-i-1]<<"\n";

    for(int j = smaller+1 ; j<=bigger; j++){
        answer[j]=i;
    }
}
for(int j = 1 ; j<=smaller; j++){
    answer[j]=cnt;
}
int answercnt = 0;
for(long long i = biggest; i>=0; i --){
    if (answercnt>=tree) {
       cout<<i<<"\n";
        return 0;
    }
    //cout<<i<<":"<<answer[i]<<"\n";
    answercnt += answer[i];

}

}