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
#include <iostream>
#include <atcoder/segtree>
using namespace std;
using ll = long long;


using Graph = vector<vector<int> >;

ll op(ll b, ll a){return min(a,b);}
ll e(){ll k=2e9;return k;}

int main(){
ll N;
cin>>N;

map<ll, vector<pair<ll, ll> > > ma;

vector<ll> vs(N);
for(int i=0;i<N;i++){
    ll a[3];
    for(int j=0;j<3;j++)cin>>a[j];
    sort(a, a+3);
    auto p=make_pair(a[1], a[2]);
    ma[a[0]].push_back(p);
    vs[i]=a[1];
}

sort(vs.begin(), vs.end());
vs.erase(unique(vs.begin(), vs.end()), vs.end());
atcoder::segtree<int, op, e> seg(vs);


for(auto [a, bc] : ma){
    sort(bc.begin(), bc.end(), greater<pair<ll, ll > >());
    for(auto p : bc){
        ll b=lower_bound(vs.begin(), vs.end(), p.first)-vs.begin();
        
        if(b>=1&&seg.prod(0, b) < p.second){
            cout<<"Yes";return 0;
        }
        else{
            seg.set(b, op(p.second, seg.get(b)));
            
        }
    }
}
cout<<"No";


}