#include <iostream>

using namespace std;

int arr[100002][3]={}, dx[]={1,1,1,0}, dy[]={-1,0,1,1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        int height;
        cin>>height;
        if(height==0){
            return 0;
        }
        for(int i=0;i<height;i++){
            for(int j=0;j<3;j++){
                cin>>arr[i][j];
            }
        }




    }


}