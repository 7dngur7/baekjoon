#include <iostream>
#include <vector>

using namespace std;

int arr[500002]={};

int get_parent(int a){
    if(arr[a]==a) return a;

    return arr[a] = get_parent(arr[a]);
}

void union_parent(int a, int b){
    a = get_parent(a);
    b = get_parent(b);

    if(a<b){
        arr[b]=a;
    }
    else{
        arr[a]=b;
    }
}

int find_parent(int a, int b){
    a = get_parent(a);
    b = get_parent(b);

    if(a==b){
        return 1;
    }
    else{
        return 0;
    }
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin>>n>>m;

    int answer = 0;

    for(int i=0; i<n; i++){
        arr[i]=i;
    }


    for(int i=1; i<=m; i++){
        int a, b;
        cin>>a>>b;

        if(answer == 0){
            if(get_parent(a)==get_parent(b)){
                answer = i;
            }
            else{
                union_parent(a,b);
            }

        }

        // cout<<i<<": ";
        // for(int j=0; j<n; j++){
        //     cout<<arr[j]<<" ";

        // }
        // cout<<"\n";

    }

    cout<<answer<<"\n";


}