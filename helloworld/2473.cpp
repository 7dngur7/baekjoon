#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long> arr;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long n;
    cin>>n;

    for(long i=0; i<n; i++){
        long a;

        cin>>a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());

    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<"\n";

    long ansnum = 3000000001;
    vector<long> ansarr;

    // int lowest = 0;
    // int highest = arr.size()-1;

    // while(lowest<highest){
    //     long cur=arr[lowest]+arr[highest];

    //     for(int i=lowest+1; i<highest; i++){
    //         if(abs(cur+arr[i])< abs(ansnum)){
    //             ansnum = cur+arr[i];

    //             ansarr.clear();
    //             ansarr.push_back(arr[lowest]);
    //             ansarr.push_back(arr[i]);
    //             ansarr.push_back(arr[highest]);
    //         }
    //     }   

    //     if(cur<0){
    //         lowest++;
    //     }
    //     else{
    //         highest--;
    //     }
        
    // }

    for(long i= 1; i<n-1; i++){
            
        long lowest = 0;
        long highest = arr.size()-1;

        while(lowest<highest){
            long cur=arr[lowest]+arr[highest]+ arr[i];

            if(abs(cur)< abs(ansnum)){
                ansnum = cur;

                ansarr.clear();
                ansarr.push_back(arr[lowest]);
                ansarr.push_back(arr[i]);
                ansarr.push_back(arr[highest]);
            }

            if(cur<0){
                lowest++;
                if(lowest==i){
                    lowest++;
                }
            }
            else{
                highest--;
                if(highest==i){
                    highest--;
                }
            }
            
        }


    }


    sort(ansarr.begin(), ansarr.end());

    cout<<ansarr[0]<<" "<<ansarr[1]<<" "<<ansarr[2]<<"\n";

}