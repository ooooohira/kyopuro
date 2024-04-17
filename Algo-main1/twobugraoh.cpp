#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> G;

// 二部グラフ判定
vector<int> color;
bool dfs(int v, int cur = 0) {
    color[v] = cur;
    for (auto next_v : G[v]) {
        // 隣接頂点がすでに色確定していた場合
        if (color[next_v] != -1) {
            // 同じ色が隣接した場合は二部グラフではない
            if (color[next_v] == cur) return false;

            // 色が確定した場合には探索しない
            continue;
        }

        // 隣接頂点の色を変えて、再帰的に探索
        // false が返ってきたら false を返す
        if (!dfs(next_v , 1 - cur)) return false;
    }
    return true;
}

int main() {
    // 頂点数と辺数
    int N, M;
    cin >> N >> M;

    // グラフ入力受取
    G.resize(N, vector<int>(0));
    color.assign(N, -1);

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 探索
    bool is_bipartite = true;
    for (int v = 0; v < N; ++v) {
        if (color[v] != -1) continue; // v が探索済みの場合は探索しない
        if (!dfs(v)) is_bipartite = false;
    }

    if (is_bipartite) cout << "Yes" << endl;
    else cout << "No" << endl;
}