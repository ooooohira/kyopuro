#include <stdio.h>
#include<iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
bool P(int x){
//    処理書いてね
}

//P(x)=trueとなる最小の整数xを返す,少し改良でvectorとかにも使えるねしそれにnが含まれてるかとかもeasy！
int binary_search(){
    int left, right;//rightは常にtrue、leftは常にfalse

    while(right-left>1){
        int mid=(left+right)/2;
        if(P(mid)) right=mid;
        else left=mid;
    }
    return right;
}






int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    int s=10000;
    for (int i = 0; i < N; ++i) cin >> a[i];
    //for (int i = 0; i < N; ++i) s+=a[i];
    vector<vector<long long>> dp(N+1, vector<long long>(s+1,INT_FAST64_MAX));
    dp[0][0]=1;
    for(int i=1;i<N+1;i++){
        for(int u=0;u<s+1;u++){
            if(dp[i-1][u]>0)dp[i][u]=dp[i-1][u];
            if(a[i-1]<=u&&dp[i-1][u-a[i-1]]>0){
                dp[i][u]=min(dp[i-1][u-a[i-1]], dp[i][u]);
            }
            else dp[i][u]=dp[i-1][u];
        }
    }
    int su=0;
    for(int i=0;i<=s;i++){
        if(dp[N][i]>0)su+=1;
    }
    cout<<su<<endl;
}