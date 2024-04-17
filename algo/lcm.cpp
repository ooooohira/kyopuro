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
#include <atcoder/segtree>
#include "atcoder/modint.hpp"
using mint = atcoder::modint998244353;
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



int MAX_V=10000;
vector<vector<int>> G(MAX_V);
int root=0;
vector<int> vs(MAX_V*3);
vector<int> depth(MAX_V*3);
vector<int> id(MAX_V);

void dfs(int v, int p, int d, int &k){
    id[v]=k;
    vs[k]=v;
    depth[k++]=d;
    for(int i=0;i<G[v].size();i++){
        if(G[v][i]!=p){
            dfs(G[v][i],v,d+1,k);
            vs[k]=v;
            depth[k++]=d;
        }
    }
}


pair<ll,ll> op(pair<ll,ll> b, pair<ll,ll> a){if(b.first<a.first)return b; else return a;}
pair<ll,ll> e(){return make_pair(100000000000,-111);}


int main(){
    ll N;
    cin>>N;
    rep(i,N-1){
        ll a,b;
        cin>>a>>b;a--;b--;
        G[a].pb(b);G[b].pb(a);
    }


    int k=0;
    dfs(root, -1, 0, k);
    vector<pair<ll,ll> > P(k);
    rep(i,k){P[i]=make_pair(depth[i],vs[i]);}
    atcoder::segtree<pair<ll,ll>, op, e>seg(P);

    ll Q;
    cin>>Q;
    rep(i,Q){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        if(id[a]>=id[b])swap(a,b);
        cout<<seg.prod(id[a],id[b]+1).second+1<<endl;
    }
}
//g++ lcm.cpp -std=c++14 -I .