#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<pair<int,int> > q;
int savecost[200005] = {};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    q.push(make_pair(n,0));

    int answerflag = -1;

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int curx = cur.first;
        int curcost = cur.second;

        for(int i=0; i<3; i++){
            int newx;
            int newcost = curcost+1;
            if(i==0){
                newx = curx+1;
            }
            else if(i==1){
                newx = curx-1;
            }
            else{
                newx = curx*2;
            }

            if(newx >200005 || newx<0) continue;
            if(savecost[newx]!=0 && savecost[newx]<newcost) continue;

            savecost[newx]=newcost;
            if(newx==k){
                answerflag = newx;
                break;
            }
            q.push(make_pair(newx,newcost));
            
        }

        if(answerflag>=0){
            break;
        }
    }

    cout<<savecost[k]<<"\n";

    int lastcost = savecost[k];

    while(answerflag!=n){
        if(answerflag%2==0 && savecost[answerflag/2] == lastcost-1){
            cout<<answerflag<<" ";
            answerflag /= 2;
            lastcost--;
        }
        else if(answerflag-1 >=0 && savecost[answerflag-1] == lastcost-1){
            cout<<answerflag<<" ";
            answerflag -= 1;
            lastcost--;
        }
        else if(answerflag+1<=200005 && savecost[answerflag+1] == lastcost-1){
            cout<<answerflag<<" ";
            answerflag += 1;
            lastcost--;
        }
    }
    cout<<"\n";


}