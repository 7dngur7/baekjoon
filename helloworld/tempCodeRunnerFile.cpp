
    for(int i=0; i<n; i++){
        cin>>cinarr[i];
    }
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        arr.push_back(make_pair(cinarr[i], a));
    }

    sort(arr.begin(), arr.end(), cmp);

    for(int j=0; j<arr.size(); j++){
        for(int i=0; i<=m; i++){
            ans[j][i]=-1;
        }
    }
    //첫 번째 인덱스
    for(int i=0; i<=m; i++){
        if(i>arr[i].first)break;
        ans[0][i] = arr[i].second;

    }

    for(int j=1; j<arr.size(); j++){
        for(int i=0; i<=m; i++){
            if(i<=arr[j].first){
                if(ans[j-1][i]<0){
                    ans[j][i]=arr[j].second;
                }
                else{
                    ans[j][i]=min(arr[j].second, ans[j-1][i]);
                }
            }
            else{
                if(ans[j-1][i-arr[j].first]<0) break;
                ans[j][i]=min(ans[j-1][i], ans[j-1][i-arr[j].first]+arr[j].second);

            }
            























            // int cnt = 0;
            // while(arr[cnt].second>i){
            //     //인덱스 음수, 처음
            //     if(ans[0][i]==-1 && i-arr[cnt].first<0){
            //         ans[0][i]=arr[cnt].second;
            //     }
            //     //인덱스 양수, 처음
            //     else if(ans[0][i]==-1){
            //         ans[0][i]= i-arr[cnt].first+arr[cnt].second;
            //     }
            //     //인덱스 음수
            //     else if(i-arr[cnt].first<0){
            //         ans[0][i]= min(ans[0][i], arr[cnt].second);
            //     }
            //     //인덱스 양수
            //     else{
            //         //ans[i]= min(ans[i], i-arr[cnt].first+arr[cnt].second);
            //     }

            //     cnt++;
            // }

            // if(ans[0][i]==-1){
            //     ans[0][i]=0;
            // }
        }
    }
    cout<<ans[arr.size()-1][m]<<"\n";
