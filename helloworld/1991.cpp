#include <iostream>
#include <stack>
#include <unistd.h>

using namespace std;
char arr[30][3]={};

stack<char> s;

void front(char a) {
    int arrcnt = a - 'A';

    cout << a;

    if (arr[arrcnt][1] != '.') {
        front(arr[arrcnt][1]);
    }
    if (arr[arrcnt][2] != '.') {
        front(arr[arrcnt][2]);
    }
}
void middle(char a){

    int arrcnt = a - 'A';
        
    if(arr[arrcnt][1]!='.'){
        middle(arr[arrcnt][1]);
    }
    cout<<a;
    if(arr[arrcnt][2]!='.'){
        middle(arr[arrcnt][2]);
    }
}

void back(char a){
    int arrcnt = a - 'A';
        
    if(arr[arrcnt][1]!='.'){
        back(arr[arrcnt][1]);
    }
    if(arr[arrcnt][2]!='.'){
        back(arr[arrcnt][2]);
    }
    cout<<a;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;;
    for (int i = 0; i < n; i++) {
        char a, b, c;
        cin >> a >> b >> c;

        int idx = a - 'A';
        //cout<<"idx: "<<idx<<"\n";
        arr[idx][0] = a;
        arr[idx][1] = b;
        arr[idx][2] = c;
    }

    // //전위
    // s.push('A');
    // while(!s.empty()){
    //     char cur = s.top();
    //     s.pop();
    //     int arrcnt = cur - 'A';
        

    //     cout<<cur;

    //     if(arr[arrcnt][2]!='.'){
    //         s.push(arr[arrcnt][2]);
    //     }
    //     if(arr[arrcnt][1]!='.'){
    //         s.push(arr[arrcnt][1]);
    //     }

    // }

    //전위
    front('A');


    //중위
    cout<<"\n";
    middle('A');

    //후위
    cout<<"\n";
    back('A');

    cout<<"\n";

}