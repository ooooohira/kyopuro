#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
int main(){
	int n,m;
	cin >> n >> m;
	scc_graph g(n);
	vector<vector<int>>G(n);
	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		u--,v--;
		g.add_edge(u,v);
		G[u].push_back(v);
	}
	
	vector<vector<int>> scc=g.scc();
	int k=scc.size();
	vector<int> idx(n);
	for(int i=0;i<k;i++)for(auto v:scc[i])idx[v]=i;

	vector<int>dp(k);
	int ans=0;
	for(int i=k-1;i>=0;i--){
		if(scc[i].size()==1){
			for(auto v:G[scc[i][0]])dp[i]|=dp[idx[v]];
		}else{
			dp[i]=1;
		}
		if(dp[i])ans+=scc[i].size();
	}
	
	cout << ans << endl;
}


重要！！！！
// vector<vector<int>> graph.scc()
// 以下の条件を満たすような、「頂点のリスト」のリストを返します。

// 全ての頂点がちょうど1つずつ、どれかのリストに含まれます。
// 内側のリストと強連結成分が一対一に対応します。リスト内での頂点の順序は未定義です。
// リストはトポロジカルソートされています。異なる強連結成分の頂点 
// 異なる強連結成分の頂点u, vについてuからvに到達できる時、uの属するリストはv の属するリストよりも前です。

