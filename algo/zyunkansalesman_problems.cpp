#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

using ll = long long;



ll mma=1000000000;
int main() {
    
    int N;
    cin>>N;//頂点数
    vector<vector<ll> > A(20, vector<ll>(3, 0));//座標的なもの、各自の問題で工夫してね

    for(int i=0;i<N;i++){
        cin>>A[i][0]>>A[i][1]>>A[i][2];
    }


    vector<vector<ll> > dp(1048579, vector<ll>(20, mma));//dp[s][i]sには到達づみで、今iにいる
        dp[0][0]=0;//初期位置には到達済みの頂点なしで、0にはいるとする。


    for(int i=1;i<(1<<N);i++){
        for(int j=0;j<N;j++){
            int s=((~(1<<j)) & i);
            for(int p=0;p<N;p++){
                dp[i][j]=min(dp[i][j], dp[s][p] + abs(A[p][0]-A[j][0]) + abs(A[p][1]-A[j][1]) + max(0ll, A[p][2]-A[j][2])); //minの第2項について、j->pの距離に直せばACできるよ
            }
        }
    }
    cout<<dp[(1<<N)-1][0];
}