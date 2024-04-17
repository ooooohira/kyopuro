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
// #include <atcoder/segtree>
// #include "atcoder/modint.hpp"
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
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define pb push_back
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }


ll inf = 1000000000000;
// ll op(ll b, ll a){return max(a,b);}
// ll e(){ll k=inf;return -k;}
// ll mo=998244353;
// ll sx,sy;
// ll ex,ey;
// cin>>sx>>sy>>ex>>ey;
// atcoder::segtree<int, op, e> seg();


int main(){
  ll N,b;
  b=0;
  cin>>N;
  vector<ll> A(N);
  rep(i,N)cin>>A[i];
  while((1<<b)<N){
    b++;
  }
  vector<vector<ll> > table(b+1, vector<ll>(1<<b, inf));
  rep(i,N)table[0][i]=A[i];
  for(int i=1;i<=b;i++){
    for(int j=0;j+(1<<i)-1<N;j++){
        table[i][j]=min(table[i-1][j],table[i-1][j+(1<<(i-1))]);
    }
  }

  ll Q;
  cin>>Q;
  rep(i,Q){
    ll a,bb;
    cin>>a>>bb;
    a--;
    bb--;//a〜bbでの最小値を求める。
    if(a==bb){cout<<table[0][a]<<endl;continue;}
    ll c=0;
    while((1<<c)<bb-a+1){
        c++;
    }
    c--;
    cout<<min(table[c][a], table[c][bb-((1<<c)-1)]);
  }
}

//g++ aa.cpp -std=c++14 -I .