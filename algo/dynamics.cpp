#include<iostream>
#include<vector>
using namespace std;
//緩和
template<class T>void chmax(T& a, T b){
    if(a<b){
        a=b;
    }
}
template<class T>void chmin(T& a, T b){
    if(a>b){
        a=b;
    }
}
int N,W;
//DP table N+1行W+1列テーブル0で初期化してるよ～
vector<vector<long long>> dp(N+1, vector<long long>(W+1,0));
//DP table 1列ばんだよ
vector<long long>dp;

