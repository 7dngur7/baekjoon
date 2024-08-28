#include <iostream>
#include<algorithm>
using namespace std;

int main(void){
    int n;
    long long m;
    cin>>n>>m;
    long long answer=-1;
    long long arr[100002]={};

    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    int lowpnt=0, highpnt=0;

    for(int i=0; i<n; i++){
        lowpnt=i;
        highpnt=i;
        while(arr[highpnt]-arr[lowpnt]<m && highpnt<n){
            highpnt++;
        }
        if(highpnt==n) break;
        if(answer<0){
            answer = arr[highpnt]-arr[lowpnt];
        }
        answer = min(answer, arr[highpnt]-arr[lowpnt]);
    }

    cout<<answer<<endl;


}