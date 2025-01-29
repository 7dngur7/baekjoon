#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>


using namespace std;

queue<int> checkfirstarr[102];
queue<int> checksecondarr[102];

priority_queue<int> firstarr;
priority_queue<int> secondarr;

int ansarr[200][200] = {};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);


    int a;
    cin>>a;

    for(int i=1; i<=a; i++){
        int x;
        cin>>x;

        checkfirstarr[x].push(i);
        firstarr.push(x);
    }

    int b;
    cin>>b;

    for(int i=1; i<=b; i++){
        int x;
        cin>>x;

        checksecondarr[x].push(i);
        secondarr.push(x);
    }

    int curfirstindex = -1;
    int cursecondindex = -1;

    queue<int> answerarr;

    while(!firstarr.empty() || !secondarr.empty()){
        if(firstarr.top()==secondarr.top()){
            //둘다 curindex보다 같거나작은 수들을 전부 뺐을 때 존재하면 ok
            while(!checkfirstarr[firstarr.top()].empty()&&checkfirstarr[firstarr.top()].front()<=curfirstindex){
                // cout<<"firstpop: "<<checkfirstarr[firstarr.top()].front()<<"  "<< curfirstindex<<"\n";
                checkfirstarr[firstarr.top()].pop();
            }
            while(checksecondarr[secondarr.top()].empty()&&checksecondarr[secondarr.top()].front()<=cursecondindex){
                // cout<<"secondpop: "<<checksecondarr[firstarr.top()].front()<<"\n";

                checksecondarr[firstarr.top()].pop();
            }

            if(!checkfirstarr[firstarr.top()].empty() && !checksecondarr[firstarr.top()].empty()){
                answerarr.push(firstarr.top());
                curfirstindex = checkfirstarr[firstarr.top()].front();
                cursecondindex = checksecondarr[firstarr.top()].front();
            }
            //아니면 넘어감?
            // cout<<"test1\n";
            firstarr.pop();
            secondarr.pop();
        }
        else if(firstarr.top()>secondarr.top()){
            // cout<<"test2\n";
            firstarr.pop();
        }
        else{
            // cout<<"test3\n";
            secondarr.pop();
        }
    }

    cout<<answerarr.size()<<"\n";
    while(!answerarr.empty()){
        cout<<answerarr.front()<<" ";
        answerarr.pop();
    }
    cout<<"\n";

    // while(!firstarr.empty()){
    //     cout<<firstarr.top()<<"\n";
    //     firstarr.pop();
    // }

    // //공통되는 최장부분수열을 찾음

    // int count = 0;
    // int countnum = -1;
    // for(int i=1; i<=a; i++){
    //     for(int j=1; j<=b; j++){
    //         if(firstarr[i-1]==secondarr[j-1] && firstarr[i-1]>=countnum){
    //             ansarr[i][j] = ansarr[i-1][j-1]+1;
    //             count = max(count, ansarr[i][j]);
    //             countnum = firstarr[i-1];
    //         }
    //         else{
    //             ansarr[i][j] = max(ansarr[i-1][j], ansarr[i][j-1]);
    //         }
    //     }
    // }

    // // for(int i=0; i<=a; i++){
    // //     for(int j=0; j<=b; j++){
    // //         cout<<ansarr[i][j]<<" ";
    // //     }
    // //     cout<<"\n";
    // // }

    // // cout<<"count: "<<count<<"\n";

    // int curcount = count-1;
    // int botharr[200] = {};
    // for(int i=a; i>0; i--){
    //     for(int j=b; j>0; j--){
    //         if((ansarr[i][j]!=ansarr[i-1][j]) && (ansarr[i][j]!= ansarr[i][j-1])){
    //             // cout<<"check: "<<i<<" "<<j<<" "<< firstarr[i]<<"\n";
    //             botharr[curcount--] = firstarr[i-1]; 
    //         }
    //     }
    // }

    // // for(int i=0; i<count; i++){
    // //     cout<<botharr[i]<<" ";
    // // }
    // // cout<<"\n";

    // //그 수열에서 가장 큰수, 그 뒤부터 가장 큰 수... 찾아감

    // //뒤에서부터 max를 갱신해가며 넣으면 되는것이었다 ㄷㄷ 말도안돼

    // stack<int> s;
    // int anscount = 0;
    // int curmax = -1;
    // for(int i=count-1; i>=0; i--){
    //     if(botharr[i]>=curmax){
    //         anscount++;
    //         s.push(botharr[i]);
    //         curmax = botharr[i];
    //     }
    // }

    // cout<<anscount<<"\n";
    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
    // cout<<"\n";

}