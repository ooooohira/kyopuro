#include <iostream>
#include <vector>
using namespace std;
//nloglognの計算量でいけるよ！！

// 1 以上 N 以下の整数が素数かどうかを返す
vector<bool> Eratosthenes(int N) {
    // テーブル
    vector<bool> isprime(N+1, true);

    // 0, 1 は予めふるい落としておく
    isprime[0] = isprime[1] = false;

    // ふるい
    for (int p = 2; p <= N; ++p) {
        // すでに合成数であるものはスキップする
        if (!isprime[p]) continue;

        // p 以外の p の倍数から素数ラベルを剥奪
        for (int q = p * 2; q <= N; q += p) {
            isprime[q] = false;
        }
    }

    // 1 以上 N 以下の整数が素数かどうか
    return isprime;
}

int main() {
    // 50 以下の素数をすべて求める
    vector<bool> isprime = Eratosthenes(50);

    // Python の出力形式に合わせて出力する
    cout << "[";
    for (int v = 0; v <= 50; ++v) {
        if (v) cout << ", ";
        cout << (isprime[v] ? "True" : "False");
    }
    cout << "]" << endl;
}