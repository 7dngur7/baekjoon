#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;



int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    vector<int> v1;
    vector< pair<int,int> > v2;
    vector< pair<int,int> > answer;

    int index1 = 0, index2 = 0;
    cin>>a;
    for(int i = 0 ; i< a ; i ++){
        int k;
        cin >> k;
        v1.push_back(k);
    }

    cin>>b;
    for(int i = 0 ; i< b ; i ++){
        int k = 0;
        cin >> k;
        v2.push_back(make_pair(k, i));
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    while(index2!=b && index1 != a){

        if(v2[index2].first==v1[index1]){
            
            answer.push_back(make_pair(v2[index2].second+1, 1));
            index2 ++;
        }
        else if(v2[index2].first>v1[index1]){
            index1 ++ ; 

        }
        else if(v2[index2].first<v1[index1]){
            answer.push_back(make_pair(v2[index2].second+1, 0));
            index2 ++ ; 
        }

    }
    for(int i = 0; i< b; i++){
        answer.push_back(make_pair(0 , 0));
    }
    sort(answer.begin(), answer.end());
    int printcnt = 1, i = 0;
    while(printcnt<=b){
        if (answer[i].first == 0) {
            i++;
            continue;
        }
        //cout<<answer[i].first<<" "<<printcnt<<"<\n";
        if(answer[i].first==printcnt){
            cout<<answer[i].second<<"\n";
            printcnt++;
            i++;
        }
        else{
            cout<<"0\n";
            printcnt++;
        }
    }

    //cout<<printcnt<<"<<\n";
}