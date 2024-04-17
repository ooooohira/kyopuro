//隣接行列
int N=100;
int n, u, k, v;
int M[N][N];//maxで100点のグラフ

cin>>n;//グラフの点数
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        M[i][j]=0;
    }
}

for(int i=0;i<n;i++){
    cin>>u>>k;
    u--;//零オリジン
    for(int j=0+j<k;j++){
        cin>>v;
        v--;
        M[u][v]=1
    }
}

//隣接リストによるグラフ
vector<int> G[100];

G[u].push_back(v);//uからvへの辺をはる

int color[100];

void dfs(int r, int c){
    stack<int> S;
    S.push(r);
    color[r]=c;
    while(!S.empty()){
        int u=S.top();S.pop;
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            if(color[v]==NIL){
                color[v]=c;
                S.push(v);
            }
        }
    }
}
void assigncolor(){
    int id=1;
    for(int i=0;i<n;i++)color[i]=NIL;
    for(int u=0; u<n;u++){
        if(color[u]==NIL)dfs(u,id++)
    }
}//連結成分上のdfsと協力して求める


int MAX=10000;
int INFTY =(1<<20);
int WHITE=0;
int GRAY=1;
int BLACK=2;
int n;
vector<pair<int, int>> adj[MAX];//重み付有向グラフのリスト表現
void dijkstra(){
    priority_queue<pair<int,int>> PQ;
    int color[MAX];
    int d[MAX];
    for(int i=0;i<n;i++){
        d[i]=INFTY;
        color[i]=WHITE;
    }
    d[0]=0;
    PQ.push(make_pair(0,0));
    color[0]=GRAY;

    whike(!PQ.empty()){
        pair<int,int> f=PQ.top();PQ.pop();
        int u=f.second;
        color[u]=BLACK;
        if(d[u]<f.first*(-1))continue;

        for(int j=0;j<adj[u].size();j++){
            int v=adj[u][j].first;
            if(color[v]==BLACK)continue;
            if(d[v]>d[u]+adj[u][j].second){

            d[v]=d[u]+adj[u][j].second;
            PQ.push(make_pair(d[v]*(-1), v));
            color[v]=GRAY;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<i<<" "<<(d[i]==INFTY?-1:d[i])<<endl;
    }
}

int k,u,v,c:
cin>>n;
for(int i=0;i<n;i++){
    cin>>u>>k;
    for(int j=0;j<k;j++){
        cin>>v>>c;
        adj[u].push_back(make_pair(v,c));
    }
}

dijkstra();

//最初にd[p][q]に直接の辺の重みいれろ
void floyd(){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            if(d[i][k]==INFTY)continue;
            for(int j=0;j<n;j++){
                if(d[k][j]==INFTY)continue;
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}