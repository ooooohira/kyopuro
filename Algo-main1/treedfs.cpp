#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

// 木上の探索
// v: 現在探索中の頂点、p: v の親 (v が根のときは -1)、これ用いて深さ高さ部分木の大きさ
void dfs(const Graph &G, int v, int p) {
    for (auto nv : G[v]) {
        if (nv == p) continue; // nv が親 p だったらダメ
        dfs(G, nv, v); // v は新たに nv の親になります
    }
}

int main() {
    // 頂点数 (木なので辺数は N-1 で確定)
    int N; cin >> N;

    // グラフ入力受取
    Graph G(N);
    for (int i = 0; i < N-1; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 探索
    int root = 0; // 仮に頂点 0 を根とする
    dfs(G, root, -1);
}