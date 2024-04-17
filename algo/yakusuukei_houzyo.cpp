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
#include <bit>
// #include <atcoder/segtree>
// #include "atcoder/modint.hpp"
// #include <atcoder/lazysegtree>
// using mint = atcoder::modint998244353;
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


// ll op(ll b, ll a){return GCD(a,b);}
// ll e(){ll k=0;return k;}
ll mo=998244353;
// ll sx,sy;
// ll ex,ey;
// cin>>sx>>sy>>ex>>ey;
// atcoder::segtree<int, op, e> seg();
ll inf=100000000000000000;//これ以上0増やすと-かけた時バグる。これが限界の大きさ
// sort(V.rbegin(),V.rend());//逆順ソート


//ABC206 Eの問題です。約数包除はO(NlogN)でN以下のgcd(x,y)=gとなるそれぞれの組み合わせの個数を求められる。
int main() {
  ll K, M,Q,N,H,W,L,R;
  ll T;
  cin>>L>>R;
  ll ans=0;
  vector<ll> F(R+1,0);
  for(ll g=R;g>=max(L,2ll);g--){
    ll fg=0;
    fg=(R/g-(L-1)/g)*(R/g-(L-1)/g);
    for(ll i=2*g;i<=R;i+=g){
      fg-=F[i];
    }
    F[g]=fg;
    ans+=fg;
    ll hiku=(R/g)-(L-1)/g;
    hiku*=2;
    hiku-=1;
    ans-=hiku;
  }
  for(ll g=L-1;g>=2;g--){
    ll fg=0;
    fg=(R/g-(L-1)/g)*(R/g-(L-1)/g);
    for(ll i=2*g;i<=R;i+=g){
      fg-=F[i];
    }
    F[g]=fg;
    ans+=fg;
  } 
  cout<<ans;
}

//g++ aa.cpp -std=c++14 -I .
