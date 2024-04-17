#include <iostream>
using namespace std;
using ll = long long;
// a^n mod を計算する
 ll modpow(ll x, ll p, ll m) {
     ll ret = 1;
     x %= m;
     while (p > 0) {
         if (p & 1) ret *= x;
         ret %= m;
         x *= x;
         x %= m;
         p >>= 1;
     }
     return ret;
 }

// a^{-1} mod を計算する逆元です、modが素数でaがmodの倍数でないとき。
long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}

int main() {
    // mod. 13 での逆元を求めてみる
    for (int i = 1; i < 13; ++i) {
        cout << i << " 's inv: " << modinv(i, 13) << endl;
    }
}