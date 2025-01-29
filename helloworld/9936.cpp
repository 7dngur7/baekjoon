#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<char> strvector;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string curstr, bombstr;
    cin>>curstr>>bombstr;

    string answer;

    for(int i=0; i<curstr.size(); i++){
        answer.push_back(curstr[i]);

        int bombflag = 1;
        if(answer.size()>=bombstr.size()){
            for(int j=0; j<bombstr.size(); j++){
                if(answer[answer.size()-1-j] != bombstr[bombstr.size()-1-j]){
                    bombflag = 0;
                    break;
                }
            }
            if(bombflag>0){
                for(int i=0; i<bombstr.size(); i++){
                    answer.pop_back();
                }
            }
        }
    }

    // cout<<answer<<" "<<answer.size();
    if(answer.size()==0){
        cout << "FRULA\n";
    } else {
        cout << answer << "\n";
    }

    // for(int i=0; i<curstr.length(); i++){
    //     strvector.push_back(curstr[i]);
    // }

    // int flag = 0;
    // do{
    //     flag = 0;
    //     int chkarr[1000000]={};
    //     stack<char> cur; 

    //     int chkbomb = 0;
    //     for(int i=0; i<strvector.size(); i++){
    //         if(strvector[i]==bombstr[chkbomb]){
    //             chkbomb += 1;
    //             chkarr[i] = chkbomb;
    //         }
    //         else if(strvector[i]==bombstr[0]){
    //             chkbomb = 1;
    //             chkarr[i] = chkbomb;
    //         }
    //         else{
    //             chkbomb = 0;
    //         }
    //     }

    //     // cout<<"test: ";
    //     // for(int i=0; i<strvector.size(); i++){
    //     //     cout<<chkarr[i]<<" ";
    //     // }
    //     // cout<<"\n";

    //     for(int i=strvector.size()-1; i>=0; i--){
    //         if(chkarr[i]==bombstr.size()){
    //             // cout<<"chk: "<<i<<"\n";
    //             i-=bombstr.size()-1;
    //             flag =1;
    //         }
    //         else{
    //             // cout<<"push: "<<strvector[i]<<"\n";
    //             cur.push(strvector[i]);
    //         }
    //     }

    //     // cout<<"test: ";
    //     // for(int i=0; i<strvector.size(); i++){
    //     //     cout<<chkarr[i]<<" ";
    //     // }
    //     // cout<<"\n";

    //     strvector.clear();
    //     while(!cur.empty()){
    //         //  cout<<"cur: "<<cur.top()<<"\n";
    //         strvector.push_back(cur.top());
    //         cur.pop();
    //     }

    //     // for(int i=strvector.size()-1; i>=0; i--){
            
    //     //     cout<<strvector[i]<<"";
    //     // }
    //     // cout<<"\n";
    // }
    // while(flag > 0);

    // if(strvector.size()==0){
    //     cout<<"FRULA\n";
    // }
    // else{
    //     for(int i=0; i<strvector.size(); i++){
            
    //         cout<<strvector[i]<<"";
    //     }
    //     cout<<"\n";
    // }
}