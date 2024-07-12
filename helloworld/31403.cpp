#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string A, B, C;

    cin >> A >> B >> C;
    cout << stoi(A) + stoi(B) - stoi(C) << "\n";
    cout << stoi(A + B) - stoi(C);

}