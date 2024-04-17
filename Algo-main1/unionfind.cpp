#include<iostream>
#include<vector>
using namespace std;

//o(logn)より高速ほぼ定数こっちはby sizeね
class DisjointSetbysize{
    public:
    vector<int> rank, p, treesize;//rank書いてあるけどby sizeだから使わない！！消してもいいよ

    DisjointSetbysize() {}
    DisjointSetbysize(int size){
        rank.resize(size, 0);
        p.resize(size, 0);
        for(int i=0; i<size; i++) makeSet(i);
    }

    void makeSet(int x){
        p[x]=x;
        rank[x]=0;
        treesize[x]=1;
    }

    bool same(int x, int y){
        return findSet(x)==findSet(y);
    }

    void unite(int x,int y){
        link(findSet(x), findSet(y));
    }

    void link(int x, int y){
        if(x==y)return;
        if(treesize[x]>treesize[y]){
            p[y]=x;
        }else{
            p[x]=y;
            if(rank[x]==rank[y]){
                rank[y]++;
            }
        }
        treesize[x]=treesize[x]+treesize[y];
        treesize[y]=treesize[x];
    }

    int findSet(int x){
        if(x!=p[x]){
            p[x]=findSet(p[x]);
        }
        return p[x];
    }

};

//o(logn)より高速ほぼ定数ちなみにby rankねこっちはサイズも求められるよただそれだけの違い0
class DisjointSet{
    public:
    vector<int> rank, p, treesize;
    DisjointSet() {}
    DisjointSet(int size){
        rank.resize(size, 0);
        p.resize(size, 0);
        treesize.resize(size, 1);//根のみサイズとしては信用できます
        for(int i=0; i<size; i++) makeSet(i);
    }

    void makeSet(int x){
        p[x]=x;
        rank[x]=0;
        treesize[x]=1;
    }

    bool same(int x, int y){
        return findSet(x)==findSet(y);
    }

    void unite(int x,int y){
        link(findSet(x), findSet(y));
    }

    void link(int x, int y){
        if(x==y)return;

        if(rank[x]>rank[y]){
            p[y]=x;
        }else{
            p[x]=y;
            if(rank[x]==rank[y]){
                rank[y]++;
            }
        }
        int s=treesize[x]+treesize[y];
        treesize[x]=s;
        treesize[y]=s;
    }

    int findSet(int x){
        if(x!=p[x]){
            p[x]=findSet(p[x]);
        }
        return p[x];
    }
};