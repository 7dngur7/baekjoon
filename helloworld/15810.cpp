#include <iostream>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    long long biggest = 1000000000001;
    long long smallest = 0 ;
    long long answer = (biggest + smallest)/2;
    vector<int> v;

    int staff, baloon;
    cin>>staff>>baloon;

    for(int i = 0 ; i<staff; i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    long long savenum = 0;
    while(true){
        int balcnt = 0;
        for(int i = 0; i<staff; i++){
            int min = v[i];
            balcnt += answer/min;
        }

        if(balcnt > baloon){
            smallest = (answer + smallest)/2;
        }
        else if(balcnt<baloon){
            biggest = (answer + biggest)/2;
        }
        else if()

    }

    


}