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


// ll op(ll b, ll a){return max(a,b);}
// ll e(){ll k=inf;return -k;}
// ll mo=998244353;
// ll sx,sy;
// ll ex,ey;
// cin>>sx>>sy>>ex>>ey;
// atcoder::segtree<int, op, e> seg();
// ll inf=10000000000000000;


template <typename T>
struct Edge {
    int to;
    T cost;
};
using Graph = vector<vector<Edge<long long> > >;  // cost の型を long long に指定
/* tree_diamiter : dfs を用いて重み付き木 T の直径を求める
    計算量: O(N)
*/
template <typename T>
pair<T, int> dfs(const Graph &G, int u, int par) {  // 最遠点間距離と最遠点を求める
    pair<T, int> ret = make_pair((T)0, u);
    for (auto e : G[u]) {
        if (e.to == par) continue;
        auto next = dfs<T>(G, e.to, u);
        next.first += e.cost;
        ret = max(ret, next);
    }
    return ret;
}
