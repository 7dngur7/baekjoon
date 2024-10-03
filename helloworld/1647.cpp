#include<iostream>
#include<vector>
#include <algorithm>
#include <tuple>

using namespace std;

vector<tuple<int,int,int> > v;
// int land[100002]={};

int parent[100002]={};

vector<int> ans;

// int main(void){
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int n, m;
//     cin>>n>>m;

//     for(int i=0; i<m; i++){
//         int a, b, c;
//         cin>>a>>b>>c;

//         v.push_back(make_tuple(c,a,b));

//     }

//     for(int i=1; i<=n; i++){
//         land[i]=-1;
//     }

//     sort(v.begin(), v.end());


//     for(int i=0; i<m-1; i++){
//         int cost = get<0>(v[i]);
//         int home1 = get<1>(v[i]);
//         int home2 = get<2>(v[i]);

//         if(land[home1]==-1 && land[home2]==-1){
//             land[home1]=home1;
//             land[home2]=home1;
//             // for(int i=1; i<=n; i++){
//             //     cout<<land[i]<<" ";
//             // }
//             // cout<<"1cost: "<<cost<<" "<<home1<<" "<<home2<<"\n";
//             ans.push_back(cost);
//         }
//         else if(land[home1]==-1){
//             land[home1]=land[home2];
//             //             for(int i=1; i<=n; i++){
//             //     cout<<land[i]<<" ";
//             // }
//             // cout<<"2cost: "<<cost<<" "<<home1<<" "<<home2<<"\n";

//             ans.push_back(cost);
//         }
//         else if(land[home2]==-1){
//             land[home2]=land[home1];
//             //             for(int i=1; i<=n; i++){
//             //     cout<<land[i]<<" ";
//             // }
//             // cout<<"3cost: "<<cost<<" "<<home1<<" "<<home2<<"\n";
//             ans.push_back(cost);
//         }
//         else{
//             if(land[home1]!=land[home2]){
//                 for(int j=1; j<=n; j++){
//                     if(land[j]==land[home2]){
//                         land[j]=land[home1];
//                     }
//                 }       
//             //                 for(int i=1; i<=n; i++){
//             //     cout<<land[i]<<" ";
//             // }      
//             //     cout<<"4cost: "<<cost<<" "<<home1<<" "<<home2<<"\n";
//                 ans.push_back(cost);
//             }
//         }
//     }

//     int realans = 0;
//     for(int i=0; i<ans.size()-1; i++){
//         realans+=ans[i];
//     }

//     cout<<realans;
// }

int find(int a){
    if(parent[a]==a) return a;
    return parent[a] = find(parent[a]);
}

void myunion(int a, int b){
    int afind = find(a);
    int bfind = find(b);

    if(afind!=bfind){
        parent[afind] = bfind;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;

        v.push_back(make_tuple(c,a,b));

    }

    for(int i=1; i<=n; i++){
        parent[i]=i;
    }

    sort(v.begin(), v.end());


    for(int i=0; i<m; i++){
        int cost = get<0>(v[i]);
        int home1 = get<1>(v[i]);
        int home2 = get<2>(v[i]);

        if(find(home1)!=find(home2)){
            myunion(home1, home2);
            ans.push_back(cost);
        }

    }

    int realans = 0;
    for(int i=0; i<ans.size()-1; i++){
        realans+=ans[i];
    }

    cout<<realans<<"\n";

}