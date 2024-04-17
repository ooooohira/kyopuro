#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
  int n, m;
  cin >> n >> m;
  vector a(n, vector<int>(m));
  rep(i,n)rep(j,m) cin >> a[i][j];

  using BS = bitset<2000>;
  vector<BS> d(n);

  rep(k,m) {
    // map<int,vector<int>> is;
    vector<vector<int> > is(1000, vector<ll>(0));
    vector<bool> boo(1000,false); 
    rep(i,n) {is[a[i][k]].push_back(i);boo[a[i][k]]=true;}
    BS x;
    for (auto p : is) {
      if(p.size()==0)continue;
      for (int i : p) x[i] = 1;
      for (int i : p) d[i] ^= x;
      for (int i : p) x[i] = 0;
    }
  }

  int ans = 0;
  rep(i,n)rep(j,i) ans += d[i][j];
  cout << ans << endl;
  return 0;
}