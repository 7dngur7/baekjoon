#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

class cmp {
public:
    bool operator()(int a, int b) {
        return a > b;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        int k;
        cin >> k;

        priority_queue<int> highq;
        priority_queue<int, vector<int>, cmp> lowq;
        unordered_map<int, int> m;

        for (int i = 0; i < k; ++i) {
            char op;
            int n;
            cin >> op >> n;

            if (op == 'I') {
                highq.push(n);
                lowq.push(n);
                m[n]++;
            } else {
                if (n == 1) { // 최댓값 삭제
                    while (!highq.empty() && m[highq.top()] == 0) {
                        highq.pop();
                    }
                    if (!highq.empty()) {
                        int maxVal = highq.top();
                        highq.pop();
                        m[maxVal]--;
                    }
                } else { // 최솟값 삭제
                    while (!lowq.empty() && m[lowq.top()] == 0) {
                        lowq.pop();
                    }
                    if (!lowq.empty()) {
                        int minVal = lowq.top();
                        lowq.pop();
                        m[minVal]--;
                    }
                }
            }
        }

        // 최종 출력
        while (!highq.empty() && m[highq.top()] == 0) {
            highq.pop();
        }
        while (!lowq.empty() && m[lowq.top()] == 0) {
            lowq.pop();
        }

        if (highq.empty() || lowq.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << highq.top() << " " << lowq.top() << "\n";
        }
    }

    return 0;
}
