#include <iostream>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

vector< vector<int> > arr(32001);
deque<int> ans;
int chkarr[32001] = {};
int indegree[32001] = {};
queue<int> q;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // 간선 정보 입력
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        arr[a].push_back(b);
        indegree[b]++;
    }

    // 진입 차수가 0인 노드를 큐에 추가
    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0){
            q.push(i);
            chkarr[i] = 1;
        }
    }

    // 위상 정렬 수행
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        ans.push_back(cur);

        for(int i = 0; i < arr[cur].size(); i++){
            int next = arr[cur][i];
            indegree[next]--;

            if(indegree[next] == 0 && chkarr[next] == 0){
                q.push(next);
                chkarr[next] = 1;
            }
        }
    }

    // 결과 출력
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}
