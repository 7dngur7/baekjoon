#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int> > >arr(1000002);
vector<int> ans(1000002);
vector<int> query;

void write_parent(int cur, int parent, int index){

    arr[parent][index].second = parent;

    for(int i=0; i<arr[cur].size(); i++){
        if(arr[cur][i].first==parent) continue;

        // cout<<"cur: "<<arr[cur][i].first<<"parent: "<<cur<<"\n";
        write_parent(arr[cur][i].first, cur, i);


    }
}

//자신의 자식들을 리턴
int write_answer(int cur){

    int curans = 1;

    if(arr[cur].size() == 1 &&  arr[cur][0].second == -1){
        ans[cur]=1;
        return 1;
    }

    for(int i=0; i<arr[cur].size(); i++){
        if(arr[cur][i].second == -1) continue;

        if(ans[arr[cur][i].first]==-1){
            curans += write_answer(arr[cur][i].first);
        }

    }

    // cout<<"writeanswer cur: "<<cur<<" curans: "<<curans<<"\n";
    ans[cur] = curans;
    return curans;

}




int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);

    //그럼 일단 연결관계를 전부 트리로 만듦

    //그러려면 일단 전부 pair로 연결해 놓고 뒤에 값을 parent로 함

    //전부 받고 루트부터 차례차례 parent 설정하는 로직 ㄱㄱ


    //이후 루트부터 시작해 재귀적으로 자기 번호 하위에 있는 노드들 배열에 적음


    //맨 밑바닥부터 하나씩 올라와야함(부모 외에 연결된 애들이 없는애부터)

    int n, r, q;

    cin>>n>>r>>q;

    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        arr[a].push_back(make_pair(b, -1));
        arr[b].push_back(make_pair(a, -1));

    }

    for(int i=0; i<q; i++){
        int a;
        cin>>a;
        query.push_back(a);
    }

    for(int i=1; i<=n; i++){
        ans[i]=-1;
    }

    for(int i=0; i<arr[r].size(); i++){
        write_parent(arr[r][i].first, r, i);
    }

    // for(int i=1; i<=n; i++){
    //     for(int j=0; j<arr[i].size(); j++){
    //         cout<<i<<":"<<arr[i][j].first<<" "<<arr[i][j].second<<"\n";

    //     }
    //     cout<<"-------\n";

    // }

    write_answer(r);

    // for(int i=1; i<=n; i++){
    //     cout<<i<<": "<<ans[i]<<"\n";
    // }

    for(int i=0; i<q; i++){
        cout<<ans[query[i]]<<"\n";
    }
    

}
