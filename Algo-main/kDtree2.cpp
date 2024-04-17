#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

class Node {
    public:
    int location;
    int p, l, r;
    Node() {}
};

class Point {
    public:
    int id, x, y;
    Point() {}
    Point(int id, int x, int y): id(id), x(x), y(y) {}
    bool operator < (const Point &p) const {
        return id < p.id;
    }//昇順に出力するために必要

    void print(){
        printf("%d\n", id);
    }
};

static const int MAX = 1000000;//入力の点の数の最大値
static const int NIL = -1;

int N;
Point P[MAX];//入力受け取る、ソートだけする

Node T[MAX];//ソートしたPをもとにつくる配列、これがKDTreeになる

int np;

bool lessX(const Point &p1, const Point &p2){return p1.x < p2.x;}
bool lessY(const Point &p1, const Point &p2){return p1.y < p2.y;}


//t=0,T[0]が木の根になる
int makeKDTree(int l, int r, int depth){
    if(!(l<r)) return NIL;
    int mid=(l+r)/2;
    int t=np++;
    if(depth%2==0){
        sort(P+l, P+r, lessX);
    }else{
        sort(P+l, P+r, lessY);
    }
    T[t].location=mid;//これはPでT[t]が対応する位置
    T[t].l=makeKDTree(l,mid,depth+1);//T[t]の右の子のTでの位置
    T[t].r=makeKDTree(mid+1,r,depth+1);//同様に

    return t;

}

//o(n^(1-1/2)+k)の計算量(１つの範囲の探索あたり)
void find(int v, int sx, int tx, int sy, int ty, int depth, vector<Point> &ans){
    int x=P[T[v].location].x;
    int y=P[T[v].location].y;

    if(sx<=x && x<=tx && sy<=y && y<=ty){
        ans.push_back(P[T[v].location]);
    }

    if(depth%2==0){
        if(T[v].l != NIL){
            if(sx<=x) find(T[v].l, sx, tx, sy, ty, depth+1, ans);
        }
        if(T[v].r != NIL){
            if(x<=tx) find(T[v].l, sx, tx, sy, ty, depth+1, ans);
        }
    }else{
        if(T[v].l != NIL){
            if(sy<=y) find(T[v].l, sx, tx, sy, ty, depth+1, ans);
        }
        if(T[v].r != NIL){
            if(x<=ty) find(T[v].l, sx, tx, sy, ty, depth+1, ans);
        }

    }
}

int main(){
    int x,y;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d %d", &x, &y);
        P[i]=Point(i, x, y);
        T[i].l=T[i].r=T[i].p=NIL;
    }

    np=0;

    int root=makeKDTree(0, N, 0);//もちろんrootは0になるよ

    int q;
    scanf("%d", &q);
    int sx, tx, sy, ty;
    vector<Point> ans;
    for(int i=0;i<q;i++){
        scanf("%d %d %d %d", &sx, &tx, &sy, &ty);
        ans.clear();
        find(root, sx, tx, sy, ty, 0, ans);
        sort(ans.begin(), ans.end());
        for(int j=0;j<ans.size();j++){
            ans[j].print();
        }
        printf("\n");
    }

    return 0;
}

//o(nq)をo(n(logn)(logn) + q*(n^(1-1/d) + k))に抑えられた