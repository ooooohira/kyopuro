#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <functional>
#include <stack>
#include <string>
#include <iomanip>
#include <tuple>
#include <numeric>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <bitset>
// #include <bit>
#include <iomanip>
#include <cfloat>
#include <atcoder/segtree>
#include "atcoder/modint.hpp"
#include <atcoder/lazysegtree>
#include <atcoder/math>
#include <cmath>
#include <limits>
using mint = atcoder::modint998244353;
// using mint = atcoder::modint1000000007;
// auto a1=make_pair(1,1);
// auto a2=make_pair(-1,1);
// auto a3=make_pair(-1,-1);
// auto a4=make_pair(1,-1);
// auto a1=make_pair(1,0);
// auto a2=make_pair(-1,0);
// auto a3=make_pair(0,1);
// auto a4=make_pair(0,-1);
// vector<pair<ll, ll> > V(0);
// V.push_back(a1);
// V.push_back(a2);
// V.push_back(a3);
// V.push_back(a4);

using namespace std;
using ll = long long;
using llu = unsigned long long;
using dd = double;
using ddl = long double;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define pb push_back
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }


// ll op(ll b, ll a){return max(a,b);}
// ll e(){ll k=0;return k;}
ll mo=998244353;
// ll sx,sy;
// ll ex,ey;
// cin>>sx>>sy>>ex>>ey;
// atcoder::segtree<int, op, e> seg();
// ll inf=1000000000000000;//これ以上0増やすと-かけた時バグる。これが限界の大きさ,10^17条だよ
ll inf=9223372036854775807;
// sort(V.rbegin(),V.rend());//逆順ソート
// const long double EPS = 1e-10;
// ll N,M,K,H,W,T,Q;
//     ll H,W;
// bool hantei(ll x, ll y){
//   if(x<H && x>=0 && y>=0 && y<W)return true;
//   return false;
// }
 



bool dfs(ll turn, vector<vector<ll> > &A, vector<vector<ll> > &masu){
    bool aite=false;
    for(ll i=0;i<3;i++){
        if(masu[i][0]==masu[i][1] && masu[i][1]==masu[i][2] && masu[i][0]==1-turn)aite=true;
    }
    for(ll i=0;i<3;i++){
        if(masu[0][i]==masu[1][i] && masu[1][i]==masu[2][i] && masu[0][i]==1-turn)aite=true;
    }
    if(masu[0][0]==masu[1][1] && masu[1][1]==masu[2][2] && masu[2][2]==1-turn)aite=true;
    if(masu[0][2]==masu[1][1] && masu[1][1]==masu[2][0] && masu[2][0]==1-turn)aite=true;
    if(aite)return false;
    ll me=0;ll ad=0; 
    bool shu=true;
    rep(i,3)rep(j,3){
        if(masu[i][j]==-1)shu=false;
        else if(masu[i][j]==turn)me+=A[i][j];
        else ad+=A[i][j];
    }
    if(shu){
        if(me<ad)return false;
        else return true;
    }

    bool f=false;
    rep(i,3)rep(j,3){
        if(masu[i][j]==-1){
            masu[i][j]=turn;
            if(!dfs(1-turn, A, masu))
            f=true;
            masu[i][j]=-1;
        }
    }
    return f;
}



int main() {

    ll N,M,K,Q;
    ll X,Y;
    // cin>>N;
    vector<vector<ll> > A(3,vector<ll>(3));
    rep(i,3)rep(j,3)cin>>A[i][j];


    vector<vector<ll> > masu(3, vector<ll>(3,-1));//0 takahashi, 1, aoki
    bool ans=dfs(0,A,masu);

    if(ans){
        cout<<"Takahashi";
    }
    else{
        cout<<"Aoki";
    }


}

//g++ aa.cpp -std=c++14 -I .
//modint x.pow(ll n)
