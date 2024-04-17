#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 1<<17;
const int INTMAX_N = 1<<17;
//セグ木を持つグローバル配列
int n, dat[2*INTMAX_N - 1];

//初期化
void init(int n_){
    //簡単のため要素数を2のべき乗に
    n=1;
    while(n < n_)n*=2;

    //全ての値をMAX_Nに
    for (int i=0;i<2*n-1;i++)dat[i]=MAX_N;
}

//k番目の値をaに変更
void update(int k, int a){
    //葉の節点
    k += n-1;
    dat[k] = a;

    while(k>0){
        k=(k-1)/2;
        dat[k] = min(dat[k*2+1], dat[k*2+2]);
    }
}

//[a, b)の最小値を求める
//kは節点の番号(index)でその範囲が[l, r)
//したがって、外からはquery(a, b, 0, 0, n)として呼ぶ

int query(int a, int b, int k, int l, int r){
    //[a, b)と[l, r)が交差しない場合はMAX_Nを返す
    if(r<=a||b<=l) return MAX_N;

    //[a, b)が[l, r)を完全に含んでいれば、この節点の値
    if(a<=l&&r<=b) return dat[k];

    else{
        int vl = query(a, b, 2*k+1, l, (l+r)/2);
        int vr = query(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);    
    }
}
