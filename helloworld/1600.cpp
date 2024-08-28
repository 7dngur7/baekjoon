#include<iostream>
#include<queue>

using namespace std;

int arr[202][202]={}, movex[]={0,-1,0,1}, movey[]={-1,0,1,0},movehorsex[]={2,2,-2,-2,1,1,-1,-1}, movehorsey[]={1,-1,1,-1,2,-2,2,-2};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k, w, h;
    cin>>k>>w>>h;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>arr[i][j];
        }
    }









}