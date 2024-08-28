#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector< vector<int> > v(100005);

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int costarr[1002] = {};
        int priorarr[1001] = {};
        int dp[1001] = {};
        int n, k;
        cin >> n >> k;

        for(int j = 1; j <= n; j++) {
            cin >> costarr[j];
        }
        for(int j = 0; j < k; j++) {
            int a, b;
            cin >> a >> b;
            priorarr[b]++;
            v[a].push_back(b);
        }

        int w;
        cin >> w;

        queue<int> q;
        for(int j = 1; j <= n; j++) {
            if(priorarr[j] == 0) {
                q.push(j);
                dp[j] = costarr[j];  // 초기 비용 설정
            }
        }

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            for(int next : v[curr]) {
                dp[next] = max(dp[next], dp[curr] + costarr[next]);
                priorarr[next]--;
                if(priorarr[next] == 0) {
                    q.push(next);
                }
            }
        }

        cout << dp[w] << "\n";

        for(int j = 1; j <= n; j++) {
            v[j].clear();
        }
    }

    return 0;
}
