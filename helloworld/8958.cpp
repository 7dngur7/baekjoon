#include <iostream>
#include <queue>

using namespace std;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m;

    cin>>m;

    for(int i=0; i<m; i++){
        string quiz;
        cin>>quiz;

        int answer = 0;
        int morescore = 0;


        for(int j=0; j<quiz.length(); j++){
            if(quiz[j]=='X'){
                morescore = 0;
            }
            else{
                answer+= ++morescore;
            }
            //cout<<answer<<" : "<<morescore<<"\n";
        }

        cout<<answer<<"\n";
    }

}