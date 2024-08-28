#include <iostream>
#include <string>

using namespace std;

int fin_cnt = 0;

int recursion(string s, int l, int r){
    fin_cnt++;
    if(l >= r){ 
        cout<<"1 "<<fin_cnt<<endl;
        return 0;

    }
    else if(s[l] != s[r]) {
        cout<<"0 "<<fin_cnt<<endl; 
        return 0;

    }
    else return recursion(s, l+1, r-1);
}


int main(){
    int cnt ;
    cin>> cnt;
    for(int i = 0 ; i<cnt ; i++){
        string str;
        cin>>str;

        int answer = str.size() - 1;
        recursion(str, 0, str.length()-1);
        fin_cnt = 0;
    }

}