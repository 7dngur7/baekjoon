#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

vector< pair<int,int> > v; 
int sudoarr[9][9]={};

bool chksuccess(int first, int second, int putnum){
    //가로 세로 네모 확인


    for(int i=0; i<9;i++){
        if(sudoarr[first][i]==putnum)return false;
    }
    
    for(int i=0; i<9;i++){
        if(sudoarr[i][second]==putnum)return false;
    }

    int sqarerow = (first/ 3) * 3;
    int sqarecol = (second / 3) * 3;
    for(int j = sqarerow; j < sqarerow + 3; j++){
        for(int k = sqarecol; k < sqarecol + 3; k++){
            if(sudoarr[j][k]==putnum) return false;
        }
    }

    return true;
}

void func(int arrnum){
    int firstnum = v[arrnum].first;
    int secondnum = v[arrnum].second;

    //cout<<arrnum<<" "<<v.size()<<"\n";
    if(arrnum == v.size()){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout<<sudoarr[i][j];
            }
            cout<<"\n";
        }        
        exit(0);
    }
    //sleep(1);
    for(int i=1; i<=9; i++){
        if (chksuccess(firstnum, secondnum, i)) {
            sudoarr[firstnum][secondnum] = i;
            func(arrnum + 1);
            sudoarr[firstnum][secondnum] = 0;  
        }

    }    

    //내가 해야하는건 지금 하나를 찍어서 내려(내가 지금까지 사용한게 있으면 x), 완료되면 올려, 만약 하나도 안되면 다시 내려
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<9; i++){
        string a;
        cin>>a;

        for(int j=0; j<9; j++){
            sudoarr[i][j]=a[j]-'0';
            if(sudoarr[i][j]==0){
                v.push_back(make_pair(i,j));
            }
        }
    }
    func(0);
}