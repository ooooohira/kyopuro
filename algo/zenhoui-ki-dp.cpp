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
#define emplace_back push_back
#define mk make_pair
 



struct edge
{
  int to, cost;
};

vector< edge > g[100000];
long long dist[100000];


void dfs1(int idx, int par)
{
  for(edge &e : g[idx]) {
    if(e.to == par) continue;
    dfs1(e.to, idx);
    dist[idx] = max(dist[idx], dist[e.to] + e.cost);
  }
}

int dfs2(int idx, int d_par, int par)
{
  vector< pair< int, int > > d_child;
  d_child.emplace_back(mk(0, -1)); // 番兵みたいなアレ
  for(edge &e : g[idx]) {
    if(e.to == par) d_child.emplace_back(mk(d_par + e.cost, e.to));
    else d_child.emplace_back(mk(e.cost + dist[e.to], e.to));
  }
  sort(d_child.rbegin(), d_child.rend());
  int ret = d_child[0].first + d_child[1].first; // 最大から 2 つ
  for(edge &e : g[idx]) {
    if(e.to == par) continue;
    // 基本は d_child() の最大が d_par になるが, e.to の部分木が最大値のときはそれを取り除く必要がある
    ret = max(ret, dfs2(e.to, d_child[d_child[0].second == e.to].first, idx));
  }
  return (ret);
}

int main()
{
  int N;
  cin >> N;
  for(int i = 0; i < N - 1; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    g[a].push_back((edge) {b, w});
    g[b].push_back((edge) {a, w});
  }

  dfs1(N / 2, -1);
  cout << dfs2(N / 2, 0, -1) << endl;
}