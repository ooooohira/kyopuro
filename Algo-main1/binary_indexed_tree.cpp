#include <iostream>
using namespace std;
//[1,2,3,   ... n]
int n;
int MAXn=100;//お好きにどうぞ
int bit[100+1];


int sum(int i){
    int s=0;
    while(i>0){
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}

void add(int i, int x){
    while(i <= n){
        bit[i]+=x;
        i+=i&-i;
    }
}





