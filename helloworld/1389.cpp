#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue< pair<int,int> > q;
vector< pair<int,int> >newarr;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;



        newarr.push_back(make_pair(a,b));
        newarr.push_back(make_pair(b,a));

    }

    pair<int,int> answerpair;
    answerpair = make_pair(-1,-1);

    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout<<arr[i][j]<<" ";

    //     }
    //     cout<<"\n";
    // }
    //     cout<<"\n";
    //     cout<<"\n";

    for(int i=1; i<=n; i++){
        int chkarr[101][101]={};

        for(int j=0; j<newarr.size(); j++){
            if(newarr[j].first==i){
                q.push(make_pair(i, newarr[j].second));
                chkarr[i][newarr[j].second]=1;
                chkarr[newarr[j].second][i]=1;

            }

        }        
        // for(int j=1; j<=n; j++){
        //             for(int k=1; k<=n; k++){

        //     cout<<  chkarr[j][k]<<" ";
        //             }
        //             cout<<"\n";

        // }

        while(!q.empty()){
            pair<int,int> cur = q.front();
            q.pop();

            int curx = cur.first;
            int cury = cur.second;

           // cout<<"curx cury: "<<curx<<" "<<cury<<"\n";


        for(int j=0; j<newarr.size(); j++){
            if(newarr[j].first==cury){
                if(chkarr[cury][newarr[j].second]!=0 &&chkarr[curx][cury]+1>chkarr[cury][newarr[j].second])continue;
                chkarr[cury][newarr[j].second] = chkarr[curx][cury]+1;
                chkarr[newarr[j].second][cury] =chkarr[curx][cury]+1;
                q.push(make_pair(cury,newarr[j].second ));
                //cout<<"curx cury222: "<<cury<<" "<<newarr[j].second<<"\n";

            }

        }   


        }
                    //각자 순서에 각자꺼에 맞는 것들을 큐에 삽입
            //꺼내서 뒤에꺼와 연결된 것들 전부 삽입
            //보다 작거나 하면 스킵


        int curanswer =0;
        for(int j=1; j<=n; j++){
            if (i==j) continue;
            int curcuranswer = -1;
            for(int k=1; k<=n; k++){
                if(chkarr[j][k]==0) continue;
                if(curcuranswer==-1){
                    curcuranswer = chkarr[j][k];
                }
                else{
                    curcuranswer = min(curcuranswer, chkarr[j][k]);

                }
            }

            curanswer+= curcuranswer;
        }

        // for(int j=1; j<=n; j++){
        //             for(int k=1; k<=n; k++){

        //     cout<<  chkarr[j][k]<<" ";
        //             }
        //             cout<<"\n";

        // }

        if(answerpair.first==-1){
            answerpair= make_pair(i, curanswer);
        }
        else if(answerpair.second>curanswer){
            answerpair= make_pair(i, curanswer);

        }
        //cout<<"\nanswer: "<<curanswer<<"\n";
    }

    cout<<answerpair.first<<endl;

    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout<<arr[i][j]<<" ";

    //     }
    //     cout<<"\n";
    // }

}