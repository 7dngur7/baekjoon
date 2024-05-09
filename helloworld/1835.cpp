#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt;
    cin>>cnt;
    deque<int> deq;

    for(int i = cnt; i>0; i--){
        deq.push_front(i);
        for(int j = 0 ; j<i; j++){
            int savenum = deq.back();
            deq.pop_back();
            deq.push_front(savenum);
        }


    }

    for(int i = 0; i<deq.size(); i++){
        cout<<deq[i]<<" ";
    }
    cout<<endl;
    return 0;

}