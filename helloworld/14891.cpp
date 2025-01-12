#include <iostream>
#include <vector>

using namespace std;

int num1 = 0, num2 = 0, num3 = 0, num4 = 0;
int arr[4][8] = {};

vector<pair<int,int>> v;

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

for(int i=0; i<4; i++){
    string a;
    cin>>a;
    for(int j=0; j<8; j++){
        arr[i][j] = a[j]-48;
    }
    
}

int b;
cin >> b;

for(int i=0; i<b; i++){
    int c, d;
    cin>>c>>d;
    v.push_back(make_pair(c,d));
}

for(int i=0; i<b; i++){
    int first = v[i].first;
    int second = v[i].second;
    
    int check1 = 0, check2 = 0, check3 = 0;
    if(arr[0][(num1+2)%8] != arr[1][(num2+6)%8])check1 = 1;
    if(arr[1][(num2+2)%8] != arr[2][(num3+6)%8])check2 = 1;
    if(arr[2][(num3+2)%8] != arr[3][(num4+6)%8])check3 = 1;
    
    // cout<<"first second: "<<first<<" "<<second<<"\n";
    // cout<<"cur check: "<<check1<<" "<<check2<<" "<<check3<<"\n";
    
    if(first == 1){
        if(second<0){
            if(check1 && check2 && check3 ){
                num1+=1;
                num2+=7;
                num3+=1;
                num4+=7;
            }
            else if (check1 && check2){
                num1+=1;
                num2+=7;
                num3+=1;
                
            }
            else if(check1){
                num1+=1;
                num2+=7;

            }
            else{
                num1+=1;
            }  
        }
        else{
            if(check1 && check2 && check3 ){
                num1+=7;
                num2+=1;
                num3+=7;
                num4+=1;
            }
            else if (check1 && check2){
                num1+=7;
                num2+=1;
                num3+=7;
                
            }
            else if(check1){
                num1+=7;
                num2+=1;

            }
            else{
                num1+=7;
            }
        }
    }
    else if(first == 2){
        if(second<0){
            if(check1&&check2 && check3){
                num1+=7;
                num2+=1;
                num3+=7;
                num4+=1;
            }
            else if(check1&&check2){
                num1+=7;
                num2+=1;
                num3+=7;
            }
            else if(check1){
                num1+=7;
                num2+=1;
            }
            else if (check2 && check3){
                num2+=1;
                num3+=7;
                num4+=1;
                
            }
            else if(check2){
                num2+=1;
                num3+=7;

            }
            else{
                num2+=1;
            }  
        }
        else{
            if(check1&&check2 && check3){
                num1+=1;
                num2+=7;
                num3+=1;
                num4+=7;
            }
            else if(check1&&check2){
                num1+=1;
                num2+=7;
                num3+=1;
            }
            else if(check1){
                num1+=1;
                num2+=7;
            }
            else if (check2 && check3){
                num2+=7;
                num3+=1;
                num4+=7;
                
            }
            else if(check2){
                num2+=7;
                num3+=1;

            }
            else{
                num2+=7;
            } 
        }
    }
    else if(first == 3){
        if(second<0){
            if(check1&&check2 && check3){
                num1+=1;
                num2+=7;
                num3+=1;
                num4+=7;
            }
            else if(check2&&check3){
                num2+=7;
                num3+=1;
                num4+=7;
            }
            else if(check3){
                num3+=1;
                num4+=7;
            }
            else if (check2 && check1){
                num1+=1;
                num2+=7;
                num3+=1;
                
            }
            else if(check2){
                num3+=1;
                num2+=7;

            }
            else{
                num3+=1;
            }  
        }
        else{
            if(check1&&check2 && check3){
                num1+=7;
                num2+=1;
                num3+=7;
                num4+=1;
            }
            else if(check2&&check3){
                num2+=1;
                num3+=7;
                num4+=1;
            }
            else if(check3){
                num3+=7;
                num4+=1;
            }
            else if (check2 && check1){
                num1+=7;
                num2+=1;
                num3+=7;
                
            }
            else if(check2){
                num3+=7;
                num2+=1;

            }
            else{
                num3+=7;
            }  
        }
    }
    else{
        if(second<0){
            if(check3 && check2 && check1 ){
                num4+=1;
                num3+=7;
                num2+=1;
                num1+=7;
            }
            else if (check3 && check2){
                num4+=1;
                num3+=7;
                num2+=1;
                
            }
            else if(check3){
                num4+=1;
                num3+=7;

            }
            else{
                num4+=1;
            } 
        }
        else{
            if(check3 && check2 && check1 ){
                num4+=7;
                num3+=1;
                num2+=7;
                num1+=1;
            }
            else if (check3 && check2){
                num4+=7;
                num3+=1;
                num2+=7;
                
            }
            else if(check3){
                num4+=7;
                num3+=1;

            }
            else{
                num4+=7;
            } 
        }
    }
    
    //  cout<<"check: "<<num1<<" "<<num2<<" "<<num3<<" "<<num4<<"\n";
    
    
}


int ans = 0;
if(arr[0][num1%8]==1) ans +=1;
if(arr[1][num2%8]==1) ans +=2;
if(arr[2][num3%8]==1) ans +=4;
if(arr[3][num4%8]==1) ans +=8;

cout<<ans<<"\n";
return 0;
}