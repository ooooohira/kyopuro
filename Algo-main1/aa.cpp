#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cassert>
#include <algorithm>
#include <functional>
#include <stack>
#include <string>
using namespace std;
using ll = long long;
#include "atcoder/modint.hpp"
using mint = atcoder::modint998244353;

//o(logn)より高速ほぼ定数ちなみにby rankねこっちはサイズも求められるよただそれだけの違い0
class DisjointSet{
    public:
    vector<int> rank, p, treesize;
    DisjointSet() {}
    DisjointSet(int size){
        rank.resize(size, 0);
        p.resize(size, 0);
        treesize.resize(size, 1);//根のみサイズとしては信用できます
        for(int i=0; i<size; i++) makeSet(i);
    }

    void makeSet(int x){
        p[x]=x;
        rank[x]=0;
        treesize[x]=1;
    }

    bool same(int x, int y){
        return findSet(x)==findSet(y);
    }

    void unite(int x,int y){
        link(findSet(x), findSet(y));
    }

    void link(int x, int y){
        if(x==y)return;

        if(rank[x]>rank[y]){
            p[y]=x;
        }else{
            p[x]=y;
            if(rank[x]==rank[y]){
                rank[y]++;
            }
        }
        int s=treesize[x]+treesize[y];
        treesize[x]=s;
        treesize[y]=s;
    }

    int findSet(int x){
        if(x!=p[x]){
            p[x]=findSet(p[x]);
        }
        return p[x];
    }
};


int main(){
    ll n;
    string s;
    cin>>n;

    DisjointSet D(n);

    vector<mint>  E(n,0);

    for(int i=0;i<n-1;i++){
        ll p,q;
        mint pp, qq;
        cin>>p>>q;
        p--;
        q--;
        pp = D.treesize[D.findSet(p)];
        qq = D.treesize[D.findSet(q)];
        for(int i=0;i<n;i++){
            if(D.same(i, p)){
                E[i]+= pp / (pp+qq);
            }
            else if(D.same(i,q)){
                E[i]+= qq/ (pp+qq);
            }
        }
        D.unite(p,q);
    }

    for(int i=0;i<n;i++){
        cout<<E[i].val()<<" ";
    }
}