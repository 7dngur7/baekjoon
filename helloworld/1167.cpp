#include <iostream>
#include <stack>

using namespace std;

int arr[100005][100005];
int chkarr[100005][100005];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int v;
    cin>>v;

    int state = 1;
    int breakcnt = 0;

    for(int i=1; i<=v; i++){
        int a, value;
        cin>>a;
        while(1){
            cin>>a;
            if(a==-1) break;
            cin>>value;
            arr[i][a]=value;
        }
    }


    // for(int i=1; i<=v; i++){
    //     for(int j=1; j<=v; j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //      cout<<"\n";

    // }
    // cout<<"\n";
    int answer =0;
    for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            if(arr[i][j]!=0){
                stack< pair<int,int> >s;
                int curarr[100005]={};
                int curanswer = 0;

                curarr[i] = 1;
                s.push(make_pair(i,j));
                curanswer += arr[i][j];

                int prei=0, prej=0;

                while(!s.empty()){
                    pair<int,int> cur = s.top();
                    s.pop();
                    int curi= cur.first;
                    int curj= cur.second;
                    curarr[curj]= 1;


                    for(int k=1; k<=v; k++){
                        if(curarr[k]==1)continue;
                        if(arr[curj][k]==0)continue;
                        
                        s.push(k);
                    }
                    curarr[curj]=0;

                }

            }
        }
    }

}