#include <iostream>

using namespace std;

int num[1005]={};
int ans[1005] = {};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    ans[0] = 1;

    //다 돌면서 자기보다 작고 숫자가 가장 큰거 찾기?
    for(int i=0; i<n; i++){
        cin>>num[i];

        int cmpint = 0;
        int cmpnum = num[i];


        for(int j = 0; j<i; j++){
            if(num[j]<cmpnum && ans[j]>cmpint){
                cmpint = ans[j];
            }
        }

        if(cmpint == 0){
            ans[i] = 1;
        }
        else{
            ans[i] = cmpint +1;
        }


    }

    int finans = 0;

    for(int i=0; i<n; i++){
        if(ans[i]>finans){
            finans = ans[i];
        }
    }

    cout<<finans<<"\n";

}