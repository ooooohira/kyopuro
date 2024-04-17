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
vector<int> parent(MAX_V);
vector<int> in(MAX_V);
vector<int> out(MAX_V);
void dfs(int v, int p, int &k){
    in[v]=k++;
    parent[v]=p;
    for(int i=0;i<G[v].size();i++){
        if(G[v][i]!=p){
            dfs(G[v][i],v,k);
        }
    }
    out[v]=k++;
}

ll op(ll a, ll b){return a+b;}
ll e(){return 0;}
int main(){//ここでは、根からの距離を求めるアルゴリズムを紹介する
    int k=0;
    ll N;
    cin>>N;
    vector<vector<pair<ll, ll> > > G_Weight(N);
    rep(i,N-1){
        ll a,b,c;cin>>a>>b>>c;a--;b--;
        G[a].pb(b);G[b].pb(a);
        G_Weight[a].push_back(make_pair(b,c));
        G_Weight[b].push_back(make_pair(a,c));
    }
    dfs(0,-1,k);
    vector<ll> A(N*2);
    for(int i=0;i<N;i++){
        for(int j=0;j<G_Weight[i].size();j++){
            ll b=G_Weight[i][j].first;
            ll c=G_Weight[i][j].second;
            ll a=i;
            if(parent[a]==b)continue;
            A[in[b]]=c;
            A[out[b]]=-c;
        }
    }
    A[0]=0;
    A[k-1]=0;
    atcoder::segtree<ll, op, e>seg(A);

    ll Q;
    cin>>Q;
    rep(i,Q){
        ll a;
        cin>>a;
        a--;
        cout<<seg.prod(0,in[a]+1);//in[a]+1をout[a]にしてももちろんok(豆知識)
    }

}
// g++ Euler_Tour.cpp -std=c++14 -I .