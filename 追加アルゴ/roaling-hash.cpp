#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef unsigned long long ull;

ull B=100000007;//ハッシュの基数
bool contain(string a, string b) {//aはbに含まれているか　o(|b|)
    int al=a.length();
    int bl=b.lebgth();

    if(al>bl){
        return false;
    }


    //Bのal乗を計算
    ull t=1;
    for(int i=0;i<al;i++)t*=B;

    //a,bの最初のal文字までのハッシュ値を計算
    ull ah=0, bh=0;

    for(int i=0;i<al;i++)ah=ah*B+a[i];
    for(int i=0;i<al;i++)bh=bh*B+b[i];

    //bの位置を１つずつ進めながらハッシュ値をチェック
    for(int i=0;i+al<=bl;i++){
        if(ah==bh)return true;
        if(i+al<bl)bh=bh*B+b[i+al]-b[i]*t;
    }
    return false;
}