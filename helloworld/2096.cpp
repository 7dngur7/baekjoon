#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    
    int minarr[3]={};
    int maxarr[3]={};

    cin>>maxarr[0]>>maxarr[1]>>maxarr[2];
    minarr[0]=maxarr[0];
    minarr[1]=maxarr[1];
    minarr[2]=maxarr[2];

    for(int i=1; i<n; i++){
        int a,b,c;
        cin>>a>>b>>c;
        
        int amax=max(maxarr[0]+a, maxarr[1]+a);
        int curmax = max(maxarr[0]+b, maxarr[1]+b);

        int bmax=max(curmax,maxarr[2]+b);
        int cmax=max(maxarr[1]+c,maxarr[2]+c);
        maxarr[0]=amax;
        maxarr[1]=bmax;
        maxarr[2]=cmax;

        //cout<<"maxarr: "<<maxarr[0]<<" "<<maxarr[1]<<" "<<maxarr[2]<<"\n";

        int amin=min(minarr[0]+a, minarr[1]+a);
        int bmin=min(min(minarr[0]+b, minarr[1]+b),minarr[2]+b);
        int cmin=min(minarr[1]+c,minarr[2]+c);

        minarr[0]=amin;
        minarr[1]=bmin;
        minarr[2]=cmin;
        //cout<<"minarr: "<<minarr[0]<<" "<<minarr[1]<<" "<<minarr[2]<<"\n";

    }

    cout<<max(max(maxarr[0],maxarr[1]),maxarr[2])<<" "<<min(min(minarr[0],minarr[1]),minarr[2])<<"\n";


}



// queue< pair<int,int> > q;

// int arr[100005][3] = {};
// int chkarr[100005][3] = {};

// int xarr[3] = {-1, 0, 1};

// int main(void) {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int n;

//     cin >> n;

//     for (int i = 0; i < n; i++) {
//         cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
//     }

//     // 최대값 계산
//     chkarr[0][0] = arr[0][0];
//     chkarr[0][1] = arr[0][1];
//     chkarr[0][2] = arr[0][2];

//     q.push(make_pair(0, 0));
//     q.push(make_pair(0, 1));
//     q.push(make_pair(0, 2));

//     while (!q.empty()) {
//         pair<int, int> cur = q.front();
//         q.pop();

//         for (int i = 0; i < 3; i++) {
//             int newx = cur.second + xarr[i];
//             int newy = cur.first + 1;

//             if (newx < 0 || newx > 2 || newy >= n) continue;
//             if (chkarr[cur.first][cur.second] + arr[newy][newx] < chkarr[newy][newx]) continue;

//             chkarr[newy][newx] = chkarr[cur.first][cur.second] + arr[newy][newx];
//             q.push(make_pair(newy, newx));
//         }
//     }

//     int maxans = 0;
//     maxans = max(chkarr[n-1][1], chkarr[n-1][0]);
//     maxans = max(maxans, chkarr[n-1][2]);

//     cout << maxans << " ";

//     // chkarr 초기화
//     for (int i = 0; i < n; i++) {
//         chkarr[i][0] = 0;
//         chkarr[i][1] = 0;
//         chkarr[i][2] = 0;
//     }

//     // 최소값 계산
//     chkarr[0][0] = arr[0][0];
//     chkarr[0][1] = arr[0][1];
//     chkarr[0][2] = arr[0][2];

//     q.push(make_pair(0, 0));
//     q.push(make_pair(0, 1));
//     q.push(make_pair(0, 2));

//     while (!q.empty()) {
//         pair<int, int> cur = q.front();
//         q.pop();

//         for (int i = 0; i < 3; i++) {
//             int newx = cur.second + xarr[i];
//             int newy = cur.first + 1;

//             if (newx < 0 || newx > 2 || newy >= n) continue;
//             if (chkarr[newy][newx] != 0 && chkarr[cur.first][cur.second] + arr[newy][newx] > chkarr[newy][newx]) continue;

//             if (chkarr[newy][newx] == 0) {
//                 chkarr[newy][newx] = chkarr[cur.first][cur.second] + arr[newy][newx];
//             } else {
//                 chkarr[newy][newx] = min(chkarr[cur.first][cur.second] + arr[newy][newx], chkarr[newy][newx]);
//             }

//             q.push(make_pair(newy, newx));
//         }
//     }

//     int minans = 0;
//     minans = min(chkarr[n-1][1], chkarr[n-1][0]);
//     minans = min(minans, chkarr[n-1][2]);

//     cout << minans << "\n";
// }
