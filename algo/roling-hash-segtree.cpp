#include <array>
#include <ctime>
#include <iostream>
#include <random>
#include <string>
using namespace std;
#include "atcoder/segtree.hpp"

constexpr int B = 5;//衝突回避のためいくつか繰り返す、ろりはでは衝突確率は1回の比較で1/modになるから複数用意して回避
int mod[B] = {998244353, 1000000007, 1000000009, 1000000021, 1000000033};
int base[B];
struct Hash {
  long long h1, h2, pw;
};
using T = array<Hash, B>;//Bは配列サイズ

T op(T lhs, T rhs) {
  T res;
  for (int i = 0; i < B; i++) {
    res[i].h1 = (lhs[i].h1 * rhs[i].pw + rhs[i].h1) % mod[i];
    res[i].h2 = (lhs[i].h2 + lhs[i].pw * rhs[i].h2) % mod[i];
    res[i].pw = lhs[i].pw * rhs[i].pw % mod[i];
  }
  return res;
}
T e() {
  T res;
  for (int i = 0; i < B; i++) res[i] = {0, 0, 1};
  return res;
}
using SegTree = atcoder::segtree<T, op, e>;

T gen(char c) {
  T res;
  for (int i = 0; i < B; i++) res[i].h1 = res[i].h2 = c, res[i].pw = base[i];
  return res;
}

int main() {
  mt19937_64 rng(time(0));
  for (int i = 0; i < B; i++) base[i] = rng() % mod[i];

  cin.tie(0)->sync_with_stdio(0);
  int N, Q;
  string S;
  cin >> N >> Q >> S;

  vector<T> init(N);
  for (int i = 0; i < N; i++) init[i] = gen(S[i]);
  SegTree seg{init};

  while (Q--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int x;
      char c;
      cin >> x >> c;
      --x;
      seg.set(x, gen(c));
    } else {
      int l, r;
      cin >> l >> r;
      --l;
      auto h = seg.prod(l, r);
      bool flag = true;
      for (int i = 0; i < B; i++) flag &= h[i].h1 == h[i].h2;
      cout << (flag ? "Yes" : "No") << endl;
    }
  }
}

//g++ roling-hash-segtree.cpp -std=c++14 -I .