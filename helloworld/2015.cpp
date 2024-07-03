#include <iostream>
#include <map>


using namespace std;
long long a[2000005]={};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n,k;
    map<long long, long long>m;

    cin>>n>>k;

    for(int i=1; i<=n; i++){
        long long aa;
        cin>>aa;

        a[i]= a[i-1]+aa;

    }
    long long answer = 0;
    for(int i=1; i<=n; i++){
        if(a[i]-k==0) answer++;

        answer += m[a[i] - k];

        m[a[i]]++;
//더해온 값에서 k 뺀 값을 만들 수 있는게 있었으면 개수만큼 더 만들 수 있음 따라서 하나 더함

    }

    cout<<answer<<"\n";



}