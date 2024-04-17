#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<class Abel> struct UnionFind {//計算量普通のunと変わらん
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;

    UnionFind(int n = 1, Abel SUM_UNITY = 0) {
        init(n, SUM_UNITY);
    }

    void init(int n = 1, Abel SUM_UNITY = 0) {//計算量普通のunと変わらん
        par.resize(n); rank.resize(n); diff_weight.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
    }

    int root(int x) {//計算量普通のunと変わらん
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    Abel weight(int x) {//計算量普通のunと変わらん
        root(x);
        return diff_weight[x];
    }

    bool issame(int x, int y) {//計算量普通のunと変わらん
        return root(x) == root(y);
    }

    bool merge(int x, int y, Abel w) {//計算量普通のunと変わらん
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    Abel diff(int x, int y) {//計算量普通のunと変わらん
        return weight(y) - weight(x);
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    UnionFind<int> uf(N);
    for (int i = 0; i < M; ++i) {
        int l, r, d;
        cin >> l >> r >> d;
        --l, --r;
        if (uf.issame(l, r)) {
            int diff = uf.diff(l, r);//r-lの結果を得る
            if (diff != d) {
                cout << "No" << endl;
                return 0;
            }
        }
        else {
            uf.merge(l, r, d);//r-l=dの関係を作成
        }
    }
    cout << "Yes" << endl;
}
