#include <iostream>
#include <queue>

using namespace std;

long arr[5];
queue<long>arr2;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string n;
    long numn; 


    cin>>n;

    if(n.size()>10){
        numn=1000000008;
    }
    else{
        numn = stoi(n);
    }
    arr[0] = 0;
    arr[1] = 1;
    arr2.push(0);
    arr2.push(1);

    for(long i=2; i<=numn; i++){
        long cur1 = arr2.front();
        arr2.pop();
        long cur2 = arr2.front();



        //cout<<"cur1 cur2: "<<cur1<<" "<<cur2<<"\n";

        long cur = -1000000007;
        cur = cur+cur1+cur2;
        if(cur<=0){
            arr2.push(cur+1000000007);
        }
        else{
            arr2.push(cur%1000000007);
        }
    }

    arr2.pop();
    cout<<arr2.front()<<"\n";



}