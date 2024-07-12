#include <iostream>
#include <queue>

using namespace std;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m;
    cin>>m;
    
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        if(c%a==0){
            cout<<a;

            if(c/a>=10){
                cout<<c/a<<"\n";

            }
            else{
                cout<<"0"<<c/a<<"\n";

            }
        }
        else{
            cout<<c%a;
            if(c/a+1>=10){
                cout<<c/a+1<<"\n";

            }
            else{
                cout<<"0"<<c/a+1<<"\n";

            }
        }

    }
}