#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

// 無限大を表す値 (ここでは 2^60 とする)
const long long INF = 1LL << 60;

// 辺を表す型，ここでは重みを表す型を long long 型とします
struct Edge {
    int to; // 隣接頂点番号
    long long w; // 重み
    Edge(int to, long long w) : to(to), w(w) {}
};

// 重み付きグラフを表す型
using Graph = vector<vector<Edge>>;

// 緩和を実施する関数
template<class T> bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    // 頂点数，辺数，始点
    int N, M, s;
    cin >> N >> M >> s;

    // グラフ
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b, w));
    }

    //0-1bfs(ダイクストラ法の0-1ばん)
    vector<long long> dist(N, INF);
    dist[s] = 0;

    // (d[v], v) のペアを要素としたヒープを作る
    deque<pair<long long, int> > que;
    que.push_front(make_pair(dist[s], s));

    // ダイクストラ法の反復を開始
    while (!que.empty()) {
        // v: 使用済みでない頂点のうち d[v] が最小の頂点
        // d: v に対するキー値
        int v = que.front().second;
        long long d = que.front().first;
        que.pop_front();

        // d > dist[v] は，(d, v) がゴミであることを意味する
        if (d > dist[v]) continue;
        
        // 頂点 v を始点とした各辺を緩和
        for (auto e : G[v]) {
            if (chmin(dist[e.to], dist[v] + e.w)) {
                // 更新があるならヒープに新たに挿入
                if(e.w==1)
                que.push_back(make_pair(dist[e.to], e.to)); 
                else
                que.push_front(make_pair(dist[e.to], e.to));
            }
        }
    }
    
    // 結果出力
    for (int v = 0; v < N; ++v) {
        if (dist[v] < INF) cout << dist[v] << endl;
        else cout << "INF" << endl;
    }
}