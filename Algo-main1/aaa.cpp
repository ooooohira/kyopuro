#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int> >;

// 深さ優先探索、これ用いてたかさ、ふかさ、各頂点での部分木のサイズも止められるね
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済ならば探索しない
        dfs(G, next_v); // 再帰的に探索
    }
    if(v!=0)
    cout<<v+1<<" ";
}



int main() {
    // 頂点数と辺数
    int N, M;
    cin >> N;

    // グラフ入力受取 (ここでは有向グラフを想定)
    Graph G(N);
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a ;
        for(int j=0;j<a;j++){
            cin>>b;
            b--;
            G[i].push_back(b);    
        }
    }

    // 探索
    seen.assign(N, false); // 初期状態では全頂点が未訪問
    dfs(G,0);

}

