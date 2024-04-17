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
// bool hantei(ll x, ll y){
//   if(x<H && x>=0 && y>=0 && y<W)return true;
//   return false;
// }
 
vector<ll> ac;
vector<ll> C;
ll dfs(ll now, ll par, vector<vector<ll> > &G){
  ac[now]=C[now];
  for(auto a:G[now]){
    if(a!=par){
      ac[now]+=dfs(a,now,G);
    }
  }
  return ac[now];
}


ll sco=0;
ll sumc=0;
vector<ll> ans;
void dfs1(ll now, ll par, vector<vector<ll> > &G, ll len){
  sco+=len*C[now];
  for(auto a:G[now]){
    if(a!=par){
      dfs1(a,now,G, len+1);
    }
  }
  return;
}


ll kota=inf;
void dfs2(ll now, ll par, vector<vector<ll> > &G, ll an){
  if(now!=0){
    ans[now]=an+sumc-ac[now]-ac[now];
  }
  else{
    ans[now]=an;
  }
  kota=min(kota,ans[now]);
  for(auto a:G[now]){
    if(a!=par){
      dfs2(a,now,G, ans[now]);
    }
  }
  return;
}



int main() {
    string t;
    ll N,M,K,Q;
    cin>>N;
    vector<vector<ll> > G(N);
    rep(i,N-1){
      ll a,b;cin>>a>>b;
      G[a-1].pb(b-1);
      G[b-1].pb(a-1);
    }
    C.resize(N,0);
    ans.resize(N,0);
    rep(i,N){cin>>C[i];sumc+=C[i];}
    ac.resize(N,0);
    dfs(0,-1,G);dfs1(0,-1,G,0);
    
    dfs2(0,-1,G,sco);
    // for(auto a:ans){
    //   cout<<a<<" ";
    // }
    // cout<<sumc;

    cout<<kota;

}

//g++ aa.cpp -std=c++14 -I .
//modint x.pow(ll n)