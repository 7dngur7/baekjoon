#include <iostream>
#include <cmath>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin>>n;

    long long  left = 0;
    long long right = n;
    long long mid;
    while(left+1<right){
        mid = (left+right)/2;
        //cout<<mid<<"\n";
        if((mid >= ((long long int)3037000500)) ||mid*mid>=n){
            right = mid;
        }
        else{
            left = mid;
        }

    }

    cout<<right<<"\n";
    




}