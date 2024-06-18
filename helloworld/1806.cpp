#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[100005];
    int n, s;
    cin>>n>>s;
    int answer = -1;

    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    int lowpnt, highpnt=0;
    int curplus = arr[0];

    for(int i=0; i<n; i++){
        lowpnt=i;
        while(highpnt<n&&curplus<s) {
            highpnt++;

            if(curplus<s)curplus+=arr[highpnt];
        }
        if(highpnt==n) break;

        if(answer<0){
            answer = highpnt-lowpnt;
        }
        else{
            answer = min(answer,highpnt-lowpnt);
        }

        curplus -= arr[lowpnt];
       // cout<<highpnt<<" "<<lowpnt<<"\n";
    }

    if (answer<0){
            cout<<"0"<<endl;
    }
    else{
        cout<<answer+1<<endl;

    }
}