#include <iostream>

using namespace std;

int arr[55][55]={};
int xarr[]={0,0,1,-1};
int yarr[]={1,-1,0,0};
pair<int,int> clean1, clean2;
int cleanflag = 0;
int dustminuscur = 0;
int dustcur = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int r, c, t;
    cin>>r>>c>>t;
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>arr[i][j];   
            if(arr[i][j]<0 && cleanflag == 0){
                clean1 = make_pair(i,j);
                cleanflag ++;
            }
            else if(arr[i][j]<0 ){
                clean2 = make_pair(i,j);
            }
            else if(arr[i][j]>0){
                dustcur+=arr[i][j];
            }
        }
    }

    for(int z=0; z<t; z++ ){
    //확산
        int curDust[55][55]={};
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(arr[i][j]>0){
                    
                    int minusCnt = 0;
                    int minusDust = arr[i][j]/5;
                    
                    for(int k=0; k<4; k++){
                        int curx = i + xarr[k];
                        int cury = j + yarr[k];
                        // cout<<"curcur x,y: "<<curx<<", "<<cury<<", xarr yarr: "<<xarr[k]<<", "<<yarr[k]<<"\n";
                        if(curx<0 || cury<0 || curx>=r || cury>=c) continue;
                        if(arr[curx][cury]<0) continue;
                        minusCnt++;
                        curDust[curx][cury]+=minusDust;
                    }
                    
                    curDust[i][j] += arr[i][j] - (minusCnt * minusDust);
                    // cout<<"cur x,y: "<<i<<" "<<j<<"\n";
                    // cout<<"test minuscnt: "<<minusCnt<<" , minusDust: "<<minusDust<<"\n";        
                    // for(int x=0; x<r; x++){
                    //     for(int y=0; y<c; y++){
                    //         cout<<curDust[x][y]<<" ";            
                    //     }
                    //     cout<<"\n";
                    // }
                    // cout<<"\n";
                }
            }
        }

        // cout<<"\n"<<z<<"test first!\n";
        // for(int x=0; x<r; x++){
        //     for(int y=0; y<c; y++){
        //         cout<<curDust[x][y]<<" ";            
        //     }
        //     cout<<"\n";
        // }

    
        
        //작동
        //clean1 반시계
        int n1, e1, w1, s1;
        //북
        n1 = curDust[0][0];
        for(int i=0; i<c-1; i++){
            curDust[0][i] = curDust[0][i+1];
        }
        //동
        e1 = curDust[0][c-1];
        for(int i=0; i<clean1.first; i++){
            curDust[i][c-1] = curDust[i+1][c-1];
        }
        //남
        s1 =  curDust[clean1.first][c-1];
        for(int i=c-1; i>0; i--){
            curDust[clean1.first][i] = curDust[clean1.first][i-1];
        }
        //서
        w1 = curDust[clean1.first][0];
        for(int i=clean1.first; i>0; i--){
            curDust[i][0] = curDust[i-1][0];
        }
        
        //북
        curDust[1][0] = n1;
        //동
        curDust[0][c-2] = e1;
        //남
        curDust[clean1.first-1][c-1] = s1; 
        //서
        curDust[clean1.first][1] = w1;

        //clean2 시계   
        int n2, e2, w2, s2;
        //북
        n2 = curDust[clean2.first][c-1];
        for(int i=c-1; i>0; i--){
            curDust[clean2.first][i] = curDust[clean2.first][i-1];
        }
                
        //동
        e2 = curDust[r-1][c-1];
        for(int i=r-1; i>clean2.first; i--){
            curDust[i][c-1] = curDust[i-1][c-1];
        }
            
        //남
        s2 =  curDust[r-1][0];
        for(int i=0; i<c-1; i++){
            curDust[r-1][i] = curDust[r-1][i+1];
        }
        
        //서
        w2 = curDust[clean2.first][0];
        for(int i=clean2.first; i<r-1; i++){
            curDust[i][0] = curDust[i+1][0];
        }
        // cout<<"test!\n";
        //     for(int x=0; x<r; x++){
        //         for(int y=0; y<c; y++){
        //             cout<<curDust[x][y]<<" ";            
        //         }
        //         cout<<"\n";
        //     }

        //북
        curDust[clean2.first+1][c-1] = n2;
        //동
        curDust[r-1][c-2] = e2;
        //남
        curDust[r-2][0] = s2; 
        //서
        curDust[clean2.first][1] = w2;


        dustminuscur += curDust[clean1.first][clean1.second];
        dustminuscur += curDust[clean2.first][clean2.second];
        curDust[clean1.first][clean1.second]=-1;
        curDust[clean2.first][clean2.second]=-1;    
        
        // cout<<"test second!\n";
        // for(int x=0; x<r; x++){
        //     for(int y=0; y<c; y++){
        //         cout<<curDust[x][y]<<" ";            
        //     }
        //     cout<<"\n";
        // }
        
        // cout<<"dustcount: "<<dustminuscur<<"\n";
        
        for(int x=0; x<r; x++){
            for(int y=0; y<c; y++){
                arr[x][y] = curDust[x][y];        
            }
        }

    }

    cout<<dustcur-dustminuscur<<"\n";
    return 0;
}