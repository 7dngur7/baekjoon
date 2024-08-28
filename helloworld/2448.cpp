#include <iostream>

using namespace std;

char arr[4000][7000]={};
int n;

void makethree(int line, int num){
    arr[line][num]= '*';
    arr[line+1][num+1]='*';
    arr[line+1][num-1]='*';
    for(int i=num-2; i<num+3;i++){
        arr[line+2][i]='*';
    }


}

void star(int line, int num, int size){

    if(size==3){
        makethree(line, num);
        return;
    }

    star(line, num, size/2);
    star(line + (size/2), num- (size/2), size/2);
    star(line + (size/2), num+ (size/2), size/2);
}



int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;

    star(0, n, n);

    for(int i=0; i<n; i++){
        for(int j=1; j<n*2+1; j++){
            if(arr[i][j]=='*'){
                cout<<arr[i][j];
            }
            else{
                cout<<" ";
            }

        }
        cout<<"\n";
    }
    

}