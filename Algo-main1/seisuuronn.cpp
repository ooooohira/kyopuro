#include<algorithm>
#include<cstdio>
#include<math.h>
#include<vector>
#include<set>
using namespace std;

//高速素数判定,範囲内ならえらとすで検索
int isPrime(int x){//1は素数,0は素数でない
    int i;
    if(x<2)return 0;
    else if(x==2)return 1;
    if(x%2==0)return 0;
    for(i=3;i*i<=x;i+=2){
        if(x%i==0)return 0;
    }
    return 1;
}

#include<cmath>
//最大公約数
int gcd(int x, int y){
    return y ? gcd(y, x%y) : x;
}

//べき乗繰り返し自乗法o(logn)xのn乗をMで割ったあまり
typedef unsigned long long ullong;
ullong power(ullong x, ullong n, ullong M){
    ullong res=1;
    if(n>0){
        res=power(x, n/2, M);
        if(n%2==0)res=(res*res)%M;
        else res=(((res*res)%M)*x)%M;
    }
    return res;
}