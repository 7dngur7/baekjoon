#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long price[123123]={};
    long long distance[123123]={};
    long long citycnt;
    cin>>citycnt;
    long long answer = 0;

    for(int i = 0; i<citycnt-1; i++){
        cin>>distance[i];
    }

    for(int i=0; i<citycnt; i++){
        cin>>price[i];
    }
    long long lowest = price[0];

    for(int i=0; i<citycnt-1; i++){
        if(price[i]<lowest) lowest = price[i];

        answer+=lowest*distance[i];

    }

    cout<<answer<<endl;

}