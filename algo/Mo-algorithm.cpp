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


ll Q,N,sq,width;
vector<ll> B(0);
bool fcomp(const pair<pair<ll,ll>,ll>& a, const pair<pair<ll,ll>,ll>& b) {
    ll aa=(a.first.first/width);
    ll bb=(b.first.first/width);
    if(aa!=bb) return aa < bb;
    else{
        if(a.first.second!=b.first.second)return a.first.second<b.first.second;
        else if(a.first.first!=b.first.first)return a.first.first<b.first.first; 
        else return a.second<b.second;
    }
    return true;
}

void add(ll index, vector<ll> &A, ll &ans){//ここいじってね(追加に対応)
    if(B[A[index]]==1){
        B[A[index]]=0;
        ans++;
    }
    else{
        B[A[index]]=1;
    }
    return;    
}

void delet(ll index, vector<ll> &A, ll &ans){//ここいじってね(消去に対応)
    if(B[A[index]]==1){
        B[A[index]]--;
    }
    else{
        B[A[index]]=1;
        ans--;
    }
    return;
}

void set1(ll &nowl, ll &nowr, vector<ll> &A, ll &ans,  ll nextl, ll nextr){//対象の数列がA,答えがans、kosuはこの問題特有s
    if(nextl>=(N)||nextr>=(N))return;
    while(nowr<nextr){
        nowr++;
        add(nowr,A,ans);
    }
    while(nowl>nextl){
        nowl--;
        add(nowl, A, ans);
    }
    while(nowl<nextl){
        delet(nowl,A,ans);
        nowl++;
    }
    while(nowr>nextr){
        delet(nowr,A,ans);
        nowr--;
    }

    return;
}


int main(){//ここでは、ABC242
    cin>>N;
    vector<ll> A(N,0);//操作対象の配列不変
    rep(i,N){cin>>A[i];A[i]--;}
    cin>>Q;
    vector<pair<pair<ll,ll>,ll> > que;
    rep(i,Q){
        ll left,right;
        cin>>left>>right;
        left--;right--;
        que.push_back(make_pair(make_pair(left,right),i));
    }
    sq=sqrt(Q);
    width=max(N/max(sq,1ll),1ll);//1以上にしないとRE出るぞ

    
    vector<vector<pair<pair<ll,ll>,ll> > > QUERY(N/width+1,vector<pair<pair<ll,ll>,ll> >(0));
    sort(que.begin(),que.end(),fcomp);
    for(auto a:que){
        ll n=a.first.first/width;
        QUERY[n].push_back(a);
    }

    ll le,ri;
    le=0;ri=0;

    ll ans=0;
    B.resize(N,0);
    vector<ll> ann(Q,0);//答え格納
    B[A[0]]++;//初期位置(0,0)での様子を表す

    for(ll i=0;i<N/width+1;i++){
        for(int j=0;j<int(QUERY[i].size());j++){
            ll l=QUERY[i][j].first.first;
            ll r=QUERY[i][j].first.second;
            ll in=QUERY[i][j].second;
            set1(le,ri,A,ans,l,r);
            ann[in]=ans;
        }
        if((width*(i+1))<N){
        set1(le,ri,A,ans,(width*(i+1)),(width*(i+1)));
        }
        else break;
    }

    for(int i=0;i<Q;i++){
        cout<<ann[i]<<endl;
    }
}
