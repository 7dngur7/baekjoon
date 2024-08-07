#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int testcnt= 1;

    do{
        int cinarr[3];
        int arr[3]={};
        cin>>n;
        if(n==0) break;
        if(n==2){
            for(int j = 0; j<n; j++){
                cin>>cinarr[0]>>cinarr[1]>>cinarr[2];
                if(j==0){
                    arr[0]=cinarr[0];
                    arr[1]=cinarr[1];
                    arr[2]=cinarr[2];
                }
                else if(j==1){

                    int arr0, arr1, arr2;
                    arr[2]= arr[1]+arr[2];
                    
                    int ans = min(arr[1],arr[2])+min(cinarr[1], cinarr[0]+cinarr[1]);
                    cout<<testcnt++<<". "<<ans<<"\n";


                }
            }
        }
        else{
            for(int j = 0; j<n-1; j++){
                cin>>cinarr[0]>>cinarr[1]>>cinarr[2];
                if(j==0){
                    arr[0]=cinarr[0];
                    arr[1]=cinarr[1];
                    arr[2]=cinarr[2];
                }
                else if(j==1){
                    int arr0, arr1, arr2;
                    arr[2]= arr[1]+arr[2];
                    
                    arr0=arr[1]+cinarr[0];
                    arr1=min(arr[1],arr[2])+cinarr[1];
                    arr2=min(arr[1], arr[2])+cinarr[2];
                    arr[0]=arr0;
                    arr[1]=arr1;
                    arr[2]=arr2;

                }
                else{
                    int arr0, arr1, arr2;

                    //arr[1]= min(arr[0]+arr[1], arr[1]);
                    //arr[2]= min(arr[1]+arr[2], arr[2]);


                    arr0= min(arr[0], arr[1])+cinarr[0];
                    //cout<<"0:"<<min(arr[0], arr[1])<<" "<<cinarr[0]<<"\n";
                    arr1=min(min(arr[0], arr[1]), arr[2])+cinarr[1];
                    arr2= min(arr[2], arr[1])+cinarr[2];
                    arr[0]=arr0;
                    arr[1]=arr1;
                    arr[2]=arr2;
                }

                //cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<"\n";
            }
            //cout<<"chk\n";
            //int ans = min(min(arr[0],arr[1]), arr[2]);
            cin>>cinarr[0]>>cinarr[1]>>cinarr[2];

            int beforelast=min(cinarr[0]+cinarr[1], cinarr[1]);

            int ans=min(min(arr[0], arr[1]), arr[2])+beforelast;

            cout<<testcnt++<<". "<<ans<<"\n";
        }
        

    }while(n!=0);
}