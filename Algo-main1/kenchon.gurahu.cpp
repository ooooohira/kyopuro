/*辺を受け取るよ、よく使うはず
    int N,M;
    cin >> N;
    cin>>M;
    vector<vector<int>>E(M, vector<int>(2,0));
    int res=0;

    for(int i=0;i<M;i++){
      int x,y;
      cin>>x;
      cin>>y;
      E[i][0]=(x-1);
      E[i][1]=(y-1);

    }
*/
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// ここでは重みを表す型を long long 型とする
struct Edge {
    int to; // 隣接頂点番号
    long long w; // 重み
    Edge(int to, long long w) : to(to), w(w) {}
};

using  Graph=vector<vector<Edge>>;//0~N-1までのとうし番号が頂点についている。

void search(const Graph &G, int s){
    int N=(int)G.size();

    vector<bool>seen(N,false);
    queue<int> todo;//stack<int>で深さ優先探索にするだけ

    seen[s]=true;
    todo.push(s);

    while(!todo.empty()){

        int v=todo.front();
        todo.pop();

        for(int x =0;x<G[v].size();x++){
            if(seen[G[v][x].to])continue;

            seen[G[v][x].to]=true;
            todo.push(x);
        }
    }
}


int main() {
    // 頂点数と辺数
    int N, M;
    cin >> N >> M;

    // グラフ
    Graph G(N);

    for (int i = 0; i < M; ++i) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b, w));
        //無効グラフならね、Graph[b].push_back(Edge(a, w));
    }
}





