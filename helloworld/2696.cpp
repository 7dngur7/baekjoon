#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T > 0){
        priority_queue<int, vector<int>, greater<int>> high;
        priority_queue<int, vector<int>, less<int>> low;
        T--;
        int m;
        cin >> m;
        int cnt = 0;
        cout << (m + 1) / 2 << endl;
        for(int i = 0; i < m; i++){
            int n;
            cin >> n;
            if (low.empty() || n <= low.top()) {
                low.push(n);
            } else {
                high.push(n);
            }

            if (low.size() > high.size() + 1) {
                high.push(low.top());
                low.pop();
            } else if (high.size() > low.size()) {
                low.push(high.top());
                high.pop();
            }
            if(i % 2 == 0){
                cout << low.top();
                if(i < m-1) cout << " ";
                cnt += 1;
                if(cnt == 10){
                    cout << endl;
                    cnt = 0;
                }
            }
        }
        cout << endl;
    }
}