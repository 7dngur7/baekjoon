// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int cinarr[102]={};
// vector< pair<int,int> >arr;
// int ans[10001][102]={};

// bool cmp(pair<int,int> a, pair<int,int> b){
//     if(a.second==b.second){
//         return a.first>b.first;
//     }
//     return a.second<b.second;
// }


// int main(void){
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int n, m;
//     cin>>n>>m;

//     for(int i=0; i<n; i++){
//         cin>>cinarr[i];
//     }
//     for(int i=0; i<n; i++){
//         int a;
//         cin>>a;
//         arr.push_back(make_pair(cinarr[i], a));
//     }

//     sort(arr.begin(), arr.end(), cmp);

//     for(int j=0; j<arr.size(); j++){
//         for(int i=0; i<=m; i++){
//             ans[j][i]=-1;
//         }
//     }
//     //첫 번째 인덱스
//     for(int i=0; i<=arr[0].first; i++){
//         ans[0][i] = arr[0].second;

//     }

//     for(int j=1; j<arr.size(); j++){
//         for(int i=0; i<=m; i++){
//             if(i<=arr[j].first){
//                 if(ans[j-1][i]<0){
//                     ans[j][i]=arr[j].second;
//                 }
//                 else{
//                     ans[j][i]=min(arr[j].second, ans[j-1][i]);
//                 }
//             }
//             else{
//                 if(ans[j-1][i-arr[j].first]<0) {
//                     cout<<"break: "<<j-1<<" "<<i-arr[j].first<<" "<<i<<"\n";
//                     break;
//                 }
//                 if(ans[j-1][i]<0){
//                     ans[j][i]=ans[j-1][i-arr[j].first]+arr[j].second;
//                 }
//                 else{
//                     ans[j][i]=min(ans[j-1][i], ans[j-1][i-arr[j].first]+arr[j].second);
//                 }
//             }
            























//             // int cnt = 0;
//             // while(arr[cnt].second>i){
//             //     //인덱스 음수, 처음
//             //     if(ans[0][i]==-1 && i-arr[cnt].first<0){
//             //         ans[0][i]=arr[cnt].second;
//             //     }
//             //     //인덱스 양수, 처음
//             //     else if(ans[0][i]==-1){
//             //         ans[0][i]= i-arr[cnt].first+arr[cnt].second;
//             //     }
//             //     //인덱스 음수
//             //     else if(i-arr[cnt].first<0){
//             //         ans[0][i]= min(ans[0][i], arr[cnt].second);
//             //     }
//             //     //인덱스 양수
//             //     else{
//             //         //ans[i]= min(ans[i], i-arr[cnt].first+arr[cnt].second);
//             //     }

//             //     cnt++;
//             // }

//             // if(ans[0][i]==-1){
//             //     ans[0][i]=0;
//             // }
//         }
//     }

//     for(int j=0; j<arr.size(); j++){
//         for(int i=0; i<=m; i++){
//             cout<<ans[j][i]<<" ";
//         }
//         cout<<"\n";
//     }
//     cout<<ans[arr.size()-1][m]<<"\n";

// }

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> memory(n); 
    vector<int> cost(n);

    for (int i = 0; i < n; i++) {
        cin >> memory[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    vector<int> dp(10001, 0);

    for (int i = 0; i < n; i++) {
        // 큰 비용부터 처리해야 이전 단계의 값이 덮어쓰여지지 않음
        for (int j = 10000; j >= cost[i]; j--) {
            dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]);
        }
    }

    for (int j = 0; j <= 10000; j++) {
        if (dp[j] >= m) {
            cout << j << "\n"; 
            break;
        }
    }

    return 0;
}
