#include <iostream>
#include <queue>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int checkarr[101] = {};
    int gamearr[101]= {};
    int dice[6] = {1,2,3,4,5,6};
    queue<int> q;
    int checkcnt = 0, answercnt = 0;
    int sixcount=0;

    int a, b;
    cin>>a>>b;
    for(int i = 0; i<a+b; i++){
        int c, d;
        cin>>c>>d;
        gamearr[c] = d;
    }

    q.push(1);
    checkarr[1] = 0;
    while(!q.empty()){
        int curplace = q.front();
        q.pop();
        for(int i = 0; i<6; i++){
            int newplace = curplace + dice[i];
            if(gamearr[newplace] !=0){
                newplace = gamearr[newplace];
            }
            if(newplace>100||newplace<1)continue;
            if(checkarr[newplace] !=0)continue;

            if(newplace == 100){
                checkcnt = 1;
                checkarr[100] = checkarr[curplace]+1;
                break;
            }
            q.push(newplace);
            checkarr[newplace] = checkarr[curplace]+1;
            answercnt ++;

        }

        if(checkcnt){
            cout<<checkarr[100]<<endl;
            break;
        }



    }

}