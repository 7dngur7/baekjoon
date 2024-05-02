#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> v;
int n, firstnum, lastnum, currentnum;
pair<int, int> answerpair;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    firstnum = 0; lastnum = n-1;
    sort(v.begin(), v.end());

    currentnum = abs(v[firstnum]+v[lastnum]);
    answerpair=make_pair(v[firstnum],v[lastnum]);

    while(firstnum!=lastnum){
        if(abs(v[firstnum]+v[lastnum])>abs(v[firstnum]+v[lastnum-1])){
            /*계속 앞에 수가 올라간다*/

        }
        else if(/*계속 뒤에 숫자가 올라간다*/){



        }
        


    }








    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }

    cout<<v[v.size()-1];

}


// -2 4 -99 -1 98    -99 -5 -1 4 5