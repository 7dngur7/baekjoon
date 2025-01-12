#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int g1, s1, b1;
    int g2, s2, b2;

    cin>>g1>>s1>>b1>>g2>>s2>>b2;

    int a, b, c;
    a = g1 - g2;
    b = s1 - s2;
    c = b1 - b2;

    int ans = 0;

// 금을 일단 끌어와
    while(g1<g2){
        if(s1>=11){
            // cout<<"test1: 1\n";
            g1++;
            s1-=11;
            ans++;
        }
        else if(b1>=11){
            // cout<<"test1: 2\n";
            s1++;
            b1-=11;
            ans++;
        }
        else{
            // cout<<"test1: 3\n";
            cout<<"-1\n";
            return 0;
        }
    }

// 은으로 와서 금을 끌어오고 동을 끌어와
    while(s1<s2){
        if(g1>g2){
            // cout<<"test2: 1\n";
            g1--;
            s1+=9;
            ans++;
        }
        else if(b1>=11){
            // cout<<"test2: 2\n";
            s1++;
            b1-=11;
            ans++;
        }
        else{
            // cout<<"test2: 3\n";
            cout<<"-1\n";
            return 0;
        }
    }
// 동 보고 체크
    while(b1<b2){
        if(s1>s2){
            // cout<<"test3: 1\n";
            s1--;
            b1+=9;
            ans++;
        }
        else if(g1>g2){
            // cout<<"test3: 2\n";
            g1--;
            s1+=9;
            ans++;
        }
        else{
            // cout<<"test3: 3\n";
            cout<<"-1\n";
            return 0;
        }
    }
    if(b1>=b2){
        cout<<ans<<"\n";
    }
    else{
        cout<<"-1\n";
    }

}