#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, p;
    long long answer = 1;
    cin>> n >>p;
    for(int i = 1; i<=n; i++){
        answer *= (long long)i % p ;
        answer %= p;
    }

    answer %= p;
    cout<<answer<<endl;



}