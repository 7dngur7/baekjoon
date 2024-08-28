#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// class cmp{
// public:
//     bool operator() (pair<int,int> a, pair<int,int> b){
//         int a1 = a.first;
//         int a2 = a.second;
//         int b1 = b.first;
//         int b2 = b.second;

//         if(a1<b1){
//             return true;
//         }
//         if(a1==b1 && a2<b2 ){
//             return true;
//         }

//         return false;
        
//     }


// };

// int main(void){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     priority_queue< pair<int, int>, vector< pair<int,int> >, cmp> q;
//     queue< pair<int,int> > saveq;

//     int n;
//     cin>>n;

//     for(int i=0; i<n; i++){
//         int a, b;

//         cin>>a>>b;
//         q.push(make_pair(a,b));

//     }

//     q.push(make_pair(0,0));
//     int answer= 0;

//     for(int i=n; i>0; i--){
//         pair<int,int> curans = make_pair(0,0);

//         while(1){
//             pair<int,int> cur = q.top();
//             q.pop();

//             saveq.push(cur);

//             //  cout<<cur.first<<" "<<cur.second<<"\n";
//             //  cout<<cur.first<<" "<<i<<"\n";

//             if(cur.first>=i){
//                 if(curans.second<cur.second){
//                     curans = cur;
//                 }
//             }
//             else{
//                 while(!saveq.empty()){
//                     if(saveq.front()==curans) {
//                         saveq.pop();
//                         continue;
//                     }
//                     q.push(saveq.front());
//                     saveq.pop();
//                 }
//                 break;
//             }

//         }

//         //cout<<"curans: "<<curans.first<<" "<<curans.second<<"\n";
//         answer +=curans.second;

//     }

//     // for(int i=0; i<n; i++){
        
//     //     pair<int,int> cur = q.top();
//     //     q.pop();

//     //     cout<<cur.first<<" "<<cur.second<<"\n";

//     // }

//     cout<<answer<<"\n";


// }

    vector< vector<int> > arr(200001);
    priority_queue<int> q;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    int answer = 0;

    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        arr[a].push_back(b);
    }

    for(int i=200001; i>0; i--){
        for(int j=0; j<arr[i].size(); j++){
            q.push(arr[i][j]);
        }

        if(q.empty())continue;
        //cout<<"answer: "<<answer<<"\n";
        answer += q.top();
        q.pop();

    }
    cout<<answer<<"\n";

}