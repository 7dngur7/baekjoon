#include <iostream>
#include <map>
#include <vector>
#include<algorithm>

using namespace std;

bool comapare1(pair<string, int> a, pair<string,int>b){
    return a.first.length()>b.first.length();

}

bool comapare2(pair<string, int> a, pair<string,int>b){
    return a.second>b.second;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin>>n>>m;

    map <string, int> mmap;

    for(int i=0; i<n; i++){
        string a;
        cin>>a;
        if(mmap.find(a)==mmap.end()){
            mmap.insert(make_pair(a, 1));
        }
        else{
            mmap[a]++;
        }
    }

    vector< pair<string,int> > v(mmap.begin(), mmap.end());



    stable_sort(v.begin(), v.end(), comapare1);



    stable_sort(v.begin(), v.end(), comapare2);



    for(int i=0; i<v.size(); i++){
        if(v[i].first.length()>=m){
            cout<<v[i].first<<"\n";
            }

    }




}