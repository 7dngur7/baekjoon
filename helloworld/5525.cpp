#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    string s;
    string pstr = "I";
    cin>>n>>m>>s;

    for(int i=0; i<n; i++){
        pstr.append("O");
        pstr.append("I");
    }

    for(int i=0; i<m; i++){
        if(s[i]=='I'){
            q.push(i);
        }
    }

    int ans = 0;
    
    while (!q.empty()){
        int cur = q.front();
        q.pop();

        int anschk = 1;
        for(int i=0; i<n; i++){
            if(s[cur+1+i*2] != 'O' || s[cur+2+i*2]!='I'){
                anschk=0;
                break;
            }

        }
        if(anschk == 1){
            ans++;
        }

    }

    cout<<ans<<"\n";

}