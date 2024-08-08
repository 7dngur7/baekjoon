#include <iostream>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<long> v;
    cin>>n;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    long before=2000000001;
    int curfrontans=0, curbackans=n-1;
    int front=0, back=n-1;

    while(1){
        if(front>=back)break;

        long cur = v[front] + v[back];
        
        if(abs(cur)<abs(before)){
            curfrontans=front;
            curbackans=back;
            before = cur;
        }

        if(abs(v[front])>abs(v[back])){
            front++;
        }
        else{
            back--;
        }        
        //cout<<"chk:"<<front<<" "<<back<<"\n";
    }

    //cout<<curfrontans<<" "<<curbackans<<"\n";
    cout<<v[curfrontans]<<" "<<v[curbackans]<<"\n";

}