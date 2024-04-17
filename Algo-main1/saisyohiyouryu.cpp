//負の閉路あるときはめいいっぱい流して消去してから。
//最初だけベルマンフォードでその後ダイクストラに変えれば高速化可能O(fvv),O(felogv)

//これの計算量はO(fev)

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
struct edge{int to, cap, cost, rev;};

int V;//頂点数
//100=MAX_Vのこと
vector<edge> G[100];
int h[100];//ポテンシャル
int dist[100];//最短距離
int prevv[100], preve[100];//直前の頂点と辺

void add_edge(int from, int to, int cap, int cost){
    G[from].push_back((edge){to, cap, cost, G[to].size()});
    G[to].push_back((edge){from, 0, -1*cost, G[from].size()-1});   
}


//sからtにfの流れ
int min_cost_flow(int s, int t, int f){
    int res=0;
    while(f>0){
        fill(dist, dist+V, INF);
        dist[s]=0;
        bool update=true;
        while(update){
            update=false;
            for(int v=0;v<V;v++){
                if(dist[v]==INF)continue;
                for(int i=0;i<G[v].size();i++){
                    edge &e=G[v][i];
                    if(e.cap>0&&dist[e.to]>dist[v]+e.cost){
                        dist[e.to]=dist[v]+e.cost;
                        prevv[e.to]=v;
                        preve[e.to]=i;
                        update=true;
                    }
                }
            }
        }
        if(dist[t]==INF){
            //条件を満たすフローはない
            return -1;
        }

        int d=f;
        for(int v=t;v!=s;v=prevv[v]){
            d=min(d, G[prevv[v]][preve[v]].cap);
        }

        f-=d;

        res+=d*dist[t];
        for(int v=t;v!=s;v=prevv[v]){
            edge &e=G[prevv[v]][preve[v]];
            e.cap-=d;
            G[v][e.rev].cap+=d;
        }
    }
    return res;
}


int main(){

??????
}



