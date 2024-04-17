#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

using Graph = vector<vector<int> >;
vector<bool> seen;


int main(){
    int n;
    cin>>n;//頂点数

    Graph G(n);

    //隣接リスト形式で与えられるとしている(1,2,3,4,で1から頂点開始と考える)
    for(int i=0;i<n;i++){
        int u, k;//uは始点、kはそこから出る辺の数
        cin>>u>>k;
        u--;
        for(int j=0;j<k;j++){
            int a;
            cin>>a;
            a--;
            G[u].push_back(a);
        }
    }
    for(int i=0;i<n;i++){
        seen.push_back(false);
    }

    queue<int> Q;
    seen[0]=true;

    vector<int> dist(n, 0);//bfsで0からの距離を求める

    Q.push(0);//0を始点とする

    while(!Q.empty()){
        int q=Q.front();
        Q.pop();
        for (auto next_v : G[q]){
            if(!seen[next_v]){
                seen[next_v]=true;
                Q.push(next_v);
                dist[next_v]=dist[q]+1;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(i!=0&&dist[i]==0){//たどり着けない時は-1
            cout<<-1<<endl;
        }
        else{
            cout<<dist[i]<<endl;            
        }
    }

}