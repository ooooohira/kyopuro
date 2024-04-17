#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;
using ll =long long;
vector<set<ll> > dp(300009);
int main() {
    // 頂点数，辺数
    ll N, Q;
    cin >> N >> Q;
    ll ans=N;
    

    for(int i=0;i<Q;i++){
        int a, b, c;
        cin>>a;
        if(a==1){
            cin>>b>>c;
            b--;
            c--;
            dp[b].insert(c);
            dp[c].insert(b);
            if(dp[b].size()==1)ans--;
            if(dp[c].size()==1)ans--;
            cout<<ans<<endl;
        }
        else{
            cin>>b;
            b--;
            for (auto v =dp[b].begin() ; v!=dp[b].end(); v++){
                dp[*v].erase(b);
                if(dp[*v].size()==0)ans++;
            }
            if(dp[b].size()!=0)ans++;
            dp[b].clear();
            cout<<ans<<endl;

        }
    }



}