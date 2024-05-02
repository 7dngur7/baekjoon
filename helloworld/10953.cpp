#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int cnt;
    string a;
    int answer;
    cin>>cnt;

    for(int i=0;i<cnt;i++){
        cin>> a;
        answer = (int)a[0]+ (int)a[2] - 48 - 48;
        cout<<answer<<"\n";
    }

}